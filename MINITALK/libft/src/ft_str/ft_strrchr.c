/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:02:47 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/14 15:02:48 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*match;

	match = (void *)0;
	while (*s != '\0')
	{
		if (*s == (unsigned char) c)
			match = s;
		s++;
	}
	if (*s == (unsigned char) c && (unsigned char) c == '\0')
		match = s;
	return ((char *)match);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	int a = '\0';
	int b = 5;
	int c = 'f';
	char *str = "the function’s behavior may differ";
	printf("Original strrchr: %p\n", strrchr(str, a));
	printf("Original strrchr: %s\n", strrchr(str, b));
	printf("Original strrchr: %s\n", strrchr(str, c));
	printf("Custom strchr: %p\n", ft_strrchr(str, a));
	printf("Custom strchr: %s\n", ft_strrchr(str, b));
	printf("Custom strchr: %s\n", ft_strrchr(str, c));
	return (0);
}*/
