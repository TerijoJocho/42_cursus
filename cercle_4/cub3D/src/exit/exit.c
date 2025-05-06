/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:38:50 by daavril           #+#    #+#             */
/*   Updated: 2025/05/05 19:19:42 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/**
 * @brief   Function to free a tab **
 * @param   tab the array to free
 * @return  none
 */
void	ft_clean_tab(char **tab)
{
	int	i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/**
 * @brief   Free the textures of file.cub in the struct
 * @param   game the struct of the game
 * @return  none
 */
void	ft_free_textures_colors(t_game *game)
{
	if (!game)
		return ;
	if (game->NO != NULL)
		(free(game->NO), game->NO = NULL);
	if (game->SO != NULL)
		(free(game->SO), game->SO = NULL);
	if (game->WE != NULL)
		(free(game->WE), game->WE = NULL);
	if (game->EA != NULL)
		(free(game->EA), game->EA = NULL);
	if (game->F != NULL)
		(free(game->F), game->F = NULL);
	if (game->C != NULL)
		(free(game->C), game->C = NULL);
}

/**
 * @brief   Free all the alloc made during the program, at the end
 * @param   game the struct of the game
 * @return  none
 */
void	ft_clean(t_game *game)
{
	if (!game)
		return ;
	ft_free_textures_colors(game);
	ft_clean_tab(game->file_tab);
	ft_clean_tab(game->map);
	free(game->p);
	free(game);
}
