

#include "../../includes/minishell.h"

/*change le repertoire actuel encelui qu'on envoit*/
void	ft_cd(t_master *master, t_cmd *cmd)
{
	// char    *path;
	// struct  stat path_stat;

	// if (cmd->args[1] == NULL)
	// {
	//     path = master->
	// }
	// if (path == NULL || access(path, F_OK) == -1)
	//     return ;//gerer erreur genre : return("is not a directory")
	// if (chdir(path) == -1)
	//     printf("Error cd\n");
	(void)cmd;
	t_clone *cur = master->env_clone;
	while (cur)
	{
		printf("clone value: %s\n", cur->value);
		cur = cur->next;
	}
}
