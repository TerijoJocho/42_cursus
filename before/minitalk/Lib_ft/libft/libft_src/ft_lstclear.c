/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:40:29 by daavril           #+#    #+#             */
/*   Updated: 2024/09/12 14:14:40 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	if (!*lst || !lst)
		return ;
	while (*lst)
	{
		next_node = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = next_node;
	}
	*lst = NULL;
}
/*supp la lst jusqua la fn et l'initialise a NULL
pas de current car on veut vraiment tt effacer*/
