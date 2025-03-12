

#include "../../includes/minishell.h"

/*Affiche toutes les variables d'envp, à partir de la copie*/
void	ft_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
