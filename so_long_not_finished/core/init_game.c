/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:40:16 by daavril           #+#    #+#             */
/*   Updated: 2024/09/24 15:50:32 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_check(t_game *game)
{
	map_exist(game);
	map_rectangular(game);
	init_var(game);
	map_check_wall(game);
	map_count_PEC(game);
	map_check_PEC(game);
}

void	init_game(t_game *game, char *file_map)
{
	get_map(game, file_map);
	map_check(game);
	map_playable(game);
	init_window(game);
	if (!game->win_ptr || !game->mlx_ptr)
	{
		ft_printf("Error: Window or MLX pointer not initialized.\n");
		return;
	}
	render_map(game);
	mlx_key_hook(game->win_ptr, &on_keypress, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, game);
	mlx_loop(game->mlx_ptr);
}
