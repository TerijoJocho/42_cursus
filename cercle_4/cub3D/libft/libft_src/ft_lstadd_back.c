/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:50:20 by daavril           #+#    #+#             */
/*   Updated: 2024/09/12 14:14:31 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
/*#include <stdio.h>

int	main(void)
{
	t_list  *head;
	t_list  *node;
	char    *s1 = "bon";
	char    *s2 = "jour";
	int     i = 0;

	head = NULL;

	node = ft_lstnew((char *)s2);
	ft_lstadd_back(&head, node);

	node = ft_lstnew((char *)s1);
	ft_lstadd_back(&head, node);

	t_list    *current;
	current = head;
	while (current != NULL)
	{
		printf("content %d: %s\n", i, (char *)current->content);
		i++;
		current = current->next;
	}
	printf("elmt :%d\n", ft_lstsize(head));
	return (0);
}*/
/*ajoute un maillon par derriere*/
