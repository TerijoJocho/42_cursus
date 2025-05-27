/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:55:01 by aistierl          #+#    #+#             */
/*   Updated: 2025/05/21 14:31:18 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_rotate_player_left(t_game *game)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = game->p->dir_x;
	tmp_y = game->p->dir_y;
	game->p->dir_x = tmp_x * cos(-0.1) - tmp_y * sin(-0.1);
	game->p->dir_y = tmp_x * sin(-0.1) + tmp_y * cos(-0.1);
	tmp_x = game->p->plane_x;
	tmp_y = game->p->plane_y;
	game->p->plane_x = tmp_x * cos(-0.1) - tmp_y * sin(-0.1);
	game->p->plane_y = tmp_x * sin(-0.1) + tmp_y * cos(-0.1);
}

void	ft_rotate_player_right(t_game *game)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = game->p->dir_x;
	tmp_y = game->p->dir_y;
	game->p->dir_x = tmp_x * cos(0.1) - tmp_y * sin(0.1);
	game->p->dir_y = tmp_x * sin(0.1) + tmp_y * cos(0.1);
	tmp_x = game->p->plane_x;
	tmp_y = game->p->plane_y;
	game->p->plane_x = tmp_x * cos(0.1) - tmp_y * sin(0.1);
	game->p->plane_y = tmp_x * sin(0.1) + tmp_y * cos(0.1);
}
