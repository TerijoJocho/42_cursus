#include "pipex.h"

void	ft_parse_cmds(t_pipex *data, char **argv)
{
	int	i;

	data->cmd_args = (char ***)malloc(sizeof(char **) * data->cmd_count);
	if (!data->cmd_args)
	{
		perror("Malloc cmd_args");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < data->cmd_count)
	{
		
	}
}
