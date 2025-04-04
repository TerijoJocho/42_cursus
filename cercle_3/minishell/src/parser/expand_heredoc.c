/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:13:33 by abastian          #+#    #+#             */
/*   Updated: 2025/04/05 00:50:53 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exp_check(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

void	add_tmp_heredoc(char **new_value, char *tmp)
{
	char	*prev_value;

	prev_value = *new_value;
	if (tmp != NULL)
	{
		*new_value = ft_strjoin(prev_value, tmp);
		free(prev_value);
		free(tmp);
	}
}

char	*expand_heredoc(t_clone **env, char *input, int i)
{
	char	*new_value;
	char	*tmp;

	new_value = ft_strdup("");
	tmp = NULL;
	if (!new_value)
		return (NULL);
	while (input[i])
	{
		if (input[i] == '$')
		{
			new_value = expand_variable(input, new_value, env, &i);
			if (!new_value)
				return (0);
			input += i;
			if (tmp != NULL)
				free(tmp);
			tmp = ft_strdup(input);
			i = 0;
		}
		else
			i++;
	}
	add_tmp_heredoc(&new_value, tmp);
	return (new_value);
}

void	clean_heredoc(int value, t_master *m, int flag)
{
	t_cmd	*cur;
	int		i;

	i = 0;
	cur = m->cmd_list;
	while (cur)
	{
		i = 0;
		while (cur->link[i])
		{
			unlink(cur->link[i]);
			i++;
		}
		cur = cur->next;
	}
	clean_exit(value, m, flag);
}

int	waitloop(pid_t pid, int status, int fd, t_cmd *cur)
{
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 2)
	{
		cur->error = 1;
		(set_signal(), close(fd));
		return (1);
	}
	return (0);
}
