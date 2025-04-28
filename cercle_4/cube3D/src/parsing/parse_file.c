

#include "../includes/cube3d.h"

int	ft_is_xpm(char *file)
{
	char	*str;

	while (*file == ' ')
		file++;
	str = ft_strrchr(file, '.');
	if (!str)
		return (1);
	if (ft_strncmp(str, ".xpm", 5))
		return (1);
	return (0);
}

int	ft_check_texture(t_game *game)
{
	int		i;
	char	*file;

	i = 0;
	while (game->file_tab[i] && i < 5)
	{
		if (!ft_strncmp(game->file_tab[i], "NO", 2)
			|| !ft_strncmp(game->file_tab[i], "SO", 2)
			|| !ft_strncmp(game->file_tab[i], "WE", 2)
			|| !ft_strncmp(game->file_tab[i], "EA", 2))
		{
			file = ft_strtrim(game->file_tab[i] + 2, " \n");
			if (!file)
				return (printf("error: malloc fail\n"), 1);
			if (ft_is_xpm(file))
				return (printf("error: %s is not a .xpm file\n", file),
					free(file), 1);
			if (access(file, F_OK) == -1)
				return (printf("error: %s doesn't exist\n", file), free(file),
					1);
			free(file);
		}
		i++;
	}
	return (0);
}

/**
 * @brief   [Résume très court de ce que fait la fonction.]
 *
 * @param   [nom_du_param] [Description rapide du paramètre.]
 * @param   [autre_param]  [S'il y a plusieurs paramètres.]
 *
 * @return  [Ce que la fonction retourne, dans quel cas.]
 */
int	ft_parse_file(t_game *game)
{
	ft_check_texture(game);
	// ft_check_colors(game->file_tab);
	// ft_check_map(game->file_tab);
	return (0);
}
