/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:45:27 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/25 20:58:57 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_threads(t_data *data);
static void	clean_threads(t_data *data);

int	start_sim(t_data *data)
{
	if (start_threads(data) == FAIL)
	{
		set_sim_ended(data, 1, 0);
		clean_data(data);
		return (FAIL);
	}
	return (SUCCESS);
}

void	end_sim(t_data *data)
{
	clean_threads(data);
	clean_data(data);
}

static int	start_threads(t_data *data)
{
	int	i;

	if (pthread_create(&data->monitor, NULL, m_routine, data) != 0)
	{
		ft_putendl_fd("Error: Failed to create monitor thread.", 2);
		return (FAIL);
	}
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				ph_routine, &data->philos[i]) != 0)
		{
			while (--i >= 0)
				pthread_join(data->philos[i].thread, NULL);
			pthread_join(data->monitor, NULL);
			ft_putendl_fd("Error: Failed to create philosophers threads.", 2);
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

static void	clean_threads(t_data *data)
{
	int	i;

	pthread_join(data->monitor, NULL);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}
