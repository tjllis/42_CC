/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:49:26 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/20 11:49:28 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strndup(char const *src, size_t len)
{
	char	*newstr;

	newstr = malloc(len + 1);
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, src, len + 1);
	return (newstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	copy_len;
	char			*copy;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strndup("", 0));
	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] != '\0' && is_inset(s1[start], set))
		start++;
	while (end >= start && is_inset(s1[end], set))
		end--;
	copy_len = (end - start) + 1;
	if (copy_len == 0)
		return (ft_strndup("", 0));
	copy = ft_strndup(&s1[start], copy_len);
	return (copy);
}
/*
#include <stdio.h>

int main() {
    char *s1 = "  **Hello, World!**  ";
    char *set = " *";  // Define the set of characters to trim

    char *trimmed = ft_strtrim(s1, set);
    if (trimmed) {
        printf("Original string: '%s'\n", s1);
        printf("Trimmed string: '%s'\n", trimmed);
        free(trimmed);  // Don't forget to free the allocated memory
    } else {
        printf("Memory allocation failed or invalid input.\n");
    }

    return 0;
}*/
