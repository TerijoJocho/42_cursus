/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:58:05 by daavril           #+#    #+#             */
/*   Updated: 2024/05/30 16:39:41 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
/*#include <stdio.h>

int	main(void)
{
	t_list *new_node;

	// new_node = ft_lstnew((void *)(__intptr_t)42);
	// printf("%d", (int)(__intptr_t)new_node->content);
	// free(new_node);
	char str[] = "lorem ipsum dolor sit";
	new_node = ft_lstnew((void *)str);
	printf("%s", (char *)new_node->content);
	free(new_node);
	return (0);
}*/
/*initialise une liste*/