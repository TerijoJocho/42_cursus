/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 20:31:33 by daavril           #+#    #+#             */
/*   Updated: 2024/09/12 14:14:50 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_elem;
	t_list	*new_list;

	if (!del || !f || !lst)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
/*t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*new;

	if (!del || !lst || !f)
		return (NULL);
	first_node = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			while (first_node)
			{
				new = first_node->next;
				(*del)(first_node->content);
				free(first_node);
				first_node = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first_node, new);
		lst = lst->next;
	}
	return (first_node);
}*/
/*t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*res;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!(new_list))
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	res = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew(f(lst->content));
		if (!(new_list->next))
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		lst = lst->next;
		new_list = new_list->next;
	}
	new_list->next = NULL;
	return (res);
}*/
