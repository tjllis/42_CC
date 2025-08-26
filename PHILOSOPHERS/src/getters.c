/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:54:06 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/26 00:01:52 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_meals_eaten(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(&philo->meals_eaten_lock);
	meals = philo->meals_eaten;
	pthread_mutex_unlock(&philo->meals_eaten_lock);
	return (meals);
}

uint64_t	get_last_meal_time(t_philo *philo)
{
	uint64_t	last_time;
	uint64_t	current_time;

	current_time = get_time_ms();
	pthread_mutex_lock(&philo->last_meal_lock);
	last_time = current_time - philo->last_meal_time;
	pthread_mutex_unlock(&philo->last_meal_lock);
	return (last_time);
}

// t_state	get_state(t_philo *philo)
// {
// 	t_state	state;

// 	pthread_mutex_lock(&philo->state_lock);
// 	state = philo->state;
// 	pthread_mutex_unlock(&philo->state_lock);
// 	return (state);
// }

int	get_sim_ended(t_data *data)
{
	int	sim_ended;

	pthread_mutex_lock(&data->death_lock);
	sim_ended = data->sim_ended;
	pthread_mutex_unlock(&data->death_lock);
	return (sim_ended);
}

int	get_philo_state(t_data *data)
{
	int	state;

	pthread_mutex_lock(&data->death_lock);
	state = data->philo_died;
	pthread_mutex_unlock(&data->death_lock);
	return (state);
}
