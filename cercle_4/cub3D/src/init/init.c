/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:39:01 by daavril           #+#    #+#             */
/*   Updated: 2025/05/19 18:03:31 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_init_player_part_two(t_game *game)
{
	if (game->p->p_dir == 'E')
	{
		game->p->dir_x = 1;
		game->p->dir_y = 0;
		game->p->plane_x = 0;
		game->p->plane_y = 0.66;
	}
	else if (game->p->p_dir == 'W')
	{
		game->p->dir_x = -1;
		game->p->dir_y = 0;
		game->p->plane_x = 0;
		game->p->plane_y = -0.66;
	}
}

/**
 * @brief   Init the structure p for the raycasting
 *
 * @param   game struct of the game
 *
 * @return
 */
void	ft_init_splayer(t_game *game)
{
	if (game->p->p_dir == 'N')
	{
		game->p->dir_x = 0;
		game->p->dir_y = -1;
		game->p->plane_x = 0.66;
		game->p->plane_y = 0;
	}
	else if (game->p->p_dir == 'S')
	{
		game->p->dir_x = 0;
		game->p->dir_y = 1;
		game->p->plane_x = -0.66;
		game->p->plane_y = 0;
	}
	else
		ft_init_player_part_two(game);
}

/**
 * @brief   Initalize the structure game
 *
 * @param   argv Name of the file in the command line
 * @param   game the struct to init
 * @return  0 if everything's good or 1 if there's an error
 */
int	ft_init_game(t_game *game, char *argv)
{
	game->file_name = argv;
	game->file_tab = NULL;
	game->map = NULL;
	game->NO = NULL;
	game->SO = NULL;
	game->WE = NULL;
	game->EA = NULL;
	game->F = NULL;
	game->C = NULL;
	game->minimap = malloc(sizeof(t_minimap));
	if (!game->minimap)
		return (printf("error: malloc minimap failed\n"), 1);
	game->p = malloc(sizeof(t_player));
	if (!game->p)
		return (printf("error: malloc player failed\n"), 1);
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		return (printf("error: malloc ray failed\n"), 1);
	game->p->p_dir = 0;
	game->p->p_x = -1;
	game->p->p_y = -1;
	return (0);
}
