/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:44:17 by tsemenov          #+#    #+#             */
/*   Updated: 2025/05/11 13:44:18 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->arr = (int *)malloc(sizeof(int) * capacity);
	if (stack->arr == NULL)
	{
		free(stack);
		return (NULL);
	}
	stack->size = capacity;
	stack->top = -1;
	return (stack);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	if (stack->top <= 0)
		return (1);
	i = stack->top;
	while (i > 0)
	{
		if (stack->arr[i] > stack->arr[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	is_empty(t_stack *stack)
{
	if (stack->top < 0)
		return (1);
	return (0);
}

void	fill_stack(t_stack *stack, int *arr)
{
	int	i;

	i = stack->size - 1;
	while (i >= 0)
	{
		push(stack, arr[i]);
		i--;
	}
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->arr)
			free(stack->arr);
		free(stack);
	}
}
