/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_pushes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:44:32 by tsemenov          #+#    #+#             */
/*   Updated: 2025/05/13 16:40:27 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack, int is_to_print)
{
	int	temp;

	if (stack->top == -1)
		return ;
	temp = stack->arr[stack->top];
	stack->arr[stack->top] = stack->arr[stack->top - 1];
	stack->arr[stack->top - 1] = temp;
	if (is_to_print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack, int is_to_print)
{
	int	temp;

	if (stack->top == -1)
		return ;
	temp = stack->arr[stack->top];
	stack->arr[stack->top] = stack->arr[stack->top - 1];
	stack->arr[stack->top - 1] = temp;
	if (is_to_print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *a, t_stack *b)
{
	int	value;

	if (b->top == -1)
		return ;
	value = pop(b);
	push(a, value);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	int	value;

	if (a->top == -1)
		return ;
	value = pop(a);
	push(b, value);
	ft_putstr_fd("pb\n", 1);
}
