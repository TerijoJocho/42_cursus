#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc > 1)
	{
		// ft_check_args(argc, argv); /*j'sais ps si je garde */
		ft_init_pipex(argv, argc, &data);
		ft_parse_args(&data, argv);
		ft_parse_cmds(&data, argv, envp);
		// while (cmds)
		// 	ft_exec();
		// ft_cleanup();
	}
	else
		return (1);
	return (0);
}
