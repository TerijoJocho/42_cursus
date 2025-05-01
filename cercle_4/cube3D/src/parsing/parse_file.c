

#include "../includes/cube3d.h"

int	ft_check_void(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_map(char *line)
{
	char	*str;

	str = ft_strtrim(line, " \t\n");
	if (!ft_check_void(str))
	{
		free(str);
		return (1);
	}
	if (!ft_strncmp(str, "F", 1) || !ft_strncmp(str, "C", 1) || !ft_strncmp(str, "NO", 2)
		|| !ft_strncmp(str, "SO", 2) || !ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2))
	{
		free(str);
		return (1);
	}
	free(str);
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
	int	i;

	i = 0;
	while(game->file_tab[i])
	{
		while(!ft_check_void(game->file_tab[i]))
			i++;
		if (!ft_is_map(game->file_tab[i]))
			break ;
		i++;
	}
	if (ft_check_texture(game, i))
		return (1);
	if (ft_check_colors(game, i))
		return (1);
	if (ft_check_map(game, i))
		return (1);
	return (0);
}
