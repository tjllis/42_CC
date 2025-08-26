/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:57:34 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/26 22:27:15 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_env.h"

// cleaners.c:
void		clean_data(t_data *data);
void		clean_philos(t_data *data);
void		destroy_ph_locks(t_philo *philo);
void		clean_forks(t_data *data);
// ft_eat:
int			ft_eat(t_philo *philo);
// getters.c:
int			get_meals_eaten(t_philo *philo);
uint64_t	get_last_meal_time(t_philo *philo);
int	get_philo_state(t_data *data);
int			get_sim_ended(t_data *data);
// init_*.c:
t_data		*init_data(int ac, char **av);
int			init_philos(t_data *data);
// m_routine:
void		*m_routine(void *arg);
// parsing.c:
int			parse_args(int ac, char **av, t_data *data);
// ph_routine:
void		*ph_routine(void *arg);
// setters.c:
void		update_last_meal_time(t_philo *philo);
void		set_meals_eaten(t_philo *philo);
void		set_sim_ended(t_data *data, int value);
// simulation.c:
int			start_sim(t_data *data);
void		end_sim(t_data *data);
// utils.c:
void		ft_putendl_fd(const char *s, int fd);
uint64_t	get_time_ms(void);
void		print_status(t_philo *philo, char *msg);
void		print_death(t_philo *philo, char *msg, uint64_t death_time);
void		ft_usleep(uint64_t sleep_time);

#endif