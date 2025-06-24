/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:42:24 by tsemenov          #+#    #+#             */
/*   Updated: 2025/05/11 13:42:25 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_num(t_stack *stack)
{
	int	max;
	int	i;

	if (stack->top == -1)
		return (0);
	i = 0;
	max = stack->arr[0];
	while (i < stack->size)
	{
		if (stack->arr[i] > max)
			max = stack->arr[i];
		i++;
	}
	return (max);
}

static int	get_max_bits(t_stack *stack)
{
	int	max_num;
	int	max_bits;

	max_bits = 0;
	max_num = get_max_num(stack);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort_desc(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	if (is_empty(a))
		return ;
	size = a->top + 1;
	normalize_values(a->arr, a->size);
	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits && !is_sorted(a))
	{
		j = 0;
		while (j++ < size)
		{
			if (((a->arr[a->top] >> i) & 1) == 1)
				ra(a, 1);
			else
				pb(a, b);
		}
		while (!is_empty(b))
			pa(a, b);
		i++;
	}
}

void	main_sort(t_stack *a, t_stack *b)
{
	if (a->size < 6)
		small_sort(a, b);
	else
		radix_sort_desc(a, b);
}
// #include <stdio.h>

// int	main()
// {
// 	t_stack *a = create_stack(5);
// 	t_stack *b = create_stack(5);
// 	push(a, 3);
// 	push(a, 7);
// 	push(a, -5);
// 	push(a, -10);
// 	push(a, 90);
// 	normalize_values(a->arr, a->size);
// 	// radix_sort(a, b, 10);
// 	int i = 0;
// 	while (i < a->size)
// 	{
// 		printf("%d ", a->arr[i]);
// 		i++;
// 	}
// }
