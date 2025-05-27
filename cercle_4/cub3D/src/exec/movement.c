/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:00:31 by aistierl          #+#    #+#             */
/*   Updated: 2025/05/21 15:29:12 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_W)
		game->keys->w = 0;
	else if (keycode == XK_s || keycode == XK_S)
		game->keys->s = 0;
	else if (keycode == XK_a || keycode == XK_A)
		game->keys->a = 0;
	else if (keycode == XK_d || keycode == XK_D)
		game->keys->d = 0;
	else if (keycode == XK_Left)
		game->keys->left = 0;
	else if (keycode == XK_Right)
		game->keys->right = 0;
	return (0);
}

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_W)
		game->keys->w = 1;
	else if (keycode == XK_s || keycode == XK_S)
		game->keys->s = 1;
	else if (keycode == XK_a || keycode == XK_A)
		game->keys->a = 1;
	else if (keycode == XK_d || keycode == XK_D)
		game->keys->d = 1;
	else if (keycode == XK_Left)
		game->keys->left = 1;
	else if (keycode == XK_Right)
		game->keys->right = 1;
	else if (keycode == XK_Escape)
		ft_clean(game);
	return (0);
}

void	ft_handle_keys(t_game *game)
{
	if (game->keys->w)
		ft_move_player_forward(game);
	if (game->keys->s)
		ft_move_player_backward(game);
	if (game->keys->a)
		ft_move_player_left(game);
	if (game->keys->d)
		ft_move_player_right(game);
	if (game->keys->left)
		ft_rotate_player_left(game);
	if (game->keys->right)
		ft_rotate_player_right(game);
}

long	get_current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_keys_loop(t_game *game)
{
	static long	last_time = 0;
	long		current_time;

	current_time = get_current_time_ms();
	if (current_time - last_time > 16)
	{
		ft_handle_keys(game);
		ft_raycasting(game);
		last_time = current_time;
	}
	return (0);
}
