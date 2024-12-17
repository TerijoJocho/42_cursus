#include "pipex.h"

void	ft_init_pipex(char **argv, int argc, t_pipex *data)
{
	if (ft_strncmp(argv[1], "here_doc", 7) == 0)
	{
		data->here_doc = true;
		data->in_fd = -1;
		data->is_invalid_infile = false;
		data->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
	}
	else
	{
		data->here_doc = false;
		data->in_fd = open(argv[1], O_RDONLY);
		if (data->in_fd == -1)
		{
			perror("open infile");
			close(data->in_fd);
			data->is_invalid_infile = true;
			exit(EXIT_FAILURE);
		}
		data->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
	}
	if (data->out_fd == -1)
	{
		perror("open outfile");
		close(data->out_fd);
		exit(EXIT_FAILURE);
	}
	if (data->here_doc == true)
		data->cmd_count = argc - 4;
	else
		data->cmd_count = argc - 3;
	/*verif*/
	ft_printf("in_fd = %d\n", data->in_fd);
	ft_printf("out_fd = %d\n", data->out_fd);
	ft_printf("here_doc = %d\n", data->here_doc);
	ft_printf("is_invalid_infile = %d\n", data->is_invalid_infile);
	ft_printf("cmd_count = %d\n", data->cmd_count);
	/*-------------------------------------*/
}
