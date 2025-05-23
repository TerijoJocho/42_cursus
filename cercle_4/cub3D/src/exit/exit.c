/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:38:50 by daavril           #+#    #+#             */
/*   Updated: 2025/05/19 18:53:24 by aistierl         ###   ########.fr       */
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
 * 			free all visual associated data from file.cub or converted by MLX
 * @param   game the struct of the game
 * @return  none
 */
void	ft_free_textures_colors(t_game *game)
{
	ft_clean_parse(game, 0);
	if (game->img->floor_color != NULL)
		(free(game->img->floor_color), game->img->floor_color = NULL);
	if (game->img->ceiling_color != NULL)
		(free(game->img->ceiling_color), game->img->ceiling_color = NULL);
	if (game->img->texture_img[NORTH])
		mlx_destroy_image(game->mlx, game->img->texture_img[NORTH]);
	if (game->img->texture_img[SOUTH])
		mlx_destroy_image(game->mlx, game->img->texture_img[SOUTH]);
	if (game->img->texture_img[EAST])
		mlx_destroy_image(game->mlx, game->img->texture_img[EAST]);
	if (game->img->texture_img[WEST])
		mlx_destroy_image(game->mlx, game->img->texture_img[WEST]);
	if (game->img->frm->frame)
		mlx_destroy_image(game->mlx, game->img->frm->frame);
}

void	ft_free_minimap(t_game *game)
{
	if (game->minimap)
		free(game->minimap);
	return ;
}

void	ft_clean_parse(t_game *game, int flag)
{
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
	ft_clean_tab(game->file_tab);
	ft_clean_tab(game->map);
	free(game->ray);
	free(game->p);
	if (flag == 1)
		exit(1);
}

/**
 * @brief   Free all the alloc made during the program, at the end
 * @param   game the struct of the game
 * @return  0 because MLX requires it or 1 for an error
 */
int	ft_clean(t_game *game)
{
	if (!game)
		return (1);
	ft_free_textures_colors(game);
	ft_free_minimap(game);
	mlx_destroy_window(game->mlx, game->wdw);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->img->texture_buffer);
	free(game->img->frm);
	free(game->img);
	exit(0);
	return (0);
}
