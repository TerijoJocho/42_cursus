

#include "../../includes/minishell.h"

/*Affiche toutes les variables d'envp, à partir de la copie*/
void	ft_env(t_master *master)
{
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
