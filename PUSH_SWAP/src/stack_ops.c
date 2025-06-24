/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:43:52 by tsemenov          #+#    #+#             */
/*   Updated: 2025/05/13 16:41:13 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack *stack, int value)
{
	if (stack->top == stack->size - 1)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	stack->arr[++stack->top] = value;
}

int	pop(t_stack *stack)
{
	int	value;

	if (stack->top < 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	value = stack->arr[stack->top];
	stack->top -= 1;
	return (value);
}

void	move_to_top(t_stack *stack, int index)
{
	int	i;
	int	j;

	i = stack->top - index;
	j = stack->top - i;
	if (i == 0)
		return ;
	if (i <= (stack->top + 1) / 2)
	{
		while (i > 0)
		{
			ra(stack, 1);
			i--;
		}
	}
	else
	{
		while (j >= 0)
		{
			rra(stack, 1);
			j--;
		}
	}
}
