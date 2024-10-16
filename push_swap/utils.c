/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:11 by daavril           #+#    #+#             */
/*   Updated: 2024/10/16 16:04:48 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_zero(t_data **pile)
{
	t_data	*temp;
	
	temp = *pile;
	while(temp)
	{
		temp->index = 0;
		temp = temp->next;
	}
}

void	init_index(t_data **pile_a, int len)
{
	t_data	*temp;
	t_data	*current;
	int	min;
	int	i;
	
	index_zero(pile_a);
	i = 1;
	while (len > 0)
	{
		min = INT32_MAX;
		current = *pile_a;
		while (current)
		{
			if (current->content < min && temp->index == 0)
			{
				min = current->content;
				temp = current;
			}
			current = current->next;
		}
		temp->index = i;
		i++;
		len--;
	}
}

t_data	*find_max(t_data **pile)
{
	t_data	*temp;
	t_data	*max_node;
	int		max;

	max = INT32_MIN;
	temp = *pile;
	max_node = NULL;
	while (temp)
	{
		if (temp->content > max)
		{
			max = temp->content;
			max_node = temp;
		}
		temp = temp->next;
	}
	return (max_node);
}

int		find_half(t_data **pile, int max, int len)
{
	t_data	*current;

	current = *pile;
	while (len > 0 && current)
	{
		if (current->content == max)
			return (1);
		current = current->next;
		len--;
	}
	return (0);
}