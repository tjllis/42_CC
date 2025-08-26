/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:28:31 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/26 22:24:38 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo);
static void	release_forks(t_philo *philo);

int	ft_eat(t_philo *philo)
{
	if (take_forks(philo) == FAIL)
		return (FAIL);
	update_last_meal_time(philo);
	set_meals_eaten(philo);
	print_status(philo, EAT);
	ft_usleep(philo->data->time_to_eat);
	release_forks(philo);
	return (SUCCESS);
}

static int	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->data->num_philos == 1)
		return (FAIL);
	first_fork = philo->left_fork;
	second_fork = philo->right_fork;
	if (pthread_mutex_lock(first_fork) != 0)
		return (FAIL);
	print_status(philo, TOOK_FORK);
	if (pthread_mutex_lock(second_fork) != 0)
	{
		pthread_mutex_unlock(first_fork);
		return (FAIL);
	}
	print_status(philo, TOOK_FORK);
	return (SUCCESS);
}

static void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
