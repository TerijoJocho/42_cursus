/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:11:25 by daavril           #+#    #+#             */
/*   Updated: 2024/10/15 19:17:40 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Lib_ft/libft/libft.h"
# include "Lib_ft/printf/ft_printf.h"
# include <unistd.h>

/*PILE*/
typedef struct s_data
{
	int				content;
	int				index;
	struct s_data	*next;
}					t_data;

void				error_mes(char *str);
void				free_all(char **tab, t_data **pile_a, t_data **pile_b,
						int argc);
void				init_lst(char *argv, t_data **pile_a);
void				swap_a(t_data **pile_a, int flag);
void				swap_b(t_data **pile_b, int flag);
void				swap_ss(t_data **pile_a, t_data **pile_b);
void				push_b(t_data **pile_a, t_data **pile_b);
void				push_a(t_data **pile_a, t_data **pile_b);
void				rotate_a(t_data **pile_a, int flag);
void				rotate_b(t_data **pile_b, int flag);
void				rotate_rr(t_data **pile_a, t_data **pile_b);
void				rrotate_a(t_data **pile_a, int flag);
void				rrotate_b(t_data **pile_b, int flag);
void				rrotate_rr(t_data **pile_a, t_data **pile_b);
void				push_swap(t_data **pile_a, t_data **pile_b);

void				find_the_cheapest(t_data **pile_a, t_data **pile_b);

#endif
