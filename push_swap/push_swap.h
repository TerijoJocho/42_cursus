/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:11:25 by daavril           #+#    #+#             */
/*   Updated: 2024/10/01 18:01:14 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include "Lib_ft/printf/ft_printf.h"
#include "Lib_ft/libft/libft.h"

/*PILE*/
typedef struct s_data
{
	int	current;
	void *next;
}t_data;

void	init_lst(char *data, t_list *pile_a);
void	swap_a(t_list **pile_a);
void	swap_b(t_list **pile_b);
void	swap_ss(t_list **pile_a, t_list **pile_b);
void	push_b(t_list **pile_a, t_list **pile_b);
void	push_a(t_list **pile_a, t_list **pile_b);

#endif
