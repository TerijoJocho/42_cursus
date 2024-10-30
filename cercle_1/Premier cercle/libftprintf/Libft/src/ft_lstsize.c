/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:35:29 by daavril           #+#    #+#             */
/*   Updated: 2024/05/30 17:51:47 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
/*#include <stdio.h>
int	main(void)
{
	t_list  *node;
	char    *str;

	str = "lol";
	node = ft_lstnew((void *)str);
	printf("%s", (char *)node->content);
	printf("\n%d", ft_lstsize(node));
}*/
/*donne la taille d'une chaine; cobien de maillon elle contient*/