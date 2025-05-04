/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:47:48 by daavril           #+#    #+#             */
/*   Updated: 2025/05/04 17:40:30 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/**
 * @brief   Save the colors in the game struct
 *
 * @param   game struct of the game
 * @param   line a line in the file that is a color
 * @param   f	 the color to save
 *
 * @return  0 when everything is ok or 1 if no colors has been saved
 */
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

/**
 * @brief   Check if the string is a number
 *
 * @param   f string to check
 *
 * @return  0 if it is or 1 if it is not
 */
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

/**
 * @brief   Get the lenght of the colors array
 *
 * @param   tab the array
 *
 * @return  0 if the lenght is == 3 or 1 if it's not
 */
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

/**
 * @brief   Check if it is a color
 *
 * @param   f the string to check
 *
 * @return  0 when it is a color or 1 if it is not
 */
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

/**
 * @brief   Check if the the colors are good
 *
 * @param   game struct of the game
 * @param   len	 lenght of the file to check
 *
 * @return  0 when everything is ok or 1 when there's an error
 */
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
				return (printf("error: duplicate colors: %s",game->file_tab[i]), free(f), 1);
			free(f);
		}
		i++;
	}
	if (!game->F || !game->C)
		return (printf("error: one or more colors are missing\n"), 1);
	return (0);
}
