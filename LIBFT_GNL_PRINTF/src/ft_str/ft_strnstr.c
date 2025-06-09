/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:58:36 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/29 14:09:59 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		while (i + j < len && little[j] != '\0'
			&& big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)(big + i));
		}
		i++;
		j = 0;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	// printf("%s\n", ft_strnstr("fake", ((void*)0), 3));
	// printf("%s\n", ft_strnstr(((void*)0), "fake", 3));

*/
