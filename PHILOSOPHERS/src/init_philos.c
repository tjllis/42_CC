/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:25:23 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/25 23:50:20 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_locks(t_philo *philo);
static void	assign_forks(t_data *data, int i);

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (data->philos == NULL)
		return (FAIL);
	i = 0;
	while (i < data->num_philos)
	{
		if (init_locks(&data->philos[i]) == FAIL)
		{
			while (--i >= 0)
				destroy_ph_locks(&data->philos[i]);
			return (FAIL);
		}
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = data->start_time;
		// data->philos[i].state = THINKING;
		data->philos[i].thread = 0;
		data->philos[i].data = data;
		assign_forks(data, i);
		i++;
	}
	return (SUCCESS);
}

static int	init_locks(t_philo *philo)
{
	if (pthread_mutex_init(&philo->meals_eaten_lock, NULL) != 0)
		return (FAIL);
	if (pthread_mutex_init(&philo->last_meal_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->meals_eaten_lock);
		return (FAIL);
	}
	// if (pthread_mutex_init(&philo->state_lock, NULL) != 0)
	// {
	// 	pthread_mutex_destroy(&philo->meals_eaten_lock);
	// 	pthread_mutex_destroy(&philo->last_meal_lock);
	// 	return (FAIL);
	// }
	return (SUCCESS);
}

static void	assign_forks(t_data *data, int i)
{
	if (i == (data->num_philos - 1))
	{
		data->philos[i].left_fork = &data->forks[0];
		data->philos[i].right_fork = &data->forks[i];
	}
	else
	{
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[i + 1];
	}
}
