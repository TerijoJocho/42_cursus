
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
