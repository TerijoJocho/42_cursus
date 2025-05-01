/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:47:48 by daavril           #+#    #+#             */
/*   Updated: 2025/05/01 14:27:50 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_save_colors(char *f, char *line, t_game *game)
{
	if (!ft_strncmp(line, "F", 1) && !game->F)
		game->F = ft_strdup(f);
	else if (!ft_strncmp(line, "C", 1) && !game->C)
		game->C = ft_strdup(f);
	else
		return (1);
	return (0);
}

int	ft_is_num(char *f)
{
	int	i;

	i = 0;
	while(f[i])
	{
		if((f[i] >= '0' && f[i] <= '9') || f[i] == ',')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_tab_len(char **tab)
{
	int	i;
	
	i = 0;
	while (tab[i])
		i++;
	if (i != 3)
		return (1);
	return (0);
}

int	ft_is_color(char *f)
{
	char **tab;
	int	i;
	int	num;
	
	tab = ft_split(f, ',');
	if (ft_is_num(f) || tab == NULL || ft_tab_len(tab))
		return (1);
	i = 0;
	while (tab[i])
	{
		num = ft_atoi(tab[i]);
		if (tab[i][0] == '0' && ft_strlen(tab[i]) > 1)
			return (1);
		if (num < 0 || num > 255)
			return (1);
		i++;
	}
	ft_clean_tab(tab);
	return (0);
}

int	ft_check_colors(t_game *game, int len)
{
	int		i;
	char	*f;

	i = 0;
	while (game->file_tab[i] && i < len)
	{
		if (!ft_strncmp(game->file_tab[i], "F", 1)
			|| !ft_strncmp(game->file_tab[i], "C", 1)
			)
		{
			f = ft_strtrim(game->file_tab[i] + 2, " \n");
			if (!f)
				return (printf("error: malloc fail\n"), free(f), 1);
			if (ft_is_color(f))
				return (printf("error: wrong colors\n"), free(f), 1);
			if (ft_save_colors(f, game->file_tab[i], game))
				return (printf("error: duplicate colors: %s\n",game->file_tab[i]), free(f), 1);
			free(f);
		}
		i++;
	}
	if (!game->F || !game->C)
		return (printf("error: one or more colors are missing\n"), 1);
	return (0);
}
