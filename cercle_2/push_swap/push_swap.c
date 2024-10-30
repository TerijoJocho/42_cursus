/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:15:23 by daavril           #+#    #+#             */
/*   Updated: 2024/10/22 15:37:08 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_two(t_list **pile_a)
{
	int		first;
	int		last;
	t_list	*temp;

	temp = (*pile_a);
	first = (int)(__intptr_t)(temp->content);
	temp = temp->next;
	last = (int)(__intptr_t)(temp->content);
	if (first > last)
		swap_a(pile_a, 0);
}

void	ps_three(t_list **pile_a)
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
	if (first > mid && mid < last && last > first)
		swap_a(pile_a, 0);
	if (first > mid && mid < last && last < first)
		rotate_a(pile_a, 0);
	if (mid > last && mid > first && last < first)
		rrotate_a(pile_a, 0);
	if (first > mid && mid > last && first > last)
	{
		rotate_a(pile_a, 0);
		swap_a(pile_a, 0);
	}
	return ;
}

void	ps_four(t_list **pile_a, t_list **pile_b)
{
	t_list	*min;
	int		min_nbr;

	min = find_min(pile_a);
	min_nbr = (int)(__intptr_t)min->content;
	if ((int)(__intptr_t)(*pile_a)->content == min_nbr)
		push_b(pile_a, pile_b);
	else if ((int)(__intptr_t)(*pile_a)->next->content == min_nbr)
	{
		rotate_a(pile_a, 0);
		push_b(pile_a, pile_b);
	}
	else
	{
		while ((int)(__intptr_t)(*pile_a)->content != min_nbr)
			rrotate_a(pile_a, 0);
		push_b(pile_a, pile_b);
	}
	if (!sorted(pile_a))
		ps_three(pile_a);
	push_a(pile_a, pile_b);
}

void	ps_five(t_list **pile_a, t_list **pile_b)
{
	t_list	*min;
	int		min_nbr;

	min = find_min(pile_a);
	min_nbr = (int)(__intptr_t)min->content;
	if ((int)(__intptr_t)(*pile_a)->content == min_nbr)
		push_b(pile_a, pile_b);
	else if ((int)(__intptr_t)(*pile_a)->next->content == min_nbr)
	{
		rotate_a(pile_a, 0);
		push_b(pile_a, pile_b);
	}
	else
	{
		while ((int)(__intptr_t)(*pile_a)->content != min_nbr)
			rrotate_a(pile_a, 0);
		push_b(pile_a, pile_b);
	}
	if (!sorted(pile_a))
		ps_four(pile_a, pile_b);
	push_a(pile_a, pile_b);
}

void	push_swap(t_list **pile_a, t_list **pile_b)
{
	int	start;
	int	end;
	int	len;

	len = ft_lstsize(*pile_a);
	start = 0;
	end = 15;
	if (len == 1)
		return ;
	else if (len == 2)
		ps_two(pile_a);
	else if (len == 3)
		ps_three(pile_a);
	else if (len == 4)
		ps_four(pile_a, pile_b);
	else if (len == 5)
		ps_five(pile_a, pile_b);
	else if (len > 3)
		ps_more(pile_a, pile_b, &start, &end);
}
