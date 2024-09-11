/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:24:17 by daavril           #+#    #+#             */
/*   Updated: 2024/09/11 15:58:10 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*typedef struct s_map
{
	int width; //largeur de la map
	int height; //hauteur de la map
	char **layout; //Représentation de la carte, par exemple, une grille de caractères
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;//mlx pointer
	void	*win_ptr;// mlx window pointer
	void	*textures[5];// mlx image pointers on the stack
	t_map	*map;//map pointer that contains map details on the stack
}	t_data;
*/

#ifndef SO_LONG_H
#define SO_LONG_H

#ifdef __linux__
#include "minilibx/minilibx-linux/mlx.h"
#elif __APPLE__
#include "minilibx/minilibx_mms20200219/mlx.h"
#endif
#include "libftprintf/include/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>

/*assets*/
typedef struct s_image
{
	void	*xpm_ptr;
	int	*x;
	int	*y;
}	t_image;

#define CHARAC_XPM	"icon_asset/icon_character.xpm"
#define COIN_XPM	"icon_asset/icon_coin.xpm"
#define EXIT_XPM	"icon_asset/icon_door.xpm"
#define OPEN_XPM	"icon_asset/icon_flag.xpm"
#define WALL_XPM	"icon_asset/icon_mirror.xpm"

#endif
