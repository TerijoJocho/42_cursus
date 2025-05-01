

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_player
{
	int	p_x;
	int	p_y;
	char	p_dir;
}	t_player;

typedef struct s_game
{
	char	*file_name;
	char	**file_tab;
	char	**map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	t_player	*p;
}			t_game;

/*parsing*/
int	ft_get_file(t_game *game);
int	ft_parse_file(t_game *game);
int	ft_check_void(char *str);
int	ft_check_texture(t_game *game, int len);
int	ft_check_colors(t_game *game, int len);
int	ft_check_map(t_game *game, int i);

/*init*/
int	ft_init_game(t_game *game, char *argv);

/*exit*/
void	ft_clean(t_game *game);
void	ft_clean_tab(char **tab);

#endif
