/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:08:28 by daavril           #+#    #+#             */
/*   Updated: 2024/10/15 10:49:49 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_strappend(char **str, char *s, t_game *game)
{
	char	*temp;

	temp = *str;
	*str = ft_strjoin(*str, s);
	if (*str == NULL)
	{
		free(temp);
		free(s);
		error_message("Can't save the map..", game, 1);
	}
	free(temp);
	free(s);
}

void	get_map(t_game *game, char *fichier_map)
{
	char	*line;
	char	*temp_map;
	int		fd;

	fd = open(fichier_map, O_RDONLY);
	if (fd < 0)
		error_message("Can not open the map.\n", game, 1);
	temp_map = ft_strdup("");
	line = get_next_line(fd);
	if (temp_map == NULL || line == NULL)
		error_message("Failed to get first line.", game, 0);
	while (line)
	{
		ft_strappend(&temp_map, line, game);
		line = get_next_line(fd);
	}
	close(fd);
	game->map.grille = ft_split(temp_map, '\n');
	game->map.grille_clone = ft_split(temp_map, '\n');
	game->map.grille_clone_2 = ft_split(temp_map, '\n');
	if (!game->map.grille || !game->map.grille_clone
		|| !game->map.grille_clone_2)
		error_message("Failed to split the map.\n", game, 1);
	free(temp_map);
}
