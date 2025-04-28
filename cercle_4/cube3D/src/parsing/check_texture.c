/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:54:27 by daavril           #+#    #+#             */
/*   Updated: 2025/04/28 17:23:51 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*f;

	i = 0;
	while (game->file_tab[i] && i < 4)
	{
		if (!ft_strncmp(game->file_tab[i], "NO", 2)
			|| !ft_strncmp(game->file_tab[i], "SO", 2)
			|| !ft_strncmp(game->file_tab[i], "WE", 2)
			|| !ft_strncmp(game->file_tab[i], "EA", 2))
		{
			f = ft_strtrim(game->file_tab[i] + 2, " \n");
			if (!f)
				return (printf("error: malloc fail\n"), 1);
			if (ft_is_xpm(f))
				return (printf("error: %s is not a .xpm file\n", f), free(f),
					1);
			if (access(f, F_OK) == -1)
				return (printf("error: %s doesn't exist\n", f), free(f), 1);
			free(f);
		}
		i++;
	}
	if (ft_check_void(game->file_tab[i]))
		return (printf("error: the .cub file is wrong(?)\n"), 1);
	return (0);
}
