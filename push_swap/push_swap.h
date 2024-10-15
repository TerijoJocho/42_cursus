/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:11:25 by daavril           #+#    #+#             */
/*   Updated: 2024/10/15 15:04:12 by daavril          ###   ########.fr       */
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

void	error_mes(char *str);
void	free_all(char **tab, t_list **pile_a, t_list **pile_b, int argc);
void	init_lst(char *argv, t_list **pile_a);
void	swap_a(t_list **pile_a, int flag);
void	swap_b(t_list **pile_b, int flag);
void	swap_ss(t_list **pile_a, t_list **pile_b);
void	push_b(t_list **pile_a, t_list **pile_b);
void	push_a(t_list **pile_a, t_list **pile_b);
void	rotate_a(t_list **pile_a, int flag);
void	rotate_b(t_list **pile_b, int flag);
void	rotate_rr(t_list **pile_a, t_list **pile_b);
void	rrotate_a(t_list **pile_a, int flag);
void	rrotate_b(t_list **pile_b, int flag);
void	rrotate_rr(t_list **pile_a, t_list **pile_b);
void	push_swap(t_list **pile_a, t_list **pile_b);

void	find_the_cheapest(t_list **pile_a, t_list **pile_b);


#endif
