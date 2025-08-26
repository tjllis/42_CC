/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:43:38 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/26 22:26:06 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->last_meal_lock);
}

void	set_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->meals_eaten_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_eaten_lock);
}


void	set_sim_ended(t_data *data, int value)
{
	pthread_mutex_lock(&data->death_lock);
	data->sim_ended = value;
	pthread_mutex_unlock(&data->death_lock);
}
