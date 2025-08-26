/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:04:34 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/25 23:50:37 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_data(t_data *data)
{
	if (data == NULL)
		return ;
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->death_lock);
	if (data->forks)
		clean_forks(data);
	if (data->philos)
		clean_philos(data);
	free(data);
}

void	clean_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		destroy_ph_locks(&data->philos[i]);
		i++;
	}
	free(data->philos);
}

void	destroy_ph_locks(t_philo *philo)
{
	pthread_mutex_destroy(&philo->meals_eaten_lock);
	pthread_mutex_destroy(&philo->last_meal_lock);
	// pthread_mutex_destroy(&philo->state_lock);
}

void	clean_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}
