/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:04:25 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 15:04:27 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_ack_received = 0;

void	acknoledge_signal(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
}

int	send_bit(pid_t server, int bit)
{
	int			retries;
	int			wait_time;

	retries = 0;
	while (retries < 3)
	{
		g_ack_received = 0;
		if (bit == 1 && (kill(server, SIGUSR1)) == -1)
			return (0);
		if (bit == 0 && (kill(server, SIGUSR2)) == -1)
			return (0);
		wait_time = 0;
		while (!g_ack_received && wait_time < 100000)
		{
			usleep(1000);
			wait_time += 1000;
		}
		if (g_ack_received)
			return (1);
		retries++;
	}
	ft_putendl_fd("❌ No acknowledgment from server", 2);
	return (0);
}

int	send_char(pid_t server, unsigned char c)
{
	int	bit;
	int	bit_value;

	bit = 7;
	while (bit >= 0)
	{
		bit_value = (c >> bit) & 1;
		if (!send_bit(server, bit_value))
		{
			ft_putendl_fd("❌ Failed to send character", 2);
			return (0);
		}
		bit--;
	}
	return (1);
}

int	send_msg(pid_t server, const char *msg)
{
	int		len;
	int		i;

	len = ft_strlen(msg);
	i = 0;
	while (i < len)
	{
		if (!send_char(server, (unsigned char)msg[i]))
		{
			ft_putendl_fd("❌ Failed to send message", 2);
			return (0);
		}
		i++;
	}
	if (!send_char(server, '\0'))
	{
		ft_putendl_fd("❌ Failed to send terminator", 2);
		return (0);
	}
	ft_printf("✅ Message sent successfully\n");
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc != 3)
	{
		ft_putendl_fd("❌ Missing argument", 2);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (!is_valid_pid(pid))
		return (1);
	msg = argv[2];
	if (!msg || ft_strlen(msg) == 0)
	{
		ft_putendl_fd("❌ Message cannot be empty", 2);
		return (1);
	}
	if (signal(SIGUSR1, acknoledge_signal) == SIG_ERR)
	{
		ft_putendl_fd("❌ Failed to set signal handler", 2);
		return (1);
	}
	if (!send_msg(pid, msg))
		return (1);
	return (0);
}
