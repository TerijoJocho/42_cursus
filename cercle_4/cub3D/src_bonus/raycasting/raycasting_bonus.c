/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:12:00 by daavril           #+#    #+#             */
/*   Updated: 2025/05/23 16:54:00 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

/**
 * @brief
 *
 * @param   game struct of the game
 *
 * @return
 */
void	ft_get_step_and_side_dist(t_game *game)
{
	t_player	*p;
	t_ray		*ray;

	p = game->p;
	ray = game->ray;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (p->p_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - p->p_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (p->p_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - p->p_y) * ray->delta_dist_y;
	}
}

/**
 * @brief   Make the ray go forward until it touches a wall
 *
 * @param   game struct of the game
 *
 * @return
 */
void	ft_dda(t_game *game, int hit)
{
	t_ray	*ray;

	ray = game->ray;
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (!game->map || ray->map_x < 0 || ray->map_y < 0
			|| ray->map_y > game->m_line || !game->map[ray->map_y][0]
			|| !game->map[0][ray->map_x] || !game->map[ray->map_y][ray->map_x])
			ft_clean(game);
		if (game->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}

/**
 * @brief
 *
 * @param   game struct of the game
 *
 * @return
 */
void	ft_compute_wall_height(t_game *game)
{
	t_player	*player;
	t_ray		*ray;

	player = game->p;
	ray = game->ray;
	if (ray->side == 0)
		ray->wall_dist = (ray->map_x - player->p_x + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x;
	else
		ray->wall_dist = (ray->map_y - player->p_y + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->p_y + ray->wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = player->p_x + ray->wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	ft_display_slice(t_game *game, int x)
{
	int			y;
	int			tex_x;
	int			tex_y;
	double		step;
	double		pos;

	tex_x = (int)(game->ray->wall_x * (double)TEXTURE_WIDTH);
	if ((game->ray->side == 0 && game->ray->ray_dir_x < 0)
		|| (game->ray->ray_dir_y > 0 && game->ray->side == 1))
		tex_x = TEXTURE_WIDTH - tex_x - 1;
	step = 1.0 * TEXTURE_HEIGHT / game->ray->line_height;
	pos = (game->ray->draw_start - WIN_HEIGHT / 2 + game->ray->line_height / 2)
		* step;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y >= game->ray->draw_start && y <= game->ray->draw_end)
		{
			tex_y = (int)pos & (TEXTURE_HEIGHT - 1);
			pos += step;
		}
		game->img->frm->frame_addr[y * (game->img->frm->size_line / 4)
			+ x] = ft_what_color(game, y, tex_x, tex_y);
		y++;
	}
}

/**
 * @brief   Raycasting engine
 *
 * @param   game struct of the game
 *
 * @return
 */
int	ft_raycasting(t_game *game)
{
	int	x;

	x = 0;
	mlx_destroy_image(game->mlx, game->img->frm->frame);
	game->img->frm->frame = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img->frm->frame)
		return (printf("error: mlx_new_image failed\n"), 1);
	game->img->frm->frame_addr = (int *)mlx_get_data_addr(game->img->frm->frame,
			&game->img->frm->bits_per_pixel, &game->img->frm->size_line,
			&game->img->frm->endian);
	if (!game->img->frm->frame_addr)
		return (printf("error: mlx_get_data_addr failed\n"), 1);
	while (x < WIN_WIDTH)
	{
		ft_get_ray_dir(game, x);
		ft_get_delta_dist(game);
		ft_get_step_and_side_dist(game);
		ft_dda(game, 0);
		ft_compute_wall_height(game);
		ft_display_slice(game, x);
		x++;
	}
	ft_minimap(game);
	mlx_put_image_to_window(game->mlx, game->wdw, game->img->frm->frame, 0, 0);
	return (0);
}
