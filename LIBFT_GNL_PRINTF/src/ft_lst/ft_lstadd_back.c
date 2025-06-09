/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:30:39 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/25 14:30:41 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
/*
#include <stdio.h>

void	print_lst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s ", (char *)lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list *begin, *elem, *elem2, *elem3, *elem4;
	begin = NULL;
	char *e = "Lorem";
	char *e2 = "ipsum";
	char *e3 = "dolor";
	char *e4 = "sit";
	elem = malloc(sizeof(t_list));
	elem2 = malloc(sizeof(t_list));
	elem3 = malloc(sizeof(t_list));
	elem4 = malloc(sizeof(t_list));

	if (!elem || !elem2 || !elem3 || !elem4) {
		// Check if malloc fails
		printf("Memory allocation failed\n");
		return 1;
	}

	// Initialize the content for each node
	elem->content = e;
	elem2->content = e2;
	elem3->content = e3;
	elem4->content = e4;

	// Set next pointers to NULL as they are individual nodes for now
	elem->next = NULL;
	elem2->next = NULL;
	elem3->next = NULL;
	elem4->next = NULL;
    	ft_lstadd_back(&begin, elem);
    	ft_lstadd_back(&begin, elem2);
    	ft_lstadd_back(&begin, elem3);
    	ft_lstadd_back(&begin, elem4);
    	print_lst(begin);
    	t_list *temp;
    	while (begin != NULL)
    	{
		temp = begin;
		begin = begin->next;
		free(temp);
	}
}*/
