/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:28:20 by daavril           #+#    #+#             */
/*   Updated: 2024/10/14 12:45:05 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_exist(t_game *game)
{
	if (!game->map.grille[0] || !game->map.grille)
	{
		error_message("There is no map.\n", game, 1);
		exit(EXIT_FAILURE);
	}
}

void	map_rectangular(t_game *game)
{
	int	len;
	int	arg;
	int	line_len;

	len = ft_strlen(game->map.grille[0]);
	arg = 0;
	while (game->map.grille[arg])
	{
		line_len = ft_strlen(game->map.grille[arg]);
		if (line_len != len)
		{
			error_message("Map is not rectangular\n", game, 1);
			exit(EXIT_FAILURE);
		}
		arg++;
	}
}

void	map_check_wall(t_game *game)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	height = 0;
	width = ft_strlen(game->map.grille[0]);
	while (game->map.grille[height])
		height++;
	while (i < height)
	{
		if (game->map.grille[i][0] != '1' || game->map.grille[i][width
			- 1] != '1')
			error_message("Invalid map. Not expected parameter in wall.\n",
				game, 1);
		i++;
	}
	wall_1(game->map.grille[0], game);
	wall_1(game->map.grille[height - 1], game);
	game->map.rows = height;
	game->map.columns = width;
}

void	map_check_pec(t_game *game)
{
	game->map.elements = game->map.colectable + game->map.players
		+ game->map.exit;
	if (game->map.colectable == 0)
		error_message("Invalid map. There is no coins.", game, 1);
	else if (game->map.players != 1)
		error_message("Invalid map. There must be only one player.", game, 1);
	else if (game->map.exit != 1)
		error_message("Invalid map.There must be only one exit.", game, 1);
}
