
#include "../includes/cube3d.h"

void	ft_clean(t_game *game)
{
	int	i;

	if (!game)
		return ;
	if (game->file_tab)
	{
		i = 0;
		while (game->file_tab[i])
		{
			free(game->file_tab[i]);
			i++;
		}
		free(game->file_tab);
	}
	free(game);
}
