/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:38:08 by tsemenov          #+#    #+#             */
/*   Updated: 2025/08/25 20:40:56 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	atoi_pos(char *str);
static int	put_int(int *dest, char *src);
static int	put_uint64(uint64_t *dest, char *src);
static int	are_valid(char **av, t_data *data);

int	parse_args(int ac, char **av, t_data *data)
{
	if (ac < 5 || ac > 6)
	{
		ft_putendl_fd("Error: Invalid number of arguments", 2);
		return (FAIL);
	}
	if (are_valid(av, data) == FAIL)
		return (FAIL);
	if (ac == 6)
	{
		if (put_int(&data->max_meals, av[5]) == FAIL)
		{
			ft_putendl_fd("Error: Invalid arguments", 2);
			return (FAIL);
		}
	}
	else
		data->max_meals = 0;
	return (SUCCESS);
}

static int	atoi_pos(char *str)
{
	long	num;
	int		i;

	if (str == NULL || *str == '\0')
		return (FAIL);
	num = 0;
	i = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (FAIL);
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9' && num <= INT_MAX)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] && ('0' > str[i] || str[i] > '9'))
		return (FAIL);
	if (num > INT_MAX || num == 0)
		return (FAIL);
	return ((int)num);
}

static int	put_int(int *dest, char *src)
{
	int	temp;

	temp = atoi_pos(src);
	if (temp == FAIL)
		return (FAIL);
	*dest = temp;
	return (SUCCESS);
}

static int	put_uint64(uint64_t *dest, char *src)
{
	int	temp;

	temp = atoi_pos(src);
	if (temp == FAIL)
		return (FAIL);
	*dest = (uint64_t)temp;
	return (SUCCESS);
}

static int	are_valid(char **av, t_data *data)
{
	if (put_int(&data->num_philos, av[1]) == FAIL
		|| put_uint64(&data->time_to_die, av[2]) == FAIL
		|| put_uint64(&data->time_to_eat, av[3]) == FAIL
		|| put_uint64(&data->time_to_sleep, av[4]) == FAIL)
	{
		ft_putendl_fd("Error: Invalid arguments", 2);
		return (FAIL);
	}
	return (SUCCESS);
}
