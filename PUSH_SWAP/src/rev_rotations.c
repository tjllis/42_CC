/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:42:44 by tsemenov          #+#    #+#             */
/*   Updated: 2025/05/11 13:42:45 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack, int is_to_print)
{
	int	i;
	int	temp;

	if (stack->top <= 0)
		return ;
	temp = stack->arr[0];
	i = 0;
	while (i < stack->top)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->top] = temp;
	if (is_to_print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack, int is_to_print)
{
	int	i;
	int	temp;

	if (stack->top <= 0)
		return ;
	temp = stack->arr[0];
	i = 0;
	while (i < stack->top)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[stack->top] = temp;
	stack->arr[0] = temp;
	if (is_to_print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_putstr_fd("rrr\n", 1);
}
