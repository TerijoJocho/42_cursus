

#include "../includes/cube3d.h"

/**
 * @brief   add a new line to the array
 *
 * @param   lines  an array to save the lines of the file
 * @param   line  the line to save in the array
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
	new_lines[line_count + 1] = NULL;
	if (lines)
		free(lines);
	return (new_lines);
}

/**
 * @brief   Read the file to have an aray of the file's lines then parse it
 *
 * @param   game struct of the game
 *
 * @return  0 when everything is good or an error
 */
int	ft_get_file(t_game *game)
{
	int fd;
	char *line;
	int line_count;

	line_count = 0;
	fd = open(game->file_name, O_RDONLY);
	if (fd < 0)
		return (printf("error: .cub file not found\n"), 1);
	while ((line = get_next_line(fd)))
	{
		game->file_tab = add_line(game->file_tab, line, line_count);
		if (!game->file_tab)
			return (printf("error: malloc\n"));
		line_count++;
		free(line);
	}
	close(fd);
	if (line_count == 0)
		return (printf("error: empty .cub file\n"), 1);
	ft_parse_file(game);
	return (0);
}
