/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:47:48 by daavril           #+#    #+#             */
/*   Updated: 2025/04/29 13:56:29 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_is_color(char *f)
{
	char **tab;
	int	i;
	int	num;

	tab = ft_split(f, ',');
	if (tab == NULL)
		return (1);
	i = 0;
	while (tab[i])
	{
		num = ft_atoi(tab[i]);
		if (num < 0 || num > 255)
			return (1);
		i++;
	}
	ft_clean_tab(tab);
	return (0);
}

int	ft_check_colors(t_game *game)
{
	int		i;
	char	*f;

	i = 5;
	while (game->file_tab[i] && i < 7)
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
			free(f);
		}
		i++;
	}
	if (ft_check_void(game->file_tab[i]))
		return (printf("error: the .cub file is wrong(?)\n"), 1);
	return (0);
}
