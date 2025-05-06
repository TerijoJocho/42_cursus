/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:41:17 by aistierl          #+#    #+#             */
/*   Updated: 2025/05/06 15:34:15 by aistierl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int *ft_tab_rgb(char *color)
{
    char        **tab;
    int         i;
    int         *tab_rgb;
    
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

void	ft_define_img(t_game *game)
{
	game->img.img_height = 75; // valeur a changer
	game->img.img_length = 75; // idem
	game->img.north_wall_img = mlx_xpm_file_to_image(game->mlx, game->NO,
			&game->img.img_length, &game->img.img_height);
	game->img.east_wall_img = mlx_xpm_file_to_image(game->mlx, game->EA,
			&game->img.img_length, &game->img.img_height);
	game->img.south_wall_img = mlx_xpm_file_to_image(game->mlx,
			game->SO, &game->img.img_length,
			&game->img.img_height);
	game->img.west_wall_img = mlx_xpm_file_to_image(game->mlx, game->WE,
			&game->img.img_length, &game->img.img_height);
	// ceiling color minilib a completer
    game->img.ceiling_color = ft_tab_rgb(game->C);
    if (!game->img.ceiling_color)
        return (printf("error: malloc failed\n"), free(game->img.ceiling_color));
	// floor color minilib a completer
    game->img.floor_color = ft_tab_rgb(game->F);
    if (!game->img.floor_color)
        return (printf("error: malloc failed\n"), free(game->img.floor_color));
}
