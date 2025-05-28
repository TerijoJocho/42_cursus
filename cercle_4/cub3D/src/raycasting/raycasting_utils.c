/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:23:04 by daavril           #+#    #+#             */
/*   Updated: 2025/05/28 15:11:55 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	ft_rgb_to_int(int rgb_tab[3])
{
	return ((rgb_tab[0] << 16) | (rgb_tab[1] << 8) | (rgb_tab[2]));
}

int	ft_looking_where(t_game *game)
{
	if (game->ray->side == 0 && game->ray->ray_dir_x < 0)
		return (EAST);
	else if (game->ray->side == 0 && game->ray->ray_dir_x > 0)
		return (WEST);
	else if (game->ray->side == 1 && game->ray->ray_dir_y < 0)
		return (NORTH);
	return (SOUTH);
}

int	ft_what_color(t_game *game, int y, int tex_x, int tex_y)
{
	int			color;
	t_direction	dir;

	dir = ft_looking_where(game);
	if (y < game->ray->draw_start)
		color = ft_rgb_to_int(game->img->ceiling_color);
	else if (y <= game->ray->draw_end)
	{
		color = game->img->texture_buffer[dir][TEXTURE_WIDTH * tex_y + tex_x];
		if (dir == NORTH || dir == SOUTH)
			color = (color >> 1) & 0x7F7F7F;
	}
	else
		color = ft_rgb_to_int(game->img->floor_color);
	return (color);
}

/**
 * @brief   Get the direction of the ray
 *
 * @param   game struct of the game
 * @param   x    the pixel
 *
 * @return
 */
void	ft_get_ray_dir(t_game *game, int x)
{
	double	camera_x;

	game->ray->map_x = (int)game->p->p_x;
	game->ray->map_y = (int)game->p->p_y;
	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	game->ray->ray_dir_x = game->p->dir_x + game->p->plane_x * camera_x;
	game->ray->ray_dir_y = game->p->dir_y + game->p->plane_y * camera_x;
}

/**
 * @brief   Get the distance between each line with the ray at x pixel
 *
 * @param   game struct of the game
 *
 * @return
 */
void	ft_get_delta_dist(t_game *game)
{
	game->ray->delta_dist_x = fabs(1 / game->ray->ray_dir_x);
	game->ray->delta_dist_y = fabs(1 / game->ray->ray_dir_y);
}
