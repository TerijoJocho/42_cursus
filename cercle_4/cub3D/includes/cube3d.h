

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_player
{
	double	p_x;
	double	p_y;
	char	p_dir;

	double	dir_x;
	double	dir_y;

	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;

	int		map_x;
	int		map_y;

	double	delta_dist_x;
	double	delta_dist_y;

	double	side_dist_x;
	double	side_dist_y;

	int		step_x;
	int		step_y;
	int		side;

	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;

	double	wall_x;
}	t_ray;

typedef struct s_img
{
	int				img_length;
	int				img_height;

	int				*floor_color;
	int				*ceiling_color;

	void			*north_wall_img;
	void			*south_wall_img;
	void			*east_wall_img;
	void			*west_wall_img;
}					t_img;

typedef struct s_game
{
	char		*file_name;
	char		**file_tab;

	char		**map;

	void		*mlx;
	void		*wdw;

	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*F;
	char		*C;

	t_img		img;
	t_player	*p;
	t_ray		ray;	
}			t_game;

/*parsing*/
int	ft_get_file(t_game *game);
int	ft_parse_file(t_game *game);
int	ft_check_void(char *str);
int	ft_check_texture(t_game *game, int len, int i);
int	ft_check_colors(t_game *game, int len);
int	ft_check_map(t_game *game, int i);
int	ft_check_map_charset(char **map);
int	ft_is_map(char *line);
int	ft_is_line_empty(char *line);
int	ft_get_maplen(char **map);
int	ft_fill_line(char **map, int i, int max_len, char *tmp);
int	ft_find_map_bounds(t_game *game, int *start, int *end);
int	ft_check_map_square(char **map);

/*init*/
int	ft_init_game(t_game *game, char *argv);
void    ft_init_splayer(t_game *game);

/*exit*/
void	ft_clean(t_game *game);
void	ft_clean_tab(char **tab);

/*exec*/
void	ft_define_img(t_game *game);

/*exit_exec*/
int		ft_cleanup_mess(t_game *game);

#endif
