/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:34:39 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/14 15:34:40 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		cc;
	size_t				i;

	i = 0;
	p = (const unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == cc)
			return ((void *)(p + i));
		i++;
	}
	return ((void *)0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	int a = '\0';
	int b = 5;
	int c = 'j';
	char *str = "Brown fox jumps ov5r a grAss A";
	printf("Original memchr: %p\n", memchr(str, a, 20));
	printf("Original memchr: %p\n", memchr(str, b, 15));
	printf("Original memchr:%p\n", memchr(str, c, 12));
	printf("Custom strchr: %p\n", ft_memchr(str, a, 20));
	printf("Custom strchr: %p\n", ft_memchr(str, b, 15));
	printf("Custom strchr: %p\n", ft_memchr(str, c, 12));
	return (0);
}*/
