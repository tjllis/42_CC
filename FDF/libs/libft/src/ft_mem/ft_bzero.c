/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:57:07 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/14 11:57:08 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = s;
	while (n > 0)
	{
		str[i] = '\0';
		i++;
		n--;
	}
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char str[5];
	char str2[7] = "aaaaaaa";
	bzero(str, 5);
	bzero(str2, 5);
	printf("Original bzero: %s\n", str);
	printf("Original bzero: %s\n", str2);
	printf("\n");
	
	char str3[5];
	char str4[7] = "aaaaaaa";
	ft_bzero(str3, 5);
	ft_bzero(str4, 5);
	printf("Custom bzero: %s\n", str3);
	printf("Custom bzero: %s\n", str4);
	return (0);
}*/
