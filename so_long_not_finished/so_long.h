/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:24:17 by daavril           #+#    #+#             */
/*   Updated: 2024/09/24 16:26:26 by daavril          ###   ########.fr       */
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
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <unistd.h>
#include <fcntl.h>
#include "Lib_ft/gnl/get_next_line.h"
#include "Lib_ft/libft/libft.h"
#include "Lib_ft/printf/ft_printf.h"

/*assets*/

#define CHARAC_XPM	"icon_asset/icon_character.xpm"
#define COIN_XPM	"icon_asset/Banana.xpm"
#define EXIT_XPM	"icon_asset/icon_door.xpm"
#define OPEN_XPM	"icon_asset/icon_flag.xpm"
#define WALL_XPM	"icon_asset/jungle-tileset.xpm"
#define FLOOR_XPM	"icon_asset/background.xpm"

/*VECTOR*/
typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

/*MAP*/
typedef struct s_map
{
	char	**grille;
	char	**grille_clone;
	int		rows;
	int		columns;
	int		colectable;
	int		exit;
	int		players;
	int		elements;
	t_vector	player;
	t_vector	map_size;
	t_vector	img_size;
}	t_map;

/*GAME*/
typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_xpm;
	void	*coins_xpm;
	void	*exit_xpm;
	void	*open_xpm;
	void	*charac_xpm;
	void	*floor_xpm;
	void	*charac_exit_xpm;
	int		moves;
	t_map	map;
}	t_game;

/*for map*/
void	init_game(t_game *game, char *fichier_map);
char	**read_map(int fd);
void	map_check(t_game *game);
void	map_exist(t_game *game);
void	map_rectangular(t_game *game);
void	map_check_wall(t_game *game);
void	map_count_PEC(t_game *game);
void	map_check_PEC(t_game *game);
void	wall_1(char *line, t_game *game);
void	init_var(t_game *game);
void	get_map(t_game *game, char *fichier_map);
void	ft_strappend(char **str, char *s, t_game *game);
void	map_playable(t_game *game);
void	error_message(char *msg, t_game *game);

/*for windo???*/
void	init_window(t_game *game);
int	on_keypress(int keysym, t_game *game);
int	on_destroy(t_game *game);

/*image*/
void	init_img(t_game *game);
void	render_map(t_game *game);
void	put_on_map(char	elem, t_game *game, int x, int y);
void	*take_img(void *file, int *x, int *y, t_game *game);

/*deplacement*/
void	move(int x, int y, t_game *game);
int	is_wall(int x, int y, t_game *game);

void	game_over(t_game *game);

#endif
