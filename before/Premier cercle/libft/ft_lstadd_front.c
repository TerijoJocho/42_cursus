/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:25:38 by daavril           #+#    #+#             */
/*   Updated: 2024/05/30 17:51:51 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
/*#include <stdio.h>
int	main(void)
{
	t_list  *new_node;
	t_list  *add;
	t_list  *head;

	char str[] = "lorem ipsum dolor sit";
	char str2[] = "bonjour";

	//head = NULL;
	new_node = ft_lstnew((void *)str);
	add = ft_lstnew((void *)str2);

	// ft_lstadd_front(&head, new_node);
	// printf("%s\n", (char *)head->content); // str
	// printf("%s\n", (char *)head->next); // NULL
	// ft_lstadd_front(&head, add);
	// printf("%s\n", (char *)head->content); // str2

	head->content = "o";
	head->next = new_node;
	printf("%s\n", (char *)head->content);
	printf("%s\n", (char *)head->next);
}*/
/*int main(void)
{
	t_list *head = NULL;
	t_list *new_node;
	char str1[] = "lorem ipsum dolor sit";
	char str2[] = "amet consectetur adipiscing elit";

	// Création et ajout de nœuds à la liste
	new_node = ft_lstnew((void *)str1);
	ft_lstadd_front(&head, new_node);

	new_node = ft_lstnew((void *)str2);
	ft_lstadd_front(&head, new_node);

	// Affichage du contenu de la liste
	t_list *current = head;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	// Libération de la mémoire
	while (head != NULL)
	{
		t_list *tmp = head;
		head = head->next;
		free(tmp);
	}

	return (0);
}*/
/*ajoute un maillon a un autre dans une chaine par le debut */