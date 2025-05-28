/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:42:45 by daavril           #+#    #+#             */
/*   Updated: 2025/05/23 16:53:25 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

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
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != 'x')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

/**
 * @brief
 *
 * @param
 *
 * @return
 */
int	ft_fill_line(char **map, int i, int max_len, char *tmp)
{
	int		j;
	char	*nl;

	nl = malloc(sizeof(char) * (max_len + 1));
	if (!nl)
		return (free(tmp), 1);
	j = 0;
	while (tmp[j])
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
	return (0);
}

/**
 * @brief
 *
 * @param
 *
 * @return
 */
int	ft_find_map_bounds(t_game *game, int *start, int *end)
{
	int	i;

	i = 0;
	*start = -1;
	while (game->file_tab && game->file_tab[i])
	{
		while (!ft_check_void(game->file_tab[i]))
		{
			if (!game->file_tab[i + 1])
				return (printf("error: no map found\n"), 1);
			i++;
		}
		if (ft_is_map(game->file_tab[i]))
		{
			*start = i;
			break ;
		}
		i++;
	}
	if (*start == -1)
		return (printf("error: no map found\n"), 1);
	i = *start;
	while (game->file_tab[i] && !ft_is_line_empty(game->file_tab[i]))
		*end = i++;
	return (0);
}

/**
 * @brief
 *
 * @param
 *
 * @return
 */
int	ft_check_map_square(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (i == 0 || j == 0 || !map[i + 1] || !map[i][j + 1])
					return (1);
				if (map[i - 1][j] == 'x' || map[i + 1][j] == 'x' || map[i][j
					- 1] == 'x' || map[i][j + 1] == 'x')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
