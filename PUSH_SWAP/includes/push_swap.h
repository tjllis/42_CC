/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:46:23 by tsemenov          #+#    #+#             */
/*   Updated: 2025/05/11 13:46:24 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# define ATOI_SUCCESS 1
# define ATOI_FAIL 0

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	top;
}	t_stack;

// utils:
t_stack	*create_stack(int capacity);
int		is_sorted(t_stack *stack);
int		is_empty(t_stack *stack);
void	fill_stack(t_stack *stack, int *arr);
void	free_stack(t_stack *stack);
// operations:
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	move_to_top(t_stack *stack, int index);
// movements:
void	sa(t_stack *stack, int is_to_print);
void	sb(t_stack *stack, int is_to_print);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *stack, int is_to_print);
void	rb(t_stack *stack, int is_to_print);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *stack, int is_to_print);
void	rrb(t_stack *stack, int is_to_print);
void	rrr(t_stack *a, t_stack *b);
// sort:
void	normalize_values(int *numbers, int size);
void	small_sort(t_stack *a, t_stack *b);
void	radix_sort_desc(t_stack *a, t_stack *b);
void	main_sort(t_stack *a, t_stack *b);
// validation & parcing:
int		is_numeric_str(char *str);
int		is_numeric_mult(char **str);
int		count_spaces(char *str);
void	free_matrix(char **result);
int		ft_atoi_safe(char *str, int *result);
int		parse_str_input(char *str, int *nums, int capacity);
int		*process_one_str(char *str, int capacity);
int		parse_mult_input(char **str, int *nums, int capacity);
int		*process_mult_str(int ac, char **av);
// helper functions:
void	ft_putstr_fd(char *s, int fd);
int		is_found(int *arr, int size, int num);
char	**ft_split(char const *s, char c);
//error handling & cleaning:
void	ft_quit(void);
void	ft_clean_quit(t_stack *a, t_stack *b);
void	success_clean(t_stack *a, t_stack *b, int *arr);

#endif
