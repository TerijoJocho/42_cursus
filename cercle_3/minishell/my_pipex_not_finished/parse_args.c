#include "pipex.h"

void	ft_parse_args(t_pipex *data, char **argv)
{
	int	i;
	int	j;
	int	k;

	data->cmd_args = malloc(sizeof(char **) * (data->cmd_count + 1));
	if (!data->cmd_args)
	{
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
		ft_printf("Parsing argv[%d]: '%s'\n", i, argv[i]);
		data->cmd_args[j] = ft_split(argv[i], ' ');
		if (!data->cmd_args[j])
		{
			perror("Split cmds_args");
			free_cmd_args(data->cmd_args, data->cmd_count);
			exit(EXIT_FAILURE);
		}
		/*verif------------------------------------*/
		k = 0;
		while (data->cmd_args[j][k])
		{
			ft_printf("cmd_args[%d][%d] = %s\n", j, k, data->cmd_args[j][k]);
			k++;
		}
		printf("\n");
		/*verif------------------------------------*/
		i++;
		j++;
	}
	data->cmd_args[j] = NULL;
}
