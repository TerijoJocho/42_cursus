/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:47:43 by daavril           #+#    #+#             */
/*   Updated: 2024/10/03 21:16:27 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_list **pile_a, int flag)
{
	t_list	*second_last;
	t_list	*last;

	if (!(*pile_a) || !(*pile_a)->next)
		return ;
	second_last = NULL;
	last = *pile_a;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *pile_a;
	*pile_a = last;
	second_last->next = NULL;
	if (flag == 0)
		ft_printf("rra\n");
}

void	rrotate_b(t_list **pile_b, int flag)
{
	t_list	*second_last;
	t_list	*last;

	if (!(*pile_b) || !(*pile_b)->next)
		return ;
	second_last = NULL;
	last = *pile_b;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *pile_b;
	*pile_b = last;
	second_last->next = NULL;
	if (flag == 0)
		ft_printf("rrb\n");
}

void	rrotate_rr(t_list **pile_a, t_list **pile_b)
{
	int	flag;

	flag = 1;
	rrotate_a(pile_a, flag);
	rrotate_b(pile_b, flag);
	ft_printf("rrr\n");
}
