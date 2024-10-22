/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_more.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:02:05 by daavril           #+#    #+#             */
/*   Updated: 2024/10/22 15:44:07 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list **pile)
{
	t_list	*cu;

	if (!pile ||!(*pile) || !(*pile)->next)
		return (1);
	cu = (*pile);
	while ((int)(__intptr_t)cu->content < (int)(__intptr_t)cu->next->content)
	{
		if (cu->next->next == NULL)
			return (1);
		cu = cu->next;
	}
	return (0);
}

void	push_next(t_list **a, t_list **b)
{
	int		half;
	t_list	*t;

	t = NULL;
	while (*b)
	{
		t = find_max(b);
		half = find_half(b, (int)(__intptr_t)t->content,
				(ft_lstsize(*b) / 2));
		while ((int)(__intptr_t)(*b)->content != (int)(__intptr_t)t->content)
		{
			if (half == 1)
				rotate_b(b, 0);
			else
				rrotate_b(b, 0);
		}
		push_a(a, b);
	}
}

void	ps_more(t_list **pile_a, t_list **pile_b, int *start, int *end)
{
	int	len;

	len = ft_lstsize(*pile_a);
	init_index(pile_a, len);
	while (*pile_a)
	{
		if ((*pile_a)->index <= (*start))
		{
			push_b(pile_a, pile_b);
			rotate_b(pile_b, 0);
			(*start)++;
			(*end)++;
		}
		else if ((*pile_a)->index > (*start) && (*pile_a)->index < (*end))
		{
			push_b(pile_a, pile_b);
			(*start)++;
			(*end)++;
		}
		else if ((*pile_a)->index >= (*end))
			rotate_a(pile_a, 0);
	}
	push_next(pile_a, pile_b);
}
