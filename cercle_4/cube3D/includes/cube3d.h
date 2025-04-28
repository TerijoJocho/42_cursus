

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_game
{
	char	*file_name;
	char	**file_tab;
}			t_game;

/*parsing*/
int	ft_get_file(t_game *game);
int	ft_parse_file(t_game *game);

/*init*/
int	ft_init_game(t_game *game, char *argv);

/*exit*/
void	ft_clean(t_game *game);

#endif
