/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:04:54 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 15:04:55 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/includes/libft.h"

// # define BUFFER_SIZE 1024
# define MSG_SIZE 4096
# ifndef SIGUSR1
#  define SIGUSR1 1
# endif
# ifndef SIGUSR2
#  define SIGUSR2 2
# endif

typedef struct s_msg
{
	char	buffer[MSG_SIZE];
	size_t	len;
	int		curr_char;
}	t_msg;

int		is_valid_pid(pid_t pid);
// size_t	count_msg_bits(char *msg);

#endif
