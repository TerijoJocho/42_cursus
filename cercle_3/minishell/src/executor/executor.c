/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:36:10 by daavril           #+#    #+#             */
/*   Updated: 2025/03/10 17:02:58 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**clone_tab_env(t_clone *env)
{
	char	**tab;
	t_clone	*cur;
	int		i;
	int		size;

	cur = env;
	size = 0;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	cur = env;
	while (cur)
	{
		tab[i] = ft_strdup(cur->value);
		// printf("tab[%d] = %s\n", i, tab[i]);
		cur = cur->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	do_cmd_last(t_cmd *cmd, char **env)
{
	t_cmd	*cur_cmd;
	pid_t	pid;

	cur_cmd = cmd;
	if (cur_cmd->error == 1)
		return ; //gerer l'erreur
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		if (execve(cur_cmd->path, cur_cmd->args, env) == -1)
		{
			printf("Error execve\n");
			exit(1) ;
		}
	}
	else
		waitpid(pid, NULL, 0);
}


int	executor(t_master *master)
{
	// pid_t	pid;
	// char	buf;
	t_cmd	*cur;
	// int	flag;

	// flag = 0;
	cur = master->cmd_list;
	master->env = clone_tab_env(master->env_clone);
	while (cur)
	{
		// if (cur->next && flag == 0)
		// 	do_cmd_first(cur);
		// else if (cur->next && flag == 1)
		// {
		// 	do_cmd_middle();
		// 	flag = 1;
		// }
		// else if (!cur->next)
		// 	do_cmd_last(cur);
		do_cmd_last(cur, master->env);
		cur = cur->next;
	}
	return (0);
}


// int	executor(t_master *master)
// {
	// pid_t	pid;
	// char	buf;

	// if (pipe(master->cmd_list->pfd) == -1)
	// 	return (1);
	// pid = fork();
	// if (pid == -1)
	// 	return (1);
	// else if (pid == 0)
	// {
	// 	close(master->cmd_list->pfd[1]);
	// 	write(STDOUT_FILENO, "K : le secret est : \n", 20);
	// 	while (read(master->cmd_list->pfd[0], &buf, 1) > 0)
	// 		write(STDOUT_FILENO, &buf, 1);
	// 	close(master->cmd_list->pfd[0]);
	// 	exit(EXIT_SUCCESS);
	// }
	// else
	// {
	// 	close(master->cmd_list->pfd[0]);

	// 	close(master->cmd_list->pfd[1]);
	// 	wait(NULL);
	// 	write(STDOUT_FILENO, "P : GG\n", 7);
	// }
// 	return (0);
// }
