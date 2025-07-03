/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsemenov <tsemenov@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:22:37 by tsemenov          #+#    #+#             */
/*   Updated: 2024/11/25 18:22:38 by tsemenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*void	del(void *content)
{
	free(content);
}*/

/*
int main() {
    t_list *node = malloc(sizeof(t_list));  // Allocate memory for a node
    node->content = malloc(20);  // Allocate memory for the content (string)
    strcpy(node->content, "Hello, World!");

    // Now delete the node using ft_lstdelone
    ft_lstdelone(node, del);  // This will delete the content and the node
    return 0;
}*/
