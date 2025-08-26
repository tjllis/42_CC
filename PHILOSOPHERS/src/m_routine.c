/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_routine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:28:57 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/26 22:26:23 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	all_ate(t_data *data);
static void	handle_death(t_data *data, int dead_philo);
static int	is_dead(t_data *data);
static void	handle_success(t_data *data);

void	*m_routine(void *arg)
{
	t_data	*data;
	int		dead_philo;
	int		sim_ended;

	data = (t_data *)arg;
	sim_ended = get_sim_ended(data);
	while (!sim_ended)
	{
		dead_philo = is_dead(data);
		if (dead_philo > -1)
		{
			handle_death(data, dead_philo);
			break ;
		}
		if (data->max_meals && all_ate(data) == SUCCESS)
		{
			handle_success(data);
			break ;
		}
		sim_ended = get_sim_ended(data);
		usleep(5000);
	}
	return (NULL);
}

static void	handle_death(t_data *data, int dead_philo)
{
	int			sim_ended;
	uint64_t	death_time;

	pthread_mutex_lock(&data->philos[dead_philo].last_meal_lock);
	death_time = data->philos[dead_philo].last_meal_time + data->time_to_die;
	pthread_mutex_unlock(&data->philos[dead_philo].last_meal_lock);
	sim_ended = get_sim_ended(data);
	if (!sim_ended)
	{
		print_death(&data->philos[dead_philo], DIED, death_time);
		set_sim_ended(data, 1);
	}
}

static int	is_dead(t_data *data)
{
	uint64_t	last_time;
	int			i;

	i = 0;
	while (i < data->num_philos)
	{
		last_time = get_last_meal_time(&data->philos[i]);
		if (last_time > data->time_to_die)
			return (i);
		i++;
	}
	return (-1);
}

static void	handle_success(t_data *data)
{
	int	sim_ended;

	sim_ended = get_sim_ended(data);
	if (!sim_ended)
	{
		pthread_mutex_lock(&data->print_lock);
		printf("All ate!\n");
		pthread_mutex_unlock(&data->print_lock);
		set_sim_ended(data, 1);
	}
}

static int	all_ate(t_data *data)
{
	int	i;
	int	meals;

	i = 0;
	while (i < data->num_philos)
	{
		meals = get_meals_eaten(&data->philos[i]);
		if (meals < data->max_meals)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}
