/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:43:10 by tsemenov          #+#    #+#             */
/*   Updated: 2025/05/11 13:43:11 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack, int is_to_print)
{
	int	temp;
	int	i;

	if (stack->top <= 0)
		return ;
	i = stack->top;
	temp = stack->arr[stack->top];
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = temp;
	if (is_to_print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack, int is_to_print)
{
	int	temp;
	int	i;

	if (stack->top <= 0)
		return ;
	i = stack->top;
	temp = stack->arr[stack->top];
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = temp;
	if (is_to_print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	ft_putstr_fd("rr\n", 1);
}
