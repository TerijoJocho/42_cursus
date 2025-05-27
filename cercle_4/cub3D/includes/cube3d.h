/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:56:48 by daavril           #+#    #+#             */
/*   Updated: 2025/05/21 16:00:06 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define NUM_TEXTURES 4
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define MN_WIDTH 200
# define MN_HEIGHT 100
# define RATIO 7

typedef struct s_keys
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			left;
	int			right;
}				t_keys;

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}				t_direction;

typedef struct s_minimap
{
	int			minimap_width;
	int			minimap_height;
	int			mn_pos_x;
	int			mn_pos_y;
}				t_minimap;

typedef struct s_player
{
	double		p_x;
	double		p_y;
	char		p_dir;

	double		dir_x;
	double		dir_y;

	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_ray
{
	double		ray_dir_x;
	double		ray_dir_y;

	int			map_x;
	int			map_y;

	double		delta_dist_x;
	double		delta_dist_y;

	double		side_dist_x;
	double		side_dist_y;

	int			step_x;
	int			step_y;
	int			side;

	double		wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;

	double		wall_x;
}				t_ray;

typedef struct s_frame
{
	void		*frame;
	int			*frame_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_frame;

typedef struct s_img
{
	int			img_width;
	int			img_height;
	t_frame		*frm;

	int			*floor_color;
	int			*ceiling_color;

	void		*texture_img[NUM_TEXTURES];
	int			**texture_buffer;
}				t_img;

typedef struct s_game
{
	char		*file_name;
	char		**file_tab;

	char		**map;
	int			m_line;

	void		*mlx;
	void		*wdw;

	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;

	t_img		*img;
	t_player	*p;
	t_ray		*ray;
	t_minimap	*minimap;
	t_keys		*keys;
}				t_game;

/*parsing*/
int				ft_get_file(t_game *game);
int				ft_parse_file(t_game *game);
int				ft_check_void(char *str);
int				ft_check_texture(t_game *game, int len, int i, int fd);
int				ft_final_check_texture(t_game *game);
void			ff(char *f, char *f2, int fd);
int				ft_check_colors(t_game *game, int len);
int				ft_check_map(t_game *game, int i);
int				ft_check_map_charset(char **map);
int				ft_is_map(char *line);
int				ft_is_line_empty(char *line);
int				ft_get_maplen(char **map);
int				ft_fill_line(char **map, int i, int max_len, char *tmp);
int				ft_find_map_bounds(t_game *game, int *start, int *end);
int				ft_check_map_square(char **map);

/*init*/
int				ft_init_game(t_game *game, char *argv);
void			ft_init_splayer(t_game *game);

/*exit*/
int				ft_clean(t_game *game);
void			ft_clean_tab(char **tab);
void			ft_free_textures_colors(t_game *game);
void			ft_clean_parse(t_game *game, int flag);

/*exec*/
int				ft_define_img(t_game *game);
int				ft_raycasting(t_game *game);

int				ft_keys_loop(t_game *game);
int				ft_keys_loop_bonus(t_game *game);

int				ft_key_release(int keycode, t_game *game);
int				ft_key_press(int keycode, t_game *game);

void			ft_handle_keys(t_game *game);
void			ft_handle_keys_bonus(t_game *game);

void			ft_move_player_forward(t_game *game);
void			ft_move_player_backward(t_game *game);
void			ft_move_player_left(t_game *game);
void			ft_move_player_right(t_game *game);

void			ft_move_player_forward_bonus(t_game *game);
void			ft_move_player_backward_bonus(t_game *game);
void			ft_move_player_left_bonus(t_game *game);
void			ft_move_player_right_bonus(t_game *game);

void			ft_rotate_player_left(t_game *game);
void			ft_rotate_player_right(t_game *game);

void			ft_minimap(t_game *game);
int				ft_rgb_to_int(int rgb_tab[3]);
int				ft_looking_where(t_game *game);
void			ft_get_ray_dir(t_game *game, int x);
void			ft_get_delta_dist(t_game *game);
int				ft_what_color(t_game *game, int y, int tex_x, int tex_y);

#endif
