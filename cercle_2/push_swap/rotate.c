/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:33:41 by daavril           #+#    #+#             */
/*   Updated: 2024/10/03 21:18:04 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **pile_a, int flag)
{
	t_list	*temp;
	t_list	*last;

	if (!(*pile_a) || !(*pile_a)->next)
		return ;
	temp = *pile_a;
	*pile_a = (*pile_a)->next;
	temp->next = NULL;
	last = *pile_a;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (flag == 0)
		ft_printf("ra\n");
}

void	rotate_b(t_list **pile_b, int flag)
{
	t_list	*temp;
	t_list	*last;

	if (!(*pile_b) || !(*pile_b)->next)
		return ;
	temp = *pile_b;
	*pile_b = (*pile_b)->next;
	temp->next = NULL;
	last = *pile_b;
	while (last->next)
		last = last->next;
	last->next = temp;
	if (flag == 0)
		ft_printf("rb\n");
}

void	rotate_rr(t_list **pile_a, t_list **pile_b)
{
	int	flag;

	flag = 1;
	rotate_a(pile_a, flag);
	rotate_b(pile_b, flag);
	ft_printf("rr\n");
}
