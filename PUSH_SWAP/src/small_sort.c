/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:43:42 by tsemenov          #+#    #+#             */
/*   Updated: 2025/05/11 13:43:43 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_min_index(t_stack *stack)
{
	int	min;
	int	i;
	int	index;

	i = 0;
	index = 0;
	min = INT_MAX;
	while (i <= stack->top)
	{
		if (stack->arr[i] < min)
		{
			min = stack->arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static void	sort_3(t_stack *stack)
{
	int	bottom;
	int	middle;
	int	top;

	bottom = stack->arr[0];
	middle = stack->arr[1];
	top = stack->arr[2];
	if (is_sorted(stack))
		return ;
	if (bottom > middle && bottom > top && middle < top)
		sa(stack, 1);
	else if (bottom < middle && bottom < top && middle < top)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (middle > top && middle > bottom && top < bottom)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if (middle > top && middle > bottom && top > bottom)
		rra(stack, 1);
	else if (top > bottom && top > middle)
		ra(stack, 1);
}

static void	sort_4(t_stack *a, t_stack *b)
{
	int	min_index;

	if (is_sorted(a))
		return ;
	while (!is_sorted(a))
	{
		min_index = find_min_index(a);
		if (min_index != a->top)
			move_to_top(a, min_index);
		pb(a, b);
		sort_3(a);
		pa(a, b);
	}
}

static void	sort_5(t_stack *a, t_stack *b)
{
	int	min_index;

	if (is_sorted(a))
		return ;
	while (!is_sorted(a))
	{
		min_index = find_min_index(a);
		if (min_index != a->top)
			move_to_top(a, min_index);
		pb(a, b);
		sort_4(a, b);
		while (!is_empty(b))
			pa(a, b);
	}
}

void	small_sort(t_stack *a, t_stack *b)
{
	int	size;

	if (is_sorted(a) || is_empty(a) || a->size == 1)
		return ;
	size = a->size;
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
