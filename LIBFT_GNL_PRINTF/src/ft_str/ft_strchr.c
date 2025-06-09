/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:37:07 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/14 14:37:11 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char) c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char) c && (unsigned char) c == '\0')
		return ((char *)s);
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
	printf("Original strchr: %s\n", strchr(str, a));
	printf("Original strchr: %s\n", strchr(str, b));
	printf("Original strchr: %s\n", strchr(str, c));
	printf("Custom strchr: %s\n", ft_strchr(str, a));
	printf("Custom strchr: %s\n", ft_strchr(str, b));
	printf("Custom strchr: %s\n", ft_strchr(str, c));
	return (0);
}*/
