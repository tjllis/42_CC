/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:41:48 by tsemenov          #+#    #+#             */
/*   Updated: 2025/05/11 13:41:49 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	parse_str_input(char *str, int *nums, int capacity)
{
	int		i;
	int		result;
	char	**arr;

	arr = ft_split(str, ' ');
	if (arr == NULL)
		return (0);
	i = 0;
	while (i < capacity && arr[i] != NULL)
	{
		if (ft_atoi_safe(arr[i], &result) != ATOI_SUCCESS)
			break ;
		if (is_found(nums, i, result))
			break ;
		nums[i] = result;
		i++;
	}
	free_matrix(arr);
	return (i == capacity);
}

int	*process_one_str(char *str, int capacity)
{
	int	*arr;
	int	success;

	arr = malloc(sizeof(int) * capacity);
	if (arr == NULL)
		return (NULL);
	if (!is_numeric_str(str))
	{
		free(arr);
		return (NULL);
	}
	success = parse_str_input(str, arr, capacity);
	if (!success)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
