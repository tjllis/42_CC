/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:02:16 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/12 12:02:18 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= dstlen)
		return (srclen + size);
	while (src[i] != '\0' && i < size - dstlen - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char *src = "Hello!";
	char dest[30] = "";
	ft_strlcat(dest, src, 4);
	printf("%lu\n", ft_strlcat(dest, src, 5)); // 10 = 3 + len of src(6) + '\0'
	printf("%s\n", dest);

	char *src2 = "Hello!";
	char dest2[30] = "Hi!";
	ft_strlcat(dest, src, 0);
	printf("%lu\n", ft_strlcat(dest2, src2, 0)); // 6 = len of src, no cat
	// size < dstlen, src + size
	printf("%s\n", dest2);

	char *src3 = "Hello!";
	char dest3[3] = "Hi!";
	printf("%lu\n", ft_strlcat(dest3, src3, 7)); // 9 = 3 + 5(Hello) + '\0'
	printf("%s\n", dest3);

	char *src4 = "Hello!";
	char dest4[10] = "H";
	printf("%lu\n", ft_strlcat(dest4, src4, 3)); // 7 = Hello! (src)
	printf("%s\n", dest4);
	printf("%lu\n", ft_strlen(dest4));

char dest5[20];
unsigned int result;
memset(dest5, 'r', 15);
result = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
printf("Resulting string: %s\n", dest5);
printf("Total length: %u\n", result);
	return (0);
	
}*/
