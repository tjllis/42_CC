/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:29:14 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/25 11:29:15 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	t_list *l = ft_lstnew(ft_strdup("nyacat"));
 	t_list *n = ft_lstnew(ft_strdup("OK"));
 
 	ft_lstadd_front(&l, n);
 	if (l == n && !strcmp(l->content, "OK"))
 	{
 		printf("Success\n");
 	}
 	else
 		printf("Fail\n");

}*/
