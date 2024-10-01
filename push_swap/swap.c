/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:33:52 by daavril           #+#    #+#             */
/*   Updated: 2024/10/01 18:02:25 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **pile_a)
{
	t_list	*temp;

	if (!(*pile_a) || !(*pile_a)->next)
		return ;
	temp = (*pile_a)->next;       // on stock le 2nd noeud
	(*pile_a)->next = temp->next; // le 1er noeud pointe vers le 3e (ou NULL)
	temp->next = (*pile_a);// le 2e noeud devient le 1er noeud en pointant vers l'ancien premier
	(*pile_a) = temp;             // le 2e deient le 1er
	ft_printf("sa\n");
}

void	swap_b(t_list **pile_b)
{
	t_list	*temp;

	if (!(*pile_b) || !(*pile_b)->next)
		return ;
	temp = (*pile_b)->next;       // on stock le 2nd noeud
	(*pile_b)->next = temp->next; // le 1er noeud pointe vers le 3e (ou NULL)
	temp->next = (*pile_b);// le 2e noeud devient le 1er noeud en pointant vers l'ancien premier
	(*pile_b) = temp;             // le 2e deient le 1er
	ft_printf("sb\n");
}

void	swap_ss(t_list **pile_a, t_list **pile_b)
{
	swap_a(pile_a);
	swap_b(pile_b);
	ft_printf("ss\n");
}
