/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:40:21 by tsemenov          #+#    #+#             */
/*   Updated: 2025/05/11 13:40:22 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap(int *arr, int a, int b)
{
	int	temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	swapped;

	i = 0;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				ft_swap(arr, i, i + 1);
				swapped = 1;
			}
			i++;
		}
		size--;
	}
}

static void	replace_numbers(int *numbers, int *sorted_arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (numbers[i] == sorted_arr[j])
			{
				numbers[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	fill_arr(int *numbers, int *sorted_arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		sorted_arr[i] = numbers[i];
		i++;
	}
}

void	normalize_values(int *numbers, int size)
{
	int	*sorted_arr;

	sorted_arr = malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	fill_arr(numbers, sorted_arr, size);
	bubble_sort(sorted_arr, size);
	replace_numbers(numbers, sorted_arr, size);
	free(sorted_arr);
}

// #include <stdio.h>

// int	main()
// {
// 	int arr[] = { 1, 3, 0, -5, 7 };
// 	normalize_values(arr, 5);
// 	// bubble_sort(arr, 5);
// 	int i = 0;
// 	while (i < 5)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// }
