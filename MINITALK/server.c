/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:05:01 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 15:05:02 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// The sigaction structure is defined as something like:

//	struct sigaction {
//	void		(*sa_handler)(int);
//	void		(*sa_sigaction)(int, siginfo_t *, void *);
//	sigset_t	sa_mask;
//	int			sa_flags;
//	void		(*sa_restorer)(void);
//};

// We do:
// Для SIGUSR1 система запоминает:
// {
//     .sa_handler = NULL,                    // Не используется
//     .sa_sigaction = handle_signal,         // ← ЭТОТ обработчик
//     .sa_mask = {SIGUSR1, SIGUSR2},        // ← ЭТИ сигналы блокировать
//     .sa_flags = SA_SIGINFO | SA_RESTART,   // ← ЭТИ флаги поведения
//     .sa_restorer = NULL                    // Не используется
// }

// Упрощенное представление структуры siginfo_t (определена в системе)
// typedef struct {
//     int      si_signo;   // Номер сигнала
//     int      si_errno;   // Код ошибки  
//     int      si_code;    // Дополнительная информация
//     pid_t    si_pid;     // ← PID процесса-отправителя
//     uid_t    si_uid;     // UID пользователя-отправителя
//     // ... другие поля
// } siginfo_t;

// typedef struct	s_msg
// {
// 	char	buffer[MSG_SIZE];
// 	size_t	len;
// 	int		curr_char;
// }	t_msg;

static t_msg	g_msg = {{0}, 0, 0};

void	clean_buffer(void)
{
	g_msg.len = 0;
	g_msg.curr_char = 0;
}

void	add_char(char c)
{
	if (c == '\0')
	{
		g_msg.buffer[g_msg.len] = '\0';
		ft_printf("✅ Received message: %s\n", g_msg.buffer);
		clean_buffer();
		return ;
	}
	if (g_msg.len >= MSG_SIZE - 1)
	{
		ft_putendl_fd("❌ Message too long", 2);
		clean_buffer();
		return ;
	}
	g_msg.buffer[g_msg.len++] = c;
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bits;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bits));
	bits++;
	if (bits == 8)
	{
		add_char(c);
		c = 0;
		bits = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		ft_putendl_fd("❌ Failed to send acknowledgment", 2);
		return ;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
		sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putendl_fd("❌ Failed to set up signal handlers", 2);
		return (1);
	}
	ft_printf("✅ Server PID: %d\n", getpid());
	ft_printf("📡 Waiting for messages...\n");
	while (1)
		pause();
	return (0);
}
