/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:08:34 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/11 16:08:35 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
/*
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	//char *dest = "";
	//char *src = "Hello!";
	//printf("%d\n", strlcpy(dest, src, 5));
	char *dest2 = "";
	char *src2 = "Hello!";
	printf("%zu\n", ft_strlcpy(dest2, src2, 5));
}*/
