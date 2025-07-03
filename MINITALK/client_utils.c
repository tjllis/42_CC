/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:04:35 by tsemenov          #+#    #+#             */
/*   Updated: 2025/06/23 15:04:36 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	is_valid_pid(pid_t pid)
{
	if (pid < 1)
	{
		ft_putstr_fd("❌ invalid PID\n", 2);
		return (0);
	}
	if (kill(pid, 0) == -1)
	{
		ft_putstr_fd("❌ PID does not exist\n", 2);
		return (0);
	}
	return (1);
}

// size_t	count_msg_bits(char *msg)
// {
// 	int len;

// 	len = ft_strlen(msg);
// 	if (len < 0)
// 		return (0);
// 	return (((size_t)len + 1) * 8);
// }
