/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:32:34 by daavril           #+#    #+#             */
/*   Updated: 2024/10/14 14:41:31 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	wall_1(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
		{
			error_message("Invalid map. Not expected parameter in wall.", game,
				1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	init_var(t_game *game)
{
	game->map.rows = 0;
	game->map.players = 0;
	game->map.colectable = 0;
	game->map.exit = 0;
	game->map.img_size.y = 32;
	game->map.img_size.x = 32;
	game->moves = 0;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->c = NULL;
	game->p = NULL;
	game->e = NULL;
	game->f = NULL;
	game->map.grille = NULL;
	game->map.grille_clone = NULL;
	game->map.grille_clone_2 = NULL;
}

void	map_count_pec(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CPE01", game->map.grille[y][x]))
				error_message("Invalid map. Not expected parameter.", game, 1);
			else if (game->map.grille[y][x] == 'P')
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.grille[y][x] == 'C')
				game->map.colectable++;
			else if (game->map.grille[y][x] == 'E')
				game->map.exit++;
			x++;
		}
		y++;
	}
}
