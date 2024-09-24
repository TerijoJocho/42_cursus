/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:08:28 by daavril           #+#    #+#             */
/*   Updated: 2024/09/20 14:18:01 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_strappend(char **str, char *s, t_game *game)
{
	char	*temp;

	temp = *str;
	*str = ft_strjoin(*str, s);
	free(temp);
	free(s);
	if (!(*str))
		error_message("Error. Can't save the map..", game);
}

void	get_map(t_game *game, char *fichier_map)
{
	char	*line;
	char	*temp_map;
	int		fd;
	char	c;

	fd = open(fichier_map, O_RDONLY);
	if (fd < 0)
		error_message("Error. Can not open the map.", game);
	temp_map = ft_strdup("");
	game->map.rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line == NULL)
			break;
		ft_strappend(&temp_map, line, game);
		line = get_next_line(fd);
	}
	c = '\n';
	game->map.grille = ft_split(temp_map, c);
	game->map.grille_clone = ft_split(temp_map, c);
	if (!game->map.grille || !game->map.grille)
		error_message("Error. Failed to split the map.", game);
	free(temp_map);
	close(fd);
}
