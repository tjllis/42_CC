/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:38:32 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/19 13:38:35 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (s == NULL)
		return (NULL);
	if ((size_t)start >= ft_strlen(s) || len == 0)
	{
		subs = malloc(1);
		if (subs == NULL)
			return (NULL);
		subs[0] = '\0';
		return (subs);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	subs = malloc(len + 1);
	if (subs == NULL)
		return (NULL);
	ft_strlcpy(subs, s + start, len + 1);
	return (subs);
}
/*
#include <stdio.h>

int	main(void)
{	char *big = "Table top is black";
	char *sub = ft_substr(big, 5, 10);
	printf("%s\n", sub);
	
	char	str[] = "lorem ipsum dolor sit amet"; //26
	char *substr = ft_substr(str, 0, 10);
	char *strsub = ft_substr(str, 7, 10);
	char *test = ft_substr("hola", 0, 0);
	printf("%s\n", substr);
	printf("%s\n", strsub);
	printf("%s\n", test);
	free(sub);
	free(substr);
	free(strsub);
	char *str = "01234";
 	size_t size = 10;
 	char *ret = ft_substr(str, 10, size);
 	printf("%s\n", ret);
 	if (!ft_strncmp(ret, "", 1))
 		printf("Success\n");
 	else
 		printf("Fail\n");
 	free(ret);
	return (0);
}*/
