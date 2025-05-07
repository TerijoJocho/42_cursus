/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:39:01 by daavril           #+#    #+#             */
/*   Updated: 2025/05/07 01:40:38 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/**
 * @brief   Init the structure player
 *
 * @param   game struct of the game
 *
 * @return
 */
 void    ft_init_splayer(t_game *game)
 {
	 if (game->player->p_dir == 'N')
	 {
		 game->player->dir_x = 0;
		 game->player->dir_y = -1;
		 game->player->plane_x = 0.66;
		 game->player->plane_y = 0;
	 }
	 else if (game->player->p_dir == 'S')
	 {
		 game->player->dir_x = 0;
		 game->player->dir_y = 1;
		 game->player->plane_x = -0.66;
		 game->player->plane_y = 0;
	 }
	 else if (game->player->p_dir == 'E')
	 {
		 game->player->dir_x = 1;
		 game->player->dir_y = 0;
		 game->player->plane_x = 0;
		 game->player->plane_y = 0.66;
	 }
	 else if (game->player->p_dir == 'W')
	 {
		 game->player->dir_x = -1;
		 game->player->dir_y = 0;
		 game->player->plane_x = 0;
		 game->player->plane_y = -0.66;
	 }
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
	game->p = malloc(sizeof(t_player));
	if (!game->p)
		return (printf("error: malloc player failed\n"), 1);
	game->p->p_dir = 0;
	game->p->p_x = -1;
	game->p->p_y = -1;
	return (0);
}
