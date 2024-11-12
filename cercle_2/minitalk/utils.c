/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:25:12 by daavril           #+#    #+#             */
/*   Updated: 2024/11/04 13:25:34 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	free_lst(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, free);
		*lst = temp;
	}
}
