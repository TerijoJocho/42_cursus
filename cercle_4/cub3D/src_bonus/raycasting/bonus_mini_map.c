/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_mini_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:20:23 by daavril           #+#    #+#             */
/*   Updated: 2025/05/21 14:42:10 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_draw_direction(t_game *game, int x, int y)
{
	int	i;
	int	px;
	int	py;

	i = 0;
	px = game->p->p_x * 7 + 50;
	py = game->p->p_y * 7 + 50;
	while (i < RATIO)
	{
		x = px + (int)(game->p->dir_x * i);
		y = py + (int)(game->p->dir_y * i);
		if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
			game->img->frm->frame_addr[y * (game->img->frm->size_line / 4)
				+ x] = 0x00FFFFFF;
		i++;
	}
}

int	ft_color(t_game *game, char tile, int y, int x)
{
	if (y == (int)game->p->p_y && x == (int)game->p->p_x)
		return (0x00FF0000);
	else
		((void)y, (void)x);
	if (tile == '1')
		return (0x00666666);
	else if (tile == '0')
		return (0x00000000);
	else
		return (0x00000000);
}

void	ft_draw_tile_row(t_game *game, int y, int start_y)
{
	int	x;
	int	start_x;
	int	color;
	int	a;
	int	b;

	x = 0;
	while (x < (int)ft_strlen(game->map[y]))
	{
		start_x = 50 + x * RATIO;
		color = ft_color(game, game->map[y][x], y, x);
		b = 0;
		while (b < RATIO)
		{
			a = 0;
			while (a < RATIO)
			{
				game->img->frm->frame_addr[(start_y + b)
					* (game->img->frm->size_line / 4) + start_x + a] = color;
				a++;
			}
			b++;
		}
		x++;
	}
}

void	ft_minimap(t_game *game)
{
	int	y;
	int	start_y;

	start_y = 50;
	y = 0;
	while (y <= game->m_line)
	{
		ft_draw_tile_row(game, y, start_y);
		start_y += RATIO;
		y++;
	}
	ft_draw_direction(game, RATIO, 50);
}
