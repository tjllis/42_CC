/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 16:22:27 by tsemenov          #+#    #+#             */
/*   Updated: 2025/01/03 16:22:31 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_t(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//cleanup
void	clean_after_gnl(void)
{
	char	*line;
	line = get_next_line(-42);
	if (line)
		free(line);
}


void	free_null(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
// cleanup end

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	str = (char *)malloc(sizeof(*s) * (len + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			str[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	str[j] = 0;
// 	return (str);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	const char	*match;

// 	match = (void *)0;
// 	while (*s != '\0')
// 	{
// 		if (*s == (unsigned char) c)
// 			match = s;
// 		s++;
// 	}
// 	if (*s == (unsigned char) c && (unsigned char) c == '\0')
// 		match = s;
// 	return ((char *)match);
// }

// char	*ft_strdup(const char *s)
// {
// 	int		i;
// 	int		j;
// 	char	*str;

// 	i = 0;
// 	j = ft_strlen(s);
// 	str = (char *)malloc(sizeof(*str) * (j + 1));
// 	if (!str)
// 		return (NULL);
// 	while (i < j)
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// char	*ft_strjoin(const char *s1, const char *s2)
// {
// 	int		i;
// 	int		j;
// 	char	*str;

// 	i = 0;
// 	j = 0;
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!str)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j] != '\0')
// 	{
// 		str[i + j] = s2[j];
// 		j++;
// 	}
// 	str[i + j] = '\0';
// 	return (str);
// }
