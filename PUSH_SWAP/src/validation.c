/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:45:10 by tsemenov          #+#    #+#             */
/*   Updated: 2025/05/11 13:45:11 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

static int	is_minus_plus(char c)
{
	return (c == '+' || c == '-');
}

int	is_numeric_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (!ft_isdigit(str[i]) && !is_minus_plus(str[i]))
			return (0);
		else if (is_minus_plus(str[i]) && !ft_isdigit(str[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	is_numeric_mult(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j])
				&& !is_minus_plus(str[i][j]))
				return (0);
			else if (is_minus_plus(str[i][j])
				&& !ft_isdigit(str[i][j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
