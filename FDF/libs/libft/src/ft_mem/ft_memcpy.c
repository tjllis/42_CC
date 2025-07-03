/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:17:11 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/14 12:17:13 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*stemp;
	size_t		i;
	char		*dtemp;

	i = 0;
	dtemp = dest;
	stemp = src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dtemp[i] = stemp[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char str[8] = "aaaaaaa";
	char str2[8] = "bbbbbbb";
	memcpy(str, str2, 5);
	printf("Original memcpy: %s\n", str);
	
	char s[8] = "";
	char s2[8] = "bbbbbbb";
	memcpy(s, s2, 5);
	printf("Original memcpy: %s\n", s);
	
	char str3[8] = "aaaaaaa";
	char str4[8] = "bbbbbbb";
	ft_memcpy(str3, str4, 5);
	printf("Custom memcpy: %s\n", str3);
	
	char s3[8];
	char s4[8] = "bbbbbbb";
	ft_memcpy(s3, s4, 5);
	printf("Custom memcpy: %s\n", s3);
	return (0);
}*/
