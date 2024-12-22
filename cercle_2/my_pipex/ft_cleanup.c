#include "pipex.h"

void	ft_free_tab(char **args)
{
	if (!args)
		return ;
	while (*args)
	{
		free(*args);
		args++;
	}
	free(args);
}

void	free_cmd_args(char ***cmd_args, int cmd_count)
{
	int	i;

	if (!cmd_args)
		return;
	i = 0;
	while (i < cmd_count - 1)
	{
		if (cmd_args[i])
			ft_free_tab(cmd_args[i]);
		i++;
	}
	free(cmd_args);
}

