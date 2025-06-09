/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:46:27 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/19 13:46:28 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = malloc((len1 + len2 + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, len1 + 1);
	ft_strlcat(newstr, s2, (len1 + len2 + 1));
	return (newstr);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s1 = "Hello!";
	char *s2 = "How are you?";
	char *str = ft_strjoin(s1, s2);
	printf("%s\n", str);
	
	char *s3 = "Hello!";
	char *s4;
	char *str2 = ft_strjoin(s3, s4);
	printf("%s\n", str2);
	
	char *s5 = "";
	char *s6 = "Hello";
	char *str3 = ft_strjoin(s5, s6);
	printf("%s\n", str3);
	
	free(str);
	free(str2);
	free(str3);
}*/
