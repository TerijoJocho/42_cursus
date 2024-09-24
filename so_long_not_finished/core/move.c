/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:13:24 by daavril           #+#    #+#             */
/*   Updated: 2024/09/24 16:56:14 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img(void *img, int x, int y, t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x, y);
}

int	is_wall(int x, int y, t_game *game)
{
	return(game->map.grille[y][x] == '1');
}

void	move(int x, int y, t_game *game)
{
	if (game->map.grille[y][x] == 'E' && game->map.colectable != 0)
		return ;
	put_img(game->floor_xpm, game->map.player.x * 32, game->map.player.y * 32, game);
	game->map.player.x = x;
	game->map.player.y = y;
	put_img(game->charac_xpm, game->map.player.x * 32, game->map.player.y * 32, game);
	if (game->map.grille[y][x] == 'C')
		game->map.colectable--;
	game->moves++;
	ft_printf("Mouvements : %d\n", game->moves);
	if (game->map.grille[y][x] == 'E' && game->map.colectable == 0)
	{
		ft_printf("YOU HAVE WONTHE GAME IN %d MOVE.\n GG !!", game->moves);
		game_over(game);
	}
	game->map.grille[y][x] = 'P';
}
