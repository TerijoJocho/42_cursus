/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:40:16 by daavril           #+#    #+#             */
/*   Updated: 2024/10/15 12:19:19 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_check(t_game *game)
{
	map_exist(game);
	map_rectangular(game);
	map_check_wall(game);
	map_count_pec(game);
	map_check_pec(game);
}

void	init_game(t_game *game, char *file_map)
{
	int	map_width;
	int	map_height;

	init_var(game);
	get_map(game, file_map);
	map_check(game);
	map_playable(game);
	init_window(game);
	if (!game->win_ptr || !game->mlx_ptr)
		error_message("Error: Window or MLX pointer not initialized.\n", game,
			1);
	map_width = 0;
	map_height = 0;
	render_map(game, map_width, map_height);
	mlx_key_hook(game->win_ptr, &on_keypress, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		game);
	mlx_loop(game->mlx_ptr);
}
