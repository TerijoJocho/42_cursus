/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:38:50 by daavril           #+#    #+#             */
/*   Updated: 2025/05/30 19:59:46 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

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
	if (game->img->frm->frame)
		mlx_destroy_image(game->mlx, game->img->frm->frame);
	if (game->img->texture_img[NORTH])
		mlx_destroy_image(game->mlx, game->img->texture_img[NORTH]);
	if (game->img->texture_img[SOUTH])
		mlx_destroy_image(game->mlx, game->img->texture_img[SOUTH]);
	if (game->img->texture_img[EAST])
		mlx_destroy_image(game->mlx, game->img->texture_img[EAST]);
	if (game->img->texture_img[WEST])
		mlx_destroy_image(game->mlx, game->img->texture_img[WEST]);
	if (game->img->floor_color)
		(free(game->img->floor_color), game->img->floor_color = NULL);
	if (game->img->ceiling_color)
		(free(game->img->ceiling_color), game->img->ceiling_color = NULL);
}

void	ft_clean_parse(t_game *game, int flag)
{
	if (game->no != NULL)
		(free(game->no), game->no = NULL);
	if (game->so != NULL)
		(free(game->so), game->so = NULL);
	if (game->we != NULL)
		(free(game->we), game->we = NULL);
	if (game->ea != NULL)
		(free(game->ea), game->ea = NULL);
	if (game->f != NULL)
		(free(game->f), game->f = NULL);
	if (game->c != NULL)
		(free(game->c), game->c = NULL);
	ft_clean_tab(game->file_tab);
	ft_clean_tab(game->map);
	if (game->keys)
		free(game->keys);
	if (game->p)
		free(game->p);
	if (game->ray)
		free(game->ray);
	if (game->minimap)
		free(game->minimap);
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
	ft_clean_parse(game, 0);
	if (game->wdw != NULL && game->img != NULL)
	{
		if (game->img->frm)
		{
			ft_free_textures_colors(game);
			free(game->img->frm);
			free(game->img->texture_buffer);
		}
		free(game->img);
	}
	if (game->wdw)
		mlx_destroy_window(game->mlx, game->wdw);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
