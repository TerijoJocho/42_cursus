/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:41:17 by aistierl          #+#    #+#             */
/*   Updated: 2025/05/19 16:00:00 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	*ft_tab_rgb(char *color)
{
	char	**tab;
	int		i;
	int		*tab_rgb;

	tab_rgb = malloc(sizeof(int) * 3);
	if (!tab_rgb)
		return (NULL);
	tab = ft_split(color, ',');
	if (!tab)
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		tab_rgb[i] = ft_atoi(tab[i]);
		i++;
	}
	ft_clean_tab(tab);
	return (tab_rgb);
}

void	ft_init_tmp(t_game *game, char **tmp)
{
	tmp[0] = game->NO;
	tmp[1] = game->SO;
	tmp[2] = game->WE;
	tmp[3] = game->EA;
	tmp[4] = NULL;
}

int	ft_xpm_to_image(t_game *game, t_img *img, int i)
{
	char	*tmp[5];
	int		tmp_bpp;
	int		tmp_sl;
	int		tmp_endian;

	ft_init_tmp(game, tmp);
	while (i < NUM_TEXTURES)
	{
		img->texture_img[i] = mlx_xpm_file_to_image(game->mlx, tmp[i],
				&img->img_width, &img->img_height);
		if (!img->texture_img[i])
			return (printf("error: mlx_xpm_file_to_image failed\n"), 1);
		img->texture_buffer[i] = (int *)mlx_get_data_addr(img->texture_img[i],
				&tmp_bpp, &tmp_sl, &tmp_endian);
		i++;
	}
	return (0);
}

int	ft_define_img(t_game *game)
{
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		return (printf("error: malloc failed\n"), 1);
	game->img->img_height = TEXTURE_HEIGHT;
	game->img->img_width = TEXTURE_WIDTH;
	game->img->frm = malloc(sizeof(t_frame));
	if (!game->img->frm)
		return (printf("error: malloc failed\n"), 1);
	game->img->texture_buffer = malloc(sizeof(int *) * NUM_TEXTURES);
	if (!game->img->texture_buffer)
		return (printf("error: malloc failed\n"), 1);
	game->img->frm->frame = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img->frm->frame)
		return (printf("error: mlx_new_image failed\n"), 1);
	game->img->frm->frame_addr = (int *)mlx_get_data_addr(game->img->frm->frame,
			&game->img->frm->bits_per_pixel, &game->img->frm->size_line,
			&game->img->frm->endian);
	ft_xpm_to_image(game, game->img, 0);
	game->img->ceiling_color = ft_tab_rgb(game->C);
	if (!game->img->ceiling_color)
		return (printf("error: malloc failed\n"), 1);
	game->img->floor_color = ft_tab_rgb(game->F);
	if (!game->img->floor_color)
		return (printf("error: malloc failed\n"), 1);
	return (0);
}
