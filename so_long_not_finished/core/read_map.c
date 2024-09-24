/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:54:02 by daavril           #+#    #+#             */
/*   Updated: 2024/09/20 15:42:36 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Lib_ft/gnl/get_next_line.h"


char	**malloc_map(char **temp_map, int i)
{
	temp_map = malloc((i + 2) * sizeof(char *));
		if (!temp_map)
			return (NULL);
	return (temp_map);
}

void	ft_temp_map(char **temp_map, int i, char *line)
{
	temp_map[i] = line;
	temp_map[i + 1] = NULL;
}

char	**read_map(int fd)
{
	char	*line;
	char	**temp_map;
	char	**str_map;
	int		i;
	int		j;

	i = 0;
	str_map = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp_map = malloc_map(temp_map, i);
		j = 0;
		while (j < i)
		{
			temp_map[j] = str_map[j];
			j++;
		}
		ft_temp_map(temp_map, i, line);
		free(str_map);
		str_map = temp_map;
		line = get_next_line(fd);
		i++;
	}
	return (str_map);
}
