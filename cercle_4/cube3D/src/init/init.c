
#include "../includes/cube3d.h"

int	ft_init_game(t_game *game, char *argv)
{
	game->file_name = argv;
	game->file_tab = NULL;
	game->map = NULL;
	game->NO = NULL;
	game->SO = NULL;
	game->WE = NULL;
	game->EA = NULL;
	game->F = NULL;
	game->C = NULL;
	game->p = malloc(sizeof(t_player));
	if (!game->p)
		return (printf("error: malloc player failed\n"), 1);
	game->p->p_dir = 0;
	game->p->p_x = -1;
	game->p->p_y = -1;
	return(0);
}
