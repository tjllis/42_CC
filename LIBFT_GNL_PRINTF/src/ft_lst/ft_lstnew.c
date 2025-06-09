/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:52:37 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/23 17:52:40 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *data = "hello, i'm a data";
 	t_list *l = ft_lstnew(data);
 	write(2, "", 1);
 	printf("%s\n", (char *)l->content);
 	if (!strcmp(data, l->content))
 		printf("Success\n");
 	else
 		printf("Fail\n");
 	free(l);

}*/
