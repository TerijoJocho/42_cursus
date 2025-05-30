/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:39:19 by daavril           #+#    #+#             */
/*   Updated: 2025/05/30 20:17:15 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	ft_final_check_texture(t_game *game)
{
	if (!game->no || !game->so || !game->we || !game->ea)
		return (printf("error: one or more textures are missing\n"), 1);
	return (0);
}

void	ff(char *f, char *f2, int fd)
{
	if (f)
		free(f);
	if (f2)
		free(f2);
	if (fd != -1)
		close(fd);
}

/**
 * @brief   add a new line to the array
 *
 * @param   lines  an array to save the lines of the file
 * @param   line  the new line to save in the array
 * @param   line_count  number of lines
 *
 * @return  the new array or NULL
 */
char	**add_line(char **lines, char *line, int line_count)
{
	int		i;
	char	**new_lines;

	i = 0;
	new_lines = malloc(sizeof(char *) * (line_count + 2));
	if (!new_lines)
		return (NULL);
	while (i < line_count)
	{
		new_lines[i] = lines[i];
		i++;
	}
	new_lines[line_count] = ft_strdup(line);
	if (!new_lines[line_count])
		return (NULL);
	new_lines[line_count + 1] = NULL;
	if (lines)
		free(lines);
	return (new_lines);
}

/**
 * @brief   Read the file and save its contents in an array
 *
 * @param   game struct of the game
 *
 * @return  0 when everything is good or 1 when there is an error
 */
int	ft_get_file(t_game *game)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(game->file_name, O_RDONLY);
	if (fd < 0)
		return (printf("error: .cub file not found\n"), 1);
	line = get_next_line(fd);
	while (line)
	{
		game->file_tab = add_line(game->file_tab, line, line_count);
		if (!game->file_tab)
			return (printf("error: malloc\n"), close(fd), 1);
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (line_count == 0)
		return (printf("error: empty .cub file\n"), 1);
	if (ft_parse_file(game))
		return (1);
	return (0);
}
