/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:38:50 by daavril           #+#    #+#             */
/*   Updated: 2025/05/06 17:18:21 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/**
 * @brief   Free all visual associated data from file.cub or converted by MLX
 * @param   game the struct of the game
 * @return  none
 */
void	ft_free_visuals(t_game *game)
{
	if (!game)
		return ;
	if (game->NO != NULL)
		(free(game->NO), game->NO = NULL);
	if (game->SO != NULL)
		(free(game->SO), game->SO = NULL);
	if (game->WE != NULL)
		(free(game->WE), game->WE = NULL);
	if (game->EA != NULL)
		(free(game->EA), game->EA = NULL);
	if (game->F != NULL)
		(free(game->F), game->F = NULL);
	if (game->C != NULL)
		(free(game->C), game->C = NULL);
	if (game->img.floor_color != NULL)
		(free(game->img.floor_color), game->img.floor_color = NULL);
	if (game->img.ceiling_color != NULL)
		(free(game->img.ceiling_color), game->img.ceiling_color = NULL);
	mlx_destroy_image(game->mlx, game->img.north_wall_img);
	mlx_destroy_image(game->mlx, game->img.south_wall_img);
	mlx_destroy_image(game->mlx, game->img.east_wall_img);
	mlx_destroy_image(game->mlx, game->img.west_wall_img);
}

/**
 * @brief   Free all the alloc made during the program, at the end
 * @param   game the struct of the game
 * @return  0 because MLX requires it
 */
int	ft_cleanup_mess(t_game *game)
{
	// free (game->file_name) ???
	ft_free_visuals(game);
	free(game->p);
	ft_clean_tab(game->map);
	ft_clean_tab(game->file_tab);
	mlx_destroy_window(game->mlx, game->wdw);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
