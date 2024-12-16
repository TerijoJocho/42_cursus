#include "pipex.h"

int main(int argc, char **argv)
{
    t_pipex *data;
    
	ft_check_args(argc, argv);
    data = (t_pipex *)malloc(sizeof(t_pipex));
    if (!data)
        return(1);
    ft_init_pipex(argv, argc, data);
	// ft_parse_cmds();
	// ft_parse_args();
	// while (cmds)
	// 	ft_exec();
	// ft_cleanup();
    return (0);
}