#include "pipex.h"

void	free_cmd_args(char ***cmd_args, int cmd_count)
{
	int	i;

	if (!cmd_args)
		return;
	i = 0;
	while (i < cmd_count - 1)
	{
		if (cmd_args[i])
			ft_free_tab(cmd_args[i]); // Fonction pour libérer un tableau de chaînes
		i++;
	}
	free(cmd_args);
}

