/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:02:54 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/14 14:02:57 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number * sign);
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char *a = "---+--+1234ab567";
	printf("Original atoi: %d\n", atoi(a));
	char *str = "";
	printf("Original atoi: %d\n", atoi(str));
	char *c = "-1234ab567";
	printf("Original atoi: %d\n", atoi(c));
	
	printf("Custom atoi: %d\n", ft_atoi(a));
	printf("Custom atoi: %d\n", ft_atoi(str));
	printf("Custom atoi: %d\n", ft_atoi(c));

	return (0);
}*/
