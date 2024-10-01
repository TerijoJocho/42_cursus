/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:25:29 by daavril           #+#    #+#             */
/*   Updated: 2024/10/01 16:54:57 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_lst(char *argv, t_list *pile_a)
{
	static t_list	*temp;
	int	num;

	num = ft_atoi(argv);
	temp = ft_lstnew((void *)(__intptr_t)num);
	if (!temp)
		return ;
	ft_lstadd_back(&pile_a, temp);
}
