/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:51:07 by daavril           #+#    #+#             */
/*   Updated: 2024/09/12 14:14:47 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*#include <stdio.h>
int	main(void)
{
	t_list  *head;
	t_list  *node;
	t_list  *last;

	char    *s1 = "bonjour";
	char    *s2 = "bonsoir";

	head = NULL;
	node = ft_lstnew((char *)s1);
	ft_lstadd_front(&head, node);
	printf("head++ :%s\n", (char *)node->content);
	node = ft_lstnew((char *)s2);
	ft_lstadd_front(&head, node);
	printf("head++ :%s\n", (char *)node->content);

	printf("size :%d\n", ft_lstsize(head));

	last = ft_lstlast(head);
	printf("last head :%s", (char *)last->content);
	return (0);
}*/
/*donne le dernier maillon d'une chaine*/
