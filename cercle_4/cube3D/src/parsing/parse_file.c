

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
