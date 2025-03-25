/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:18:11 by abastian          #+#    #+#             */
/*   Updated: 2025/03/24 16:49:18 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void	fill_redir(t_cmd **cmd, int in, int *i, t_token **token)
{
	if (in == 0)
	{
		if (!(*token)->value_2)
			(*cmd)->outfile[*i] = ft_strdup((*token)->value);
		else
			(*cmd)->outfile[*i] = ft_strdup((*token)->value_2);
		if ((*token)->prev->real == APPEND)
			(*cmd)->append[*i] = 1;
		else
			(*cmd)->append[*i] = 0; // mettre peut etre au niveau du token  ? car si on a append puis pas append on va mettre append a 0 a tord
	}
	else
	{
		if (!(*token)->value_2)
			(*cmd)->infile[*i] = ft_strdup((*token)->value);
		else
			(*cmd)->infile[*i] = ft_strdup((*token)->value_2);
	}
	(*i)++;
}

void	fill_heredoc(t_cmd **cmd, int *i, t_token **token)
{
	(*cmd)->heredoc[*i] = ft_strdup((*token)->value);
	(*cmd)->nb_heredoc += 1;
	(*i)++;
}
// void	fill_heredoc(t_cmd **cmd, t_token **token)
// {
// 	if ((*cmd)->heredoc != NULL)
// 	{
// 		open(".heredoc", O_WRONLY | O_CREATE | O_TRUNC, 0644);
// 	}
// }


void	handle_redir(t_master **master, int i, int j, int h)
{
	t_token	*cur;
	t_cmd	*cmd_list;

	if (!master || !*master)
		return ;
	cur = (*master)->token_list;
	cmd_list = (*master)->cmd_list;
	while (cur && cmd_list)
	{
		if (cur->real == REDIR_IN)
			fill_redir(&cmd_list, 1, &i, &cur->next);
		else if (cur->real == REDIR_OUT || cur->real == APPEND)
			fill_redir(&cmd_list, 0, &j, &cur->next);
		else if (cur->real == HEREDOC)
			fill_heredoc(&cmd_list, &h, &cur->next);
		cur = cur->next;
		if (cur && cur->real == PIPE)
		{
			cmd_list = cmd_list->next;
			cur = cur->next;
			i = 0;
			j = 0;
			h = 0;
		}
	}
}

// void	handle_redir(t_master **master)
// {
// 	t_token	*cur;
// 	t_cmd	*cmd_list;

// 	cur = (*master)->token_list;
// 	cmd_list = (*master)->cmd_list;
// 	while (cur && cmd_list)
// 	{
// 		if (cur->real == REDIR_IN)
// 			fill_redir(&cmd_list, 1, &cur->next);
// 		else if (cur->real == HEREDOC)
// 			fill_redir(&cmd_list, 1, &cur->next);
// 		else if (cur->real == APPEND)
// 			fill_redir(&cmd_list, 0, &cur->next);
// 		else if (cur->real == REDIR_OUT)
// 			fill_redir(&cmd_list, 0, &cur->next);
// 		outinfile_checker(&cmd_list);
// 		cur = cur->next;
// 		if (cur && cur->real == PIPE)
// 		{
// 			cmd_list = cmd_list->next;
// 			cur = cur->next;
// 		}
// 	}
// }
