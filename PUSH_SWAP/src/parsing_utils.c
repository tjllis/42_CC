/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:42:05 by tsemenov          #+#    #+#             */
/*   Updated: 2025/05/11 13:42:06 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ');
}

int	count_spaces(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
			count++;
		i++;
	}
	return (count + 1);
}

void	free_matrix(char **result)
{
	int	i;

	if (result == NULL)
		return ;
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	ft_atoi_safe(char *str, int *result)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num = num * sign;
	if (num < INT_MIN || num > INT_MAX)
		return (ATOI_FAIL);
	*result = (int)num;
	return (ATOI_SUCCESS);
}
