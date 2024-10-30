/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:24:17 by daavril           #+#    #+#             */
/*   Updated: 2024/10/21 20:12:17 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__
#  include "minilibx/minilibx-linux/mlx.h"
# elif __APPLE__
#  include "minilibx/minilibx_mms20200219/mlx.h"
# endif
# include "Lib_ft/gnl/get_next_line.h"
# include "Lib_ft/libft/libft.h"
# include "Lib_ft/printf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*VECTOR*/
typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

/*MAP*/
typedef struct s_map
{
	char		**grille;
	char		**grille_clone;
	char		**grille_clone_2;
	int			rows;
	int			columns;
	int			colectable;
	int			exit;
	int			players;
	int			elements;
	t_vector	player;
	t_vector	map_size;
	t_vector	img_size;
}				t_map;

/*GAME*/
typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*w;
	void		*p;
	void		*e;
	void		*c;
	void		*f;
	int			moves;
	t_map		map;
}				t_game;

/*for map*/
void			init_game(t_game *game, char *fichier_map);
char			**read_map(int fd);
void			map_check(t_game *game);
void			map_exist(t_game *game);
void			map_rectangular(t_game *game);
void			map_check_wall(t_game *game);
void			map_count_pec(t_game *game);
void			map_check_pec(t_game *game);
void			wall_1(char *line, t_game *game);
void			init_var(t_game *game);
void			get_map(t_game *game, char *fichier_map);
void			ft_strappend(char **str, char *s, t_game *game);
void			map_playable(t_game *game);
void			error_message(char *msg, t_game *game, int flag);

/*for windo???*/
void			init_window(t_game *game);
int				on_keypress(int keysym, t_game *game);
int				on_destroy(t_game *game);

/*image*/
void			init_img(t_game *game);
void			render_map(t_game *game, int map_width, int map_height);
void			put_on_map(char elem, t_game *game, int x, int y);
void			*take_img(void *file, int *x, int *y, t_game *game);

/*deplacement*/
void			move(int x, int y, t_game *game);
int				is_wall(int x, int y, t_game *game);

void			game_over(t_game *game);
void			free_map(char **grille);
void			destroy(t_game *game);

#endif
