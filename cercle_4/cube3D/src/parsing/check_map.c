/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:00:47 by daavril           #+#    #+#             */
/*   Updated: 2025/05/04 17:52:42 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/**
 * @brief   Save the map in the game struct
 *
 * @param   tab the remaining array of the file game
 *
 * @return  the map in an array
 */
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

/**
 * @brief   Get the max lenght of the map
 *
 * @param   map a copy of the map
 *
 * @return  the longest line of the map
 */
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

/**
 * @brief   Function to rectangularize the map
 *
 * @param   map a copy of the map
 * @param   max_len max lenght of the map
 * @param   i	the begining of the map
 * @param   len the le of each line of the map
 *
 * @return  0 when everything is ok or 1 when there's an error
 */
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

/**
 * @brief   Function to get the player position
 *
 * @param   map a copy of the map
 * @param   game struct of the game
 * @param   i	the begining of the map
 * @param   count param to verified if ther's inly one player
 *
 * @return  0 when everything is ok or 1 when there's an error
 */
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

/**
 * @brief   Check if the map is playable
 *
 * @param   map a copy of the map
 * @param   x	the position x of the player
 * @param   y	the position y of the player
 *
 * @return  0 when everything is ok or 1 when there's an error
 */
int	ft_flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[x] || y >= (int)ft_strlen(map[x]))
		return (1);
	if (map[x][y] == 'x')
		return (1);
	if (map[x][y] == '1' || map[x][y] == 'v')
		return (0);
	map[x][y] = 'v';
	if (ft_flood_fill(map, x + 1, y))
		return (1);
	if (ft_flood_fill(map, x, y + 1))
		return (1);
	if (ft_flood_fill(map, x - 1, y))
		return (1);
	if (ft_flood_fill(map, x, y - 1))
		return (1);
	return (0);
}

/**
 * @brief   Check if there's a bad caract if the map
 *
 * @param   map the map to check
 * @return  0 when there is no bad caract or 1 when there's one
 */
int	ft_check_map_charset(char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != 'x')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief   Check if the map is good
 *
 * @param   game struct of the game
 * @param   i	 the start of the map
 *
 * @return  0 when everything is ok or 1 when there's an error
 */
int	ft_check_map(t_game *game, int i)
{
	char	**cpy;
	int	len;
	
	cpy = ft_dup_map(&game->file_tab[i]);
	if (!cpy || !*cpy)
		return(printf("error: cannot dup map\n"), ft_clean_tab(cpy), 1);
	game->map = ft_dup_map(&game->file_tab[i]);
	len = ft_get_maplen(cpy);
	if (ft_rectangularize(cpy, len, 0, 0))
		return (printf("error: cannot rectangularize map\n"), ft_clean_tab(cpy), 1);
	if (ft_check_map_charset(cpy))
		return (printf("error: map contains invalid characters\n"), ft_clean_tab(cpy), 1);
	if (ft_get_player(cpy, game, 0, 0))
		return (printf("error: cannot get player position\n"), ft_clean_tab(cpy), 1);
	if (ft_flood_fill(cpy, game->p->p_x, game->p->p_y))
		return (printf("error: map not playable\n"), ft_clean_tab(cpy), 1);
	/*test*/
	// int l = 0;
	// while(cpy[l])
	// {
	// 	printf("%s\n", cpy[l]);
	// 	l++;
	// }
	/*---*/
	ft_clean_tab(cpy);
	return (0);
}
