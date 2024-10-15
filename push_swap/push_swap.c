/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:15:23 by daavril           #+#    #+#             */
/*   Updated: 2024/10/15 19:16:02 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_two(t_data **pile_a)
{
	int	first;
	int	last;
	t_data	*temp;

	temp= (*pile_a);
	first = (int)(__intptr_t)(temp->content);
	temp = temp->next;
	last = (int)(__intptr_t)(temp->content);
	if (first > last)
		swap_a(pile_a, 0);
}

void	ps_three(t_data **pile_a)
{
	int	first;
	int	last;
	int	mid;

	first = (int)(__intptr_t)((*pile_a)->content);
	mid = (int)(__intptr_t)((*pile_a)->next->content);
	last = (int)(__intptr_t)((*pile_a)->next->next->content);
	if (mid > first && mid > last && last > first)
	{
		swap_a(pile_a, 0);
		rotate_a(pile_a, 0);
	}
	if (first>mid && mid<last && last>first)
		swap_a(pile_a, 0);
	if (first>mid && mid<last && last<first)
		rotate_a(pile_a, 0);
	if (mid > last && mid > first && last < first)
		rrotate_a(pile_a, 0);
	if (first>mid && mid>last && first>last)
	{
		rotate_a(pile_a, 0);
		swap_a(pile_a, 0);
	}
	return ;
}

void	ps_more(t_data **pile_a, t_data **pile_b)
{
	init_index(pile_a);
	push_b(pile_a,pile_b);
	push_b(pile_a,pile_b);
}

void	push_swap(t_data **pile_a, t_data **pile_b)
{
	int	len;

	len = ft_lstsize(*pile_a);
	if (len == 1)
		return ;
	else if (len == 2)
	{
		(void)pile_b;
		ps_two(pile_a);
	}
	else if (len == 3)
	{
		(void)pile_b;
		ps_three(pile_a);
	}
	else if (len > 3)
		ps_more(pile_a, pile_b);
}
