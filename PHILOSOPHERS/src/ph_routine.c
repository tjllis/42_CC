/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:38:48 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/26 22:25:28 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_think(t_philo *philo);
static void	ft_sleep(t_philo *philo);

void	*ph_routine(void *arg)
{
	t_philo	*philo;
	int		sim_ended;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2);
	sim_ended = get_sim_ended(philo->data);
	while (!sim_ended)
	{
		if (ft_eat(philo) == SUCCESS)
			ft_sleep(philo);
		else
			ft_think(philo);
		sim_ended = get_sim_ended(philo->data);
	}
	return (NULL);
}

static void	ft_think(t_philo *philo)
{
	uint64_t	think_time;

	print_status(philo, THINK);
	think_time = 1000 + (philo->data->num_philos * 500);
	ft_usleep(think_time);
}

static void	ft_sleep(t_philo *philo)
{
	print_status(philo, SLEEP);
	ft_usleep(philo->data->time_to_sleep);
}
