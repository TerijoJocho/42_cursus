/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_cheapest.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:11 by daavril           #+#    #+#             */
/*   Updated: 2024/10/15 17:58:44 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_the_cheapest(t_list **pile_a, t_list **pile_b)
{
	t_list	*temp;

	temp = pile_a;
	while (temp)
	{
		if(!(is_cheapest(temp->content)))
			temp = temp->next;

	}
}


CACCAAAA faire celu d'alex bcpplus simple 
