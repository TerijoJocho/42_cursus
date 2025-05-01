/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:00:47 by daavril           #+#    #+#             */
/*   Updated: 2025/05/01 16:52:13 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*renvoie la map qu'on a dans le file en plus d'enregistrer la map dans la game*/
char	**ft_dup_map(char	**tab)
{
	int	i;
	char	**res;

	i = 0;
	while (tab[i])
		i++;
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		tab[i] = ft_strtrim(tab[i], "\n");
		res[i] = ft_strdup(tab[i]);
		if (!res[i])
		{
			while (i--)
				free(res[i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

int	ft_get_maplen(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	len = 0;
	max = 0;
	while(map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max )
			max = len;
		i++;
	}
	return (max);
}

int	ft_rectangularize(char **map, int max_len, int i, int len)
{
	int	j;
	char	*nl;
	char	*tmp;

	j = 0;
	while(map[i])
	{
		tmp = ft_strtrim(map[i], " ");
		if (!tmp)
			return (1);
		len = ft_strlen(map[i]);
		if (len <= max_len)
		{
			nl = malloc(sizeof(char ) * (max_len + 1));
			if (!nl)
				return(free(tmp), 1);
			j = 0;
			while(tmp[j])
			{
				nl[j] = tmp[j];
				if (nl[j] == ' ')
					nl[j] = 'x';
				j++;
			}
			while (j < max_len)
				nl[j++] = 'x';
			nl[j] = '\0';
			free(map[i]);
			free(tmp);
			map[i] = nl;
		}
		i++;
	}
	return (0);
}

int	ft_get_player(char **map, t_game *game, int i, int count)
{
	int	j;

	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' 
				|| map[i][j] == 'E'))
			{
				if (count == 0)
				{
					(game->p->p_x = i, game->p->p_y = j);
					game->p->p_dir = map[i][j];
				}
				count++;
			}
			j++;
		}
		i++;
	}
	if (!game->p->p_dir || count != 1)
		return (1);
	return (0);
}

int	ft_check_map(t_game *game, int i)
{
	char	**cpy;
	int	len;

	cpy = ft_dup_map(&game->file_tab[i]);
	game->map = ft_dup_map(&game->file_tab[i]);
	if (!cpy || !*cpy)
		return(printf("error: cannot dup map\n"), ft_clean_tab(cpy), 1);
	len = ft_get_maplen(cpy);
	if (ft_rectangularize(cpy, len, 0, 0))
		return (printf("error: cannot rectangularize map\n"), ft_clean_tab(cpy), 1);
	if (ft_get_player(cpy, game, 0, 0))
		return (printf("error: cannot get player position\n"), ft_clean_tab(cpy), 1);

	/*test*/
	int j =0;
	while (cpy[j])
	{
		printf("line=   %s\n", cpy[j]);
		j++;
	}
	/*----*/
	ft_clean_tab(cpy);
	return (0);
}

// int	is_out(int x, int y, int size_x, int size_y)
// {
// 	return (x < 0 || x >= size_x || y < 0 || y >= size_y);
// }

// int	to_find(char *str, char c)
// {
// 	while (*str)
// 	{
// 		if (*str == c)
// 			return (1);
// 		str++;
// 	}
// 	return (0);
// }

// int	floo_fill(char **map_clone, t_vector pos, t_vector map_size, t_game *game)
// {
// 	int		elements;
// 	char	*str;

// 	str = "P0C";
// 	if (is_out(pos.x, pos.y, map_size.x, map_size.y) || !to_find(str,
// 			map_clone[pos.y][pos.x]))
// 		return (0);
// 	elements = 0;
// 	if (map_clone[pos.y][pos.x] == 'C' || map_clone[pos.y][pos.x] == 'P')
// 		elements = 1;
// 	map_clone[pos.y][pos.x] = 'X';
// 	elements += floo_fill(map_clone, (t_vector){pos.x - 1, pos.y}, map_size,
// 			game);
// 	elements += floo_fill(map_clone, (t_vector){pos.x + 1, pos.y}, map_size,
// 			game);
// 	elements += floo_fill(map_clone, (t_vector){pos.x, pos.y - 1}, map_size,
// 			game);
// 	elements += floo_fill(map_clone, (t_vector){pos.x, pos.y + 1}, map_size,
// 			game);
// 	return (elements);
// }

// void	map_playable(t_game *game)
// {
// 	int	pec_nb;
// 	int	pc_nb;

// 	game->map.map_size.y = game->map.rows;
// 	game->map.map_size.x = game->map.columns;
// 	pc_nb = floo_fill(game->map.grille_clone_2, game->map.player,
// 			game->map.map_size, game);
// 	if (pc_nb == (game->map.elements - 1))
// 	{
// 		pec_nb = flood_fill(game->map.grille_clone, game->map.player,
// 				game->map.map_size, game);
// 		if (pec_nb != game->map.elements)
// 			error_message("Map is not playable\n", game, 1);
// 	}
// 	else
// 		error_message("Map is not playable\n", game, 1);
// }
