/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:11 by daavril           #+#    #+#             */
/*   Updated: 2024/10/15 19:27:42 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_data **pile_a)
{
	t_data	*temp;
	t_data	*current;
	int	min;
	int	i;

	min = INT32_MAX;
	temp = pile_a;
	current = temp;
	i = 1;
	while (i <= ft_lstsize(temp))
	{
		if (temp->content < min && temp->index == 0)
		{
			min = temp->content;
			temp->index = i;
			current = temp;
		}
		temp = temp->next;
		i++;
	}
}
