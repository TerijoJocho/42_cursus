/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:54:27 by daavril           #+#    #+#             */
/*   Updated: 2025/05/02 16:49:50 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_save_textures(char *f, char *line, t_game *game)
{
	if (!ft_strncmp(line, "NO", 2) && !game->NO)
		game->NO = ft_strdup(f);
	else if (!ft_strncmp(line, "SO", 2) && !game->SO)
		game->SO = ft_strdup(f);
	else if (!ft_strncmp(line, "WE", 2) && !game->WE)
		game->WE = ft_strdup(f);
	else if (!ft_strncmp(line, "EA", 2) && !game->EA)
		game->EA = ft_strdup(f);
	else
		return (1);
	return (0);
}

int	ft_is_xpm(char *file)
{
	char	*str;

	str = ft_strrchr(file, '.');
	if (!str)
		return (1);
	if (ft_strncmp(str, ".xpm", 5))
		return (1);
	return (0);
}

int	ft_is_texture(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (!ft_strncmp(line, "NO", 2)
			|| !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2)
			|| !ft_strncmp(line, "EA", 2))
	{
		return(1);
	}
	return (0);
}

char	*ft_get_texture_path(char *line, int flag)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (flag == 1)
	{
		line +=2;
		while (*line == ' ' || *line == '\t')
			line++;	
	}
	return (ft_strtrim(line, " \t\n"));
}

int	ft_check_texture(t_game *game, int len, int i)
{
	int		fd;
	char	*f;

	while (game->file_tab[i] && i < len)
	{
		if (ft_is_texture(game->file_tab[i]))
		{
			f = ft_get_texture_path(game->file_tab[i], 1);
			if (!f)
				return (printf("error: malloc fail\n"), 1);
			if (ft_is_xpm(f))
				return (printf("error: %s is not a .xpm file\n", f), free(f), 1);
			fd = open(f, O_RDONLY);
			if (fd == -1)
				return (printf("error: %s can not be opened\n", f), free(f), 1);
			if (ft_save_textures(f, ft_get_texture_path(game->file_tab[i], 0), game))
				return (printf("error: duplicate texture: %s", game->file_tab[i]), free(f), 1);
			free(f);
		}
		i++;
	}
	if (!game->NO || !game->SO || !game->WE || !game->EA)
		return (printf("error: one or more textures are missing\n"), 1);
	return (0);
}
