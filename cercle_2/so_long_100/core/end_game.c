/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:44:53 by daavril           #+#    #+#             */
/*   Updated: 2024/10/15 12:32:30 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_message(char *msg, t_game *game, int flag)
{
	if (flag == 1)
		ft_printf("\nError.\n%s", msg);
	if (game->map.grille != NULL)
		free_map(game->map.grille);
	if (game->map.grille_clone != NULL)
		free_map(game->map.grille_clone);
	if (game->map.grille_clone_2 != NULL)
		free_map(game->map.grille_clone_2);
	if (game->mlx_ptr != NULL)
		destroy(game);
	if (flag == 1)
		exit(EXIT_FAILURE);
}

void	game_over(t_game *game)
{
	error_message("Game closed.\n", game, 0);
	exit(EXIT_SUCCESS);
}

void	free_map(char **grille)
{
	int	i;

	i = 0;
	while (grille[i])
	{
		free(grille[i]);
		i++;
	}
	free(grille);
	grille = NULL;
}

void	destroy(t_game *game)
{
	if (game->p != NULL)
		mlx_destroy_image(game->mlx_ptr, game->p);
	if (game->e != NULL)
		mlx_destroy_image(game->mlx_ptr, game->e);
	if (game->f != NULL)
		mlx_destroy_image(game->mlx_ptr, game->f);
	if (game->c != NULL)
		mlx_destroy_image(game->mlx_ptr, game->c);
	if (game->w != NULL)
		mlx_destroy_image(game->mlx_ptr, game->w);
	if (game->win_ptr != NULL)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr != NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}
