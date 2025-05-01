
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
	return(0);
}
