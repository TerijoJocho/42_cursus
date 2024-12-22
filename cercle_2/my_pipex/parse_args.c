#include "pipex.h"

void	ft_parse_args(t_pipex *data, char **argv)
{
	int	i;
	int	j;

	data->cmd_args = (char ***)malloc(sizeof(char **) * data->cmd_count);
	if (!data->cmd_args)
	{
		free_cmd_args(data->cmd_args);
		perror("Malloc cmd_args");
		exit(EXIT_FAILURE);
	}
	if (data->here_doc == 0)
		i = 2;
	else
		i = 3;
	j = 0;
	while (j < data->cmd_count)
	{
		data->cmd_args[j] = ft_split(argv[i], ' ');
		if (!data->cmd_args[j])
		{
			perror("Split cmds_args");
			exit(EXIT_FAILURE);
		}
		/*verif---------------------------------*/
		ft_printf("cmd[%d]:\n", j);
		for (int k = 0; data->cmd_args[j][k]; k++)
			ft_printf("  arg[%d]: %s\n", k, data->cmd_args[j][k]);
		/*-------------------------------------*/
		i++;
		j++;
	}
}
