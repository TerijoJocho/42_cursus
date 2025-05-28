/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:41:17 by aistierl          #+#    #+#             */
/*   Updated: 2025/05/23 18:55:36 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

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
	tmp[0] = game->no;
	tmp[1] = game->so;
	tmp[2] = game->we;
	tmp[3] = game->ea;
	tmp[4] = NULL;
}

void	ft_init_textures(t_game *game)
{
	game->img->ceiling_color = NULL;
	game->img->floor_color = NULL;
	game->img->texture_img[NORTH] = NULL;
	game->img->texture_img[SOUTH] = NULL;
	game->img->texture_img[EAST] = NULL;
	game->img->texture_img[WEST] = NULL;
	game->img->texture_buffer[NORTH] = NULL;
	game->img->texture_buffer[SOUTH] = NULL;
	game->img->texture_buffer[EAST] = NULL;
	game->img->texture_buffer[WEST] = NULL;
}

int	ft_xpm_to_image(t_game *game, t_img *img, int i)
{
	char	*tmp[5];
	int		tmp_bpp;
	int		tmp_sl;
	int		tmp_endian;

	ft_init_tmp(game, tmp);
	game->img->img_height = TEXTURE_HEIGHT;
	game->img->img_width = TEXTURE_WIDTH;
	while (i < NUM_TEXTURES)
	{
		img->texture_img[i] = mlx_xpm_file_to_image(game->mlx, tmp[i],
				&img->img_width, &img->img_height);
		if (!img->texture_img[i])
			return (printf("error: mlx_xpm_file_to_image failed\n"), 1);
		img->texture_buffer[i] = (int *)mlx_get_data_addr(img->texture_img[i],
				&tmp_bpp, &tmp_sl, &tmp_endian);
		if (!img->texture_buffer[i])
			return (printf("error: mlx_get_data_addr failed\n"), 1);
		i++;
	}
	return (0);
}

int	ft_define_img(t_game *game)
{
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		return (printf("error: malloc failed\n"), 1);
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
	if (!game->img->frm->frame_addr)
		return (printf("error: mlx_get_data_addr failed\n"), 1);
	ft_init_textures(game);
	if (ft_xpm_to_image(game, game->img, 0))
		return (1);
	game->img->ceiling_color = ft_tab_rgb(game->c);
	game->img->floor_color = ft_tab_rgb(game->f);
	if (!game->img->ceiling_color || !game->img->floor_color)
		return (printf("error: ceiling or floor malloc failed\n"), 1);
	return (0);
}
