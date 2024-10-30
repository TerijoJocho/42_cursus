/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_playable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:43:31 by daavril           #+#    #+#             */
/*   Updated: 2024/10/14 12:45:23 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_out(int x, int y, int size_x, int size_y)
{
	return (x < 0 || x >= size_x || y < 0 || y >= size_y);
}

int	to_find(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	floo_fill(char **map_clone, t_vector pos, t_vector map_size, t_game *game)
{
	int		elements;
	char	*str;

	str = "P0C";
	if (is_out(pos.x, pos.y, map_size.x, map_size.y) || !to_find(str,
			map_clone[pos.y][pos.x]))
		return (0);
	elements = 0;
	if (map_clone[pos.y][pos.x] == 'C' || map_clone[pos.y][pos.x] == 'P')
		elements = 1;
	map_clone[pos.y][pos.x] = 'X';
	elements += floo_fill(map_clone, (t_vector){pos.x - 1, pos.y}, map_size,
			game);
	elements += floo_fill(map_clone, (t_vector){pos.x + 1, pos.y}, map_size,
			game);
	elements += floo_fill(map_clone, (t_vector){pos.x, pos.y - 1}, map_size,
			game);
	elements += floo_fill(map_clone, (t_vector){pos.x, pos.y + 1}, map_size,
			game);
	return (elements);
}

int	flood_fill(char **map_clone, t_vector pos, t_vector map_size, t_game *game)
{
	int		elements;
	char	*str;

	str = "P0CE";
	if (is_out(pos.x, pos.y, map_size.x, map_size.y) || !to_find(str,
			map_clone[pos.y][pos.x]))
		return (0);
	elements = 0;
	if (map_clone[pos.y][pos.x] == 'P' || map_clone[pos.y][pos.x] == 'E'
		|| map_clone[pos.y][pos.x] == 'C')
		elements = 1;
	map_clone[pos.y][pos.x] = 'X';
	elements += flood_fill(map_clone, (t_vector){pos.x - 1, pos.y}, map_size,
			game);
	elements += flood_fill(map_clone, (t_vector){pos.x + 1, pos.y}, map_size,
			game);
	elements += flood_fill(map_clone, (t_vector){pos.x, pos.y - 1}, map_size,
			game);
	elements += flood_fill(map_clone, (t_vector){pos.x, pos.y + 1}, map_size,
			game);
	return (elements);
}

void	map_playable(t_game *game)
{
	int	pec_nb;
	int	pc_nb;

	game->map.map_size.y = game->map.rows;
	game->map.map_size.x = game->map.columns;
	pc_nb = floo_fill(game->map.grille_clone_2, game->map.player,
			game->map.map_size, game);
	if (pc_nb == (game->map.elements - 1))
	{
		pec_nb = flood_fill(game->map.grille_clone, game->map.player,
				game->map.map_size, game);
		if (pec_nb != game->map.elements)
			error_message("Map is not playable\n", game, 1);
	}
	else
		error_message("Map is not playable\n", game, 1);
}
