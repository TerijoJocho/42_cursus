/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:47:48 by daavril           #+#    #+#             */
/*   Updated: 2025/04/29 12:01:57 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_check_colors(t_game *game)
{
	int		i;
	int		j;

	i = 5;
	while (game->file_tab[i] && ++i < 7)
	{
		if (!ft_strncmp(game->file_tab[i], "F", 1)
			|| !ft_strncmp(game->file_tab[i], "C", 1)
			)
		{
			j = 2;
			while (game->file_tab[i][j] && ft_strncmp(&game->file_tab[i][j], ",", 1))
			{
				if (ft_atoi(&game->file_tab[i][j]) < 0 && ft_atoi(&game->file_tab[i][j]) > 5)
					return (printf("error: bad colors\n"), 1);
				j++;
			}
		}
	}
	if (ft_check_void(game->file_tab[i]))
		return (printf("error: the .cub file is wrong(?)\n"), 1);
	return (0);
}
