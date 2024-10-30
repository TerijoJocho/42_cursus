/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:41:43 by daavril           #+#    #+#             */
/*   Updated: 2024/10/01 18:01:55 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **pile_a, t_list **pile_b)
{
	t_list	*temp;

	if (!(*pile_a))
		return ;
	temp = (*pile_a);
	(*pile_a) = (*pile_a)->next;
	ft_lstadd_front(pile_b, temp);
	ft_printf("pb\n");
}

void	push_a(t_list **pile_a, t_list **pile_b)
{
	t_list	*temp;

	if (!(*pile_b))
		return ;
	temp = (*pile_b);
	(*pile_b) = (*pile_b)->next;
	ft_lstadd_front(pile_a, temp);
	ft_printf("pa\n");
}
