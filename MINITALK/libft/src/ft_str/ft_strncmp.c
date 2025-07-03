/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:28:47 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/14 15:28:49 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n)
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0' && c2 == '\0')
			break ;
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
        int     a;
        int     b;
        int     c;

        char s1[] = "Hello";
        char s2[] = "World";
        char s3[] = "Hello";
        char s4[] = "Hi";
        a = ft_strncmp(s1, s2, 1);
        b = ft_strncmp(s3, s1, 2);
        c = ft_strncmp(s2, s4, 3);
        printf("Custom strncmp: %i\n%i\n%i\n", a, b, c);

        int d = strncmp(s1, s2, 1);
        int e = strncmp(s3, s1, 2);
        int f = strncmp(s2, s4, 3);
        printf("Original srtncmp: %d\n%d\n%d\n", d, e, f);
        return (0);
}*/
