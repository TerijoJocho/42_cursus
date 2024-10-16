/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 23:15:23 by daavril           #+#    #+#             */
/*   Updated: 2024/10/16 16:04:09 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_next(t_data **pile_a, t_data **pile_b)
{
	int	half;
	t_data	*temp;
	
	temp = NULL;
	while (*pile_b)
	{
		temp = find_max(pile_b);
		half = find_half(pile_b, temp->content, (ft_lstsize(*pile_b)/2));
		while ((*pile_b)->content != temp->content)
		{
			if (half == 1)
				rotate_b(pile_b, 0);
			else
				rrotate_b(pile_b, 0);
		}
		push_a(pile_a, pile_b);
	}
}

void	ps_more(t_data **pile_a, t_data **pile_b, int *start, int *end, int len)
{
	init_index(pile_a, len);
	while (*pile_a)
	{
		if ((*pile_a)->index <= start)
		{
			push_b(pile_a, pile_b);
			rotate_b(pile_b, 0);
			start++;
			end++;
		}
		else if ((*pile_a)->index > start && (*pile_a)->index < end)
		{
			push_b(pile_a, pile_b);
			start++;
			end++;
		}
		else if ((*pile_a)->index >= end)
			rotate_a(pile_a, 0);
	}
	push_next(pile_a, pile_b);
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

void	push_swap(t_data **pile_a, t_data **pile_b)
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
		ps_more(pile_a, pile_b, &start, &end, len);
}
