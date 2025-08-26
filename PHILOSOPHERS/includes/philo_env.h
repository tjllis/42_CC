/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:58:29 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/26 22:26:54 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// usleep takes microseconds
// 1 millisecond = 1000 microseconds
// 1 second = 1000 milliseconds
// number_of_philosophers, time_to_die, time_to_eat, time_to_sleep,
// [number_of_times_each_philosopher_must_eat]

// even num_ph:
// ttdie = tteat + ttsleep + 10 mls
// odd num_ph:
// ttdie = tteat * 2 + ttsleep + 10 mls

#ifndef PHILO_ENV_H
# define PHILO_ENV_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define SUCCESS 1
# define FAIL -1

# define TOOK_FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef struct s_data
{
	int					num_philos;
	int					max_meals;
	uint64_t			time_to_die;
	uint64_t			time_to_eat;
	uint64_t			time_to_sleep;
	uint64_t			start_time;
	struct s_philo		*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		death_lock;
	pthread_t			monitor;
	int					sim_ended;
}	t_data;

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	pthread_mutex_t		meals_eaten_lock;
	uint64_t			last_meal_time;
	pthread_mutex_t		last_meal_lock;
	pthread_t			thread;
	t_data				*data;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}	t_philo;

#endif