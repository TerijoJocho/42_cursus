/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:31:59 by abastian          #+#    #+#             */
/*   Updated: 2025/03/24 11:41:26 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

// int	make_heredoc_next(t_cmd *cmd)
// {
// 	int	fd;

// 	fd = open("nom", O_CREAT | O_RDWR | O_TRUNC, 0600); //  O_TRUNC PAS SUR !!!!!!!
// 	if (fd == -1)
// }

// void	make_heredoc(t_cmd **cmd_list, t_token **token)
// {
// 	t_cmd	*cur_cmd;
// 	t_token	*cur;
// 	// int	i;

// 	// i = 0;
// 	cur_cmd = *cmd_list;
// 	cur = *token;
// 	while (cur_cmd)
// 	{
// 		if (cur_cmd->nb_heredoc != 0)
// 		{
// 			while (cur_cmd->nb_heredoc--)
// 			{
// 				if (!make_heredoc_next(cur_cmd)) //->heredoc[i]));
// 				{
// 					printf("Error while using open in heredoc management\n");
// 					return ;
// 				}
// 				// i++;
// 			}
// 			// i = 0;
// 		}
// 		cur_cmd = cur_cmd->next;
// 	}
// }
