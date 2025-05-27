/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:19:38 by aistierl          #+#    #+#             */
/*   Updated: 2025/05/21 14:47:34 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_move_player_right_bonus(t_game *game)
{
	if (game->map[(int)(game->p->p_y + game->p->plane_y
			* 0.4)][(int)(game->p->p_x + game->p->plane_x * 0.5)] == '1')
		return ;
	game->p->p_x += game->p->plane_x * 0.1;
	game->p->p_y += game->p->plane_y * 0.1;
}

void	ft_move_player_left_bonus(t_game *game)
{
	if (game->map[(int)(game->p->p_y - game->p->plane_y
			* 0.4)][(int)(game->p->p_x - game->p->plane_x * 0.5)] == '1')
		return ;
	game->p->p_x -= game->p->plane_x * 0.1;
	game->p->p_y -= game->p->plane_y * 0.1;
}

void	ft_move_player_forward_bonus(t_game *game)
{
	if (game->map[(int)(game->p->p_y + game->p->dir_y * 0.4)][(int)(game->p->p_x
			+ game->p->dir_x * 0.5)] == '1')
		return ;
	game->p->p_x += game->p->dir_x * 0.1;
	game->p->p_y += game->p->dir_y * 0.1;
}

void	ft_move_player_backward_bonus(t_game *game)
{
	if (game->map[(int)(game->p->p_y - game->p->dir_y * 0.4)][(int)(game->p->p_x
			- game->p->dir_x * 0.5)] == '1')
		return ;
	game->p->p_x -= game->p->dir_x * 0.1;
	game->p->p_y -= game->p->dir_y * 0.1;
}
