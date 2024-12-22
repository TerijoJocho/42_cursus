#ifndef PIPEX_H
# define PIPEX_H

# include "Lib_ft/libft/libft.h"
# include "Lib_ft/printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	t_bool	here_doc;
	t_bool	is_invalid_infile;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
}			t_pipex;

void		ft_init_pipex(char **argv, int argc, t_pipex *data);
void		ft_check_args(int argc, char **argv);
void		ft_parse_args(t_pipex *data, char **argv);
void		ft_parse_cmds(t_pipex *data, char **argv, char **envp);

#endif
