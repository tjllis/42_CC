/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:28:41 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/26 22:26:41 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_flags_time(t_data *data);
static int	init_monitor_and_locks(t_data *data);
static int	init_forks(t_data *data);

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	if (parse_args(ac, av, data) == FAIL)
		return (free(data), NULL);
	if (init_monitor_and_locks(data) == FAIL)
		return (free(data), NULL);
	if (init_forks(data) == FAIL)
		return (clean_data(data), NULL);
	if (init_flags_time(data) != SUCCESS)
		return (clean_data(data), NULL);
	if (init_philos(data) == FAIL)
		return (clean_data(data), NULL);
	return (data);
}

static int	init_flags_time(t_data *data)
{
	data->sim_ended = 0;
	data->start_time = get_time_ms();
	return (SUCCESS);
}

static int	init_monitor_and_locks(t_data *data)
{
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
		return (FAIL);
	if (pthread_mutex_init(&data->death_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_lock);
		return (FAIL);
	}
	data->monitor = 0;
	return (SUCCESS);
}

static int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (data->forks == NULL)
		return (FAIL);
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}
