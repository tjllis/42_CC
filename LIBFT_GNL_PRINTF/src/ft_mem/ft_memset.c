/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:57:00 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/14 10:57:03 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (s == NULL)
		return (NULL);
	i = 0;
	str = s;
	while (n > 0)
	{
		str[i] = (unsigned char) c;
		i++;
		n--;
	}
	return (s);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char str[5];
	int i = 0;
	char str2[5];
	memset(str, '1', 5);
	memset(str2, 5, 5);
	printf("Original memset: %s\n", str);
	printf("Original memset, arr  of ints: ");
	while (i < 5)
	{
		printf("%d ", str2[i]);
		i++;
	}
	printf("\n");
	
	char str3[5];
	int j = 0;
	char str4[5];
	ft_memset(str3, '1', 5);
	ft_memset(str4, 5, 5);
	printf("Custom memset: %s\n", str3);
	printf("Custom memset, arr  of ints: ");
	while (j < 5)
	{
		printf("%d ", str4[j]);
		j++;
	}
	printf("\n");
	return (0);
}*/
