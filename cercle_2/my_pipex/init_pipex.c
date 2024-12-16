#include "pipex.h"

void    ft_init_pipex(char **argv, int argc, t_pipex *data)
{   
    if (strcmp(argv[1], "here_doc") == 0)
    {
        data->here_doc = true;
        data->in_fd = -1;
        data->is_invalid_infile = false;
        data->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
    }
    else
    {
        data->here_doc = fals;
        data->in_fd = open(argv[1], O_ONLY);
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
        data->cmd_count = argc -4;
    else
        data->cmd_count = argc -3;
    data->cmd_args = (char ***)malloc(sizeof(char **) * data->cmd_count);
    if (!data->cmd_args)
    {
        perror("Malloc cmd_args");
        exit(EXIT_FAILURE);
    }
}