/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:08:00 by daavril           #+#    #+#             */
/*   Updated: 2024/10/15 12:33:11 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_destroy(t_game *game)
{
	if (game->map.grille != NULL)
		error_message("", game, 0);
	else
		destroy(game);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_game *game)
{
	int	x;
	int	y;

	x = game->map.player.x;
	y = game->map.player.y;
	if (keysym == XK_Escape)
		game_over(game);
	if (keysym == XK_w && !is_wall(x, y - 1, game))
		move(x, y - 1, game);
	if (keysym == XK_a && !is_wall(x - 1, y, game))
		move(x - 1, y, game);
	if (keysym == XK_s && !is_wall(x, y + 1, game))
		move(x, y + 1, game);
	if (keysym == XK_d && !is_wall(x + 1, y, game))
		move(x + 1, y, game);
	return (0);
}

void	init_window(t_game *game)
{
	int	x;
	int	y;

	x = game->map.map_size.x;
	y = game->map.map_size.y;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_message("Failed to init mlx.\n", game, 1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, x * 32, y * 32, "GAME");
	if (!game->win_ptr)
		error_message("Failed to create a window\n", game, 1);
}
