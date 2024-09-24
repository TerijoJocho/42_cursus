/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:13:29 by daavril           #+#    #+#             */
/*   Updated: 2024/09/24 16:27:59 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_on_map(char	elem, t_game *game, int x, int y)
{
	if (elem == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor_xpm, x, y);
	else if (elem == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall_xpm, x, y);
	else if (elem == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->charac_xpm, x, y);
	else if (elem == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->coins_xpm, x, y);
	else if (elem == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_xpm, x, y);
}

void	*take_img(void *file, int *x, int *y, t_game *game)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx_ptr, file, x, y);
	if (!img)
		ft_printf("Failed to load image\n");
	return (img);
}

void	init_img(t_game *game)
{
	int	img_x;
	int	img_y;

	img_x = game->map.img_size.x;
	img_y = game->map.img_size.y;
	game->floor_xpm = take_img("/home/daavril/so_long/so_l/icon_asset/floor.xpm", &game->map.map_size.x, &game->map.map_size.y, game);
	game->wall_xpm = take_img("/home/daavril/so_long/so_l/icon_asset/wall.xpm", &game->map.img_size.x, &game->map.img_size.y, game);
	game->coins_xpm = take_img("/home/daavril/so_long/so_l/icon_asset/fruit.xpm", &game->map.map_size.x, &game->map.map_size.y, game);
	game->charac_xpm = take_img("/home/daavril/so_long/so_l/icon_asset/knight.xpm", &game->map.map_size.x, &game->map.map_size.y, game);
	game->exit_xpm = take_img("/home/daavril/so_long/so_l/icon_asset/exit.xpm", &game->map.map_size.x, &game->map.map_size.y, game);
	game->charac_exit_xpm = take_img("/home/daavril/so_long/so_l/icon_asset/charac_exit.xpm", &game->map.map_size.x, &game->map.map_size.y, game);
}

void	update(int	*map_x, int *x_pixel, int *map_width)
{
	(*map_x)++;
	(*x_pixel) +=32;
	(*map_width)--;
}

void	render_map(t_game *game)
{
	int	x_pixel;
	int	y_pixel;
	int	map_x;
	int	map_y;
	int	map_width;
	int	map_height;

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
