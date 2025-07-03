/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:37:20 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/14 17:37:22 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp1;
	const unsigned char	*temp2;
	size_t				i;

	i = 0;
	temp1 = s1;
	temp2 = s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (temp1[i] != temp2[i])
			return (temp1[i] - temp2[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char *s1 = "Hello";
	char *s2 = "Hello World";
	char *s3 = "hello";
	char *s4 = "Hello";
	
	int arr[] = {1, 2, 3, 4, 5};
	int arr2[] = {1, 3, 3};
	printf("Original memcmp: %d\n", memcmp(s1, s2, 5));
	printf("Original memcmp: %d\n", memcmp(s1, s2, 10));
	printf("Original memcmp: %d\n", memcmp(s1, s3, 0));
	printf("Original memcmp: %d\n", memcmp(s1, s4, 5));
	printf("Original memcmp: %d\n", memcmp(arr, arr2, 5));
	printf("Original memcmp: %d\n", memcmp(arr, arr2, 3));
	printf("\n");
	printf("Custom memcmp: %d\n", ft_memcmp(s1, s2, 5));
	printf("Custom memcmp: %d\n", ft_memcmp(s1, s2, 10));
	printf("Custom memcmp: %d\n", ft_memcmp(s1, s3, 0));
	printf("Custom memcmp: %d\n", ft_memcmp(s1, s4, 5));
	printf("Custom memcmp: %d\n", ft_memcmp(arr, arr2, 5));
	printf("Custom memcmp: %d\n", ft_memcmp(arr, arr2, 3));
	return (0);
}*/
