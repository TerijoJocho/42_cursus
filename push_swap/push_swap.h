/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:11:25 by daavril           #+#    #+#             */
/*   Updated: 2024/10/21 19:23:33 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Lib_ft/libft/libft.h"
# include "Lib_ft/printf/ft_printf.h"
# include <unistd.h>

/*PILE*/
// typedef struct s_data
// {
// 	int				content;
// 	int				index;
// 	struct s_data	*next;
// }					t_list;

void	error_mes(char *str, t_list **pile_a, char **tab);
void	free_all(char **tab, t_list **pile_a, t_list **pile_b, int argc);
void	init_lst(char *argv, t_list **pile_a, char **tab);
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

int		find_half(t_list **pile, int max, int len);
t_list	*find_max(t_list **pile);
t_list	*find_min(t_list **pile);
void	init_index(t_list **pile_a, int len);
void	index_zero(t_list **pile);
void	ps_more(t_list **pile_a, t_list **pile_b, int *start, int *end);
void	push_next(t_list **pile_a, t_list **pile_b);
int		sorted(t_list **pile);

#endif
