/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:19:38 by aistierl          #+#    #+#             */
/*   Updated: 2025/05/19 17:31:13 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_move_player_right_bonus(t_game *game)
{
	if (game->map[(int)(game->p->p_y + game->p->plane_y * 0.4)][(int)(game->p->p_x + game->p->plane_x * 0.5)] == '1')
		return;
	game->p->p_x += game->p->plane_x * 0.1;
	game->p->p_y += game->p->plane_y * 0.1;
}

void	ft_move_player_left_bonus(t_game *game)
{
	if (game->map[(int)(game->p->p_y - game->p->plane_y * 0.4)][(int)(game->p->p_x - game->p->plane_x * 0.5)] == '1')
		return;
	game->p->p_x -= game->p->plane_x * 0.1;
	game->p->p_y -= game->p->plane_y * 0.1;
}

void	ft_move_player_forward_bonus(t_game *game)
{
	if (game->map[(int)(game->p->p_y + game->p->dir_y * 0.4)][(int)(game->p->p_x + game->p->dir_x * 0.5)] == '1')
		return;
	game->p->p_x += game->p->dir_x * 0.1;
	game->p->p_y += game->p->dir_y * 0.1;
}

void	ft_move_player_backward_bonus(t_game *game)
{
	if (game->map[(int)(game->p->p_y - game->p->dir_y * 0.4)][(int)(game->p->p_x - game->p->dir_x * 0.5)] == '1')
		return;
	game->p->p_x -= game->p->dir_x * 0.1;
	game->p->p_y -= game->p->dir_y * 0.1;
}

int	ft_input_to_event(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_W)
		ft_move_player_forward_bonus(game);
	else if (keycode == XK_S || keycode == XK_s)
		ft_move_player_backward_bonus(game);
	else if (keycode == XK_A || keycode == XK_a)
		ft_move_player_left_bonus(game);
	else if (keycode == XK_D || keycode == XK_d)
		ft_move_player_right_bonus(game);
	else if (keycode == XK_Escape)
		return (ft_clean(game), 0);
	else if (keycode == XK_Left)
		ft_rotate_player_left(game);
	else if (keycode == XK_Right)
		ft_rotate_player_right(game);
	return (1);
}
