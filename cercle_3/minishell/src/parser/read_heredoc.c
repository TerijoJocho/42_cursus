/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:58:07 by abastian          #+#    #+#             */
/*   Updated: 2025/03/31 15:40:28 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

int	noquote(t_cmd *node, t_master *m, char *lim)
{
	t_cmd	*cur;
	t_token	*cur2;
	int		i;
	int		k;

	i = 0;
	k = 0;
	cur = m->cmd_list;
	cur2 = m->token_list;
	while (cur && cur != node)
	{
		i++;
		cur = cur->next;
	}
	while (cur2 && k != i)
	{
		if (cur2->real == PIPE)
			k++;
		cur2 = cur2->next;
	}
	while (cur2 && ft_strncmp(cur2->value, lim, ft_strlen(cur2->value)) != 0)
		cur2 = cur2->next;
	if (cur2 && cur2->quote_flag == 1)
		return (1);
	return (0);
}

void	pre_expand(int fd, char *input, t_master *m)
{
	char	*exp;
	// char	*cpy;

	// cpy = ft_strdup(input);
	exp = NULL;
	exp = expand_heredoc(&m->env_clone, input, 0);
	// free(cpy);
	if (!exp)
		return ;
	printf("exp value : %s\n", exp);
	write_it(fd, exp);
	free(exp);
}

void	heredoc_loop(int fd, char *lim, t_cmd *cur, t_master *m)
{
	char	*input;

	while (1)
	{
		input = readline("> ");
		if (!input)
		{
			printf("\n");
			break ;
		}
		if (ft_strncmp(input, lim, ft_strlen(lim)) == 0)
		{
			free(input);
			break ;
		}
		if (ft_strchr(input, '$') && noquote(cur, m, lim) == 0)
			pre_expand(fd, input, m);
		else
			write_it(fd, input);
		free(input);
	}
}

void	read_heredoc_next(t_cmd	*cur, t_master *m)
{
	int	fd;
	int	i;

	i = 0;
	while (cur->heredoc[i])
	{
		fd = open(cur->link[i], O_WRONLY | O_TRUNC);
		if (fd == -1)
		{
			printf("Error with open in heredoc\n");
			cur->error = 1;
			return ;
		}
		heredoc_loop(fd, cur->heredoc[i], cur, m);
		close(fd);
		i++;
	}
}

void	read_heredoc(t_cmd **cmd, t_master *m)
{
	t_cmd	*cur;

	cur = *cmd;
	while (cur)
	{
		if (cur->nb_heredoc > 0)
			read_heredoc_next(cur, m);
		cur = cur->next;
	}
}
