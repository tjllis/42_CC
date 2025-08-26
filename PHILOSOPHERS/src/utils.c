/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:39:39 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/25 23:55:14 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time_ms(void)
{
	struct timeval	tv;
	uint64_t		start_time;

	if (gettimeofday(&tv, NULL))
		return (0);
	start_time = (uint64_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
	return (start_time);
}

void	ft_putendl_fd(const char *s, int fd)
{
	int	i;

	if (s == NULL)
	{
		write(1, "error", 5);
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

void	print_status(t_philo *philo, char *msg)
{
	uint64_t	timestamp;

	pthread_mutex_lock(&philo->data->print_lock);
	if (!get_sim_ended(philo->data))
	{
		timestamp = get_time_ms() - philo->data->start_time;
		printf("%llu ms %d %s\n", timestamp, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	print_death(t_philo *philo, char *msg, uint64_t death_time)
{
	uint64_t	timestamp;

	pthread_mutex_lock(&philo->data->print_lock);
	if (!get_sim_ended(philo->data))
	{
		timestamp = death_time - philo->data->start_time;
		printf("%llu ms %d %s\n", timestamp, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	ft_usleep(uint64_t sleep_time)
{
	uint64_t	start;

	start = get_time_ms();
	while ((get_time_ms() - start) < sleep_time)
		usleep(500);
}
