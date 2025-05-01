
#include "../includes/cube3d.h"


/*utilise dans check colors*/
void	ft_clean_tab(char **tab)
{
	int	i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_textures_colors(t_game *game)
{
	if (!game)
		return ;
	if(game->NO !=  NULL)
		(free(game->NO), game->NO = NULL);
	if(game->SO !=  NULL)
		(free(game->SO), game->SO = NULL);
	if(game->WE !=  NULL)
		(free(game->WE), game->WE = NULL);
	if(game->EA !=  NULL)
		(free(game->EA), game->EA = NULL);
	if(game->F !=  NULL)
		(free(game->F), game->F = NULL);
	if(game->C !=  NULL)
		(free(game->C), game->C = NULL);
}

void	ft_clean(t_game *game)
{
	if (!game)
		return ;
	ft_free_textures_colors(game);
	ft_clean_tab(game->file_tab);
	ft_clean_tab(game->map);
	free(game);
}
