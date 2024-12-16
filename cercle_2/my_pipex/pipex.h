#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

typedef enum e_bool
{
	false,
	true
} t_bool;

typedef struct s_pipex
{
	int in_fd;
	int out_fd;
	t_bool here_doc;
	t_bool is_invalid_infile;
	char **cmd_paths;
	char ***cmd_args;
	int cmd_count;
} t_pipex;

void    ft_init_pipex(char **argv, int argc, t_pipex *data);

#endif 