/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:13:29 by daavril           #+#    #+#             */
/*   Updated: 2024/10/14 16:03:02 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_on_map(char elem, t_game *game, int x, int y)
{
	if (elem == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->f, x, y);
	else if (elem == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->w, x, y);
	else if (elem == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->p, x, y);
	else if (elem == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->c, x, y);
	else if (elem == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->e, x, y);
}

void	*take_img(void *file, int *x, int *y, t_game *game)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx_ptr, file, x, y);
	if (img == NULL)
		error_message("Failed to load image\n", game, 1);
	return (img);
}

void	init_img(t_game *game)
{
	game->f = take_img("/home/daavril/42_cursus/so_long/icon_asset/f.xpm",
			&game->map.img_size.x, &game->map.img_size.y, game);
	game->w = take_img("/home/daavril/42_cursus/so_long/icon_asset/w.xpm",
			&game->map.img_size.x, &game->map.img_size.y, game);
	game->c = take_img("/home/daavril/42_cursus/so_long/icon_asset/c.xpm",
			&game->map.img_size.x, &game->map.img_size.y, game);
	game->p = take_img("/home/daavril/42_cursus/so_long/icon_asset/p.xpm",
			&game->map.img_size.x, &game->map.img_size.y, game);
	game->e = take_img("/home/daavril/42_cursus/so_long/icon_asset/e.xpm",
			&game->map.img_size.x, &game->map.img_size.y, game);
	if (game->e == NULL || game->w == NULL || game->c == NULL || game->p == NULL
		|| game->f == NULL)
		error_message("Failed to init image.\n", game, 1);
}

void	update(int *map_x, int *x_pixel, int *map_width)
{
	(*map_x)++;
	(*x_pixel) += 32;
	(*map_width)--;
}

void	render_map(t_game *game, int map_width, int map_height)
{
	int	x_pixel;
	int	y_pixel;
	int	map_x;
	int	map_y;

	map_height = game->map.map_size.y;
	y_pixel = 0;
	map_y = 0;
	init_img(game);
	while (map_height > 0)
	{
		x_pixel = 0;
		map_x = 0;
		map_width = game->map.map_size.x;
		while (map_width > 0)
		{
			put_on_map(game->map.grille[map_y][map_x], game, x_pixel, y_pixel);
			update(&map_x, &x_pixel, &map_width);
		}
		map_y++;
		y_pixel += 32;
		map_height--;
	}
}
