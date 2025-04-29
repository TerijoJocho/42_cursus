

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
	if (ft_check_texture(game))
		return (1);
	if (ft_check_colors(game))
		return (1);
	if (ft_check_map(game))
		return (1);
	return (0);
}


/*parsing faux, il faudrait juste chercher les types d'element
ensuite enregistre leur valeurs dans la struct apres avoir verifier
s'ils sont bon
et aussi verifier qu'il existe un seul meme type a chaque fois
et enfin verifier la map*/
