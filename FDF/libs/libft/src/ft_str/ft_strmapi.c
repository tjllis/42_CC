/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:48:01 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/22 11:48:02 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*result;
	size_t				len;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = (unsigned char)f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
    char str[] = "LoReM iPsUm";
    char *str2 = ft_strmapi(str, change);
    if (str2 == str)
        printf("\nA new string was not returned");
    if (str2[11] != '\0')
        printf("\nString is not null terminated");
    printf("%s\n", str);
    return (0);
}*/
