/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:25:29 by daavril           #+#    #+#             */
/*   Updated: 2024/10/04 16:31:29 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_list(t_list *pile_a, int num)
{
	while (pile_a)
	{
		if ((int)(__intptr_t)pile_a->content == num)
			return (1);
		pile_a = pile_a->next;
	}
	return (0);
}

void	init_lst(char *argv, t_list **pile_a)
{
	static t_list	*temp;
	int				num;

	num = ft_atoi(argv);
	if (is_in_list(*pile_a, num))
		error_mes("There is a parameter twice.");
	temp = ft_lstnew((void *)(__intptr_t)num);
	if (!temp)
		error_mes("Failed tocreate new node.");
	ft_lstadd_back(pile_a, temp);
}

