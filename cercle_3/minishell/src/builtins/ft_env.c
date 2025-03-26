

#include "../../includes/minishell.h"

/*Affiche toutes les variables d'envp, à partir de la copie*/
void	ft_env(char **env, t_master *master)
{
	// int i;

	// i = 0;
	// while (env[i])
	// {
	// 	printf("%s\n", env[i]);
	// 	i++;
	// }
	(void)env;
	t_clone	*cur;

	cur = master->env_clone;
	if (!cur)
		return ;
	while (cur)
	{
		printf("%s\n", cur->value);
		cur = cur->next;
	}
}
