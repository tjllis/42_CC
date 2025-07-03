/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:38:38 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/22 12:38:40 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_counter(char const *s, char c)
{
	int	i;
	int	word;
	int	counter;

	i = 0;
	word = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !word)
		{
			word = 1;
			counter++;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (counter);
}

static char	*make_str(char const *s, int len)
{
	int		i;
	char	*newstr;

	newstr = malloc(len + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

static char	*get_str(char const **s, char c)
{
	char	*newstr;
	char	*start;
	int		len;

	len = 0;
	while (**s && **s == c)
		(*s)++;
	if (**s == '\0')
		return (NULL);
	start = (char *)*s;
	while (**s && **s != c)
	{
		(*s)++;
		len++;
	}
	if (start == *s)
		return (NULL);
	else
		newstr = make_str(start, len);
	return (newstr);
}

static void	free_all(char **result)
{
	int	i;

	if (result == NULL)
		return ;
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		counter;
	int		i;

	counter = get_counter(s, c);
	result = malloc((counter + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < counter)
	{
		result[i] = get_str(&s, c);
		if (result[i] == NULL)
		{
			free_all(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
