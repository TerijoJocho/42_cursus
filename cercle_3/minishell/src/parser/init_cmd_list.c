/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:28:46 by abastian          #+#    #+#             */
/*   Updated: 2025/03/24 12:32:23 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

char	**ft_outfile(t_token *token)
{
	char	**tab;
	t_token	*cur;
	int	i;

	cur = token;
	i = 0;
	while (cur && cur->real != PIPE)
	{
		if (cur->real == REDIR_OUT || cur->real == APPEND)
			i++;
		cur = cur->next;
	}
	tab = ft_calloc(i + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

char	**ft_infile(t_token *token)
{
	char	**tab;
	t_token	*cur;
	int	i;

	cur = token;
	i = 0;
	while (cur && cur->real != PIPE)
	{
		if (cur->real == REDIR_IN)
			i++;
		cur = cur->next;
	}
	tab = ft_calloc(i + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

char	**ft_heredoc(t_token *token)
{
	char	**tab;
	t_token	*cur;
	int	i;

	cur = token;
	i = 0;
	while (cur && cur->real != PIPE)
	{
		if (cur->real == HEREDOC)
			i++;
		cur = cur->next;
	}
	tab = ft_calloc(i + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	return (tab);
}

void	init_cmd_list_2(t_cmd **cmd, int i, t_token *token)
{
	(*cmd)->args = ft_calloc(i + 1, sizeof(char *));
	(*cmd)->infile = ft_infile(token);
	(*cmd)->outfile = ft_outfile(token);
	(*cmd)->path = NULL;
	(*cmd)->append = 0;
	(*cmd)->nb_heredoc = 0;
	(*cmd)->heredoc = ft_heredoc(token);
	(*cmd)->next = NULL;
	(*cmd)->error = 0;
	if (token && token->real >= 2 && token->real <= 8)
		(*cmd)->builtins = token->real;
	else
		(*cmd)->builtins = 0;
}

void	init_cmd_list(t_master **master, int i)
{
	t_token	*cur;
	t_cmd	*new_cmd;
	t_token	*head;

	cur = (*master)->token_list;
	while (cur)
	{
		i = 1;
		head = cur;
		while (cur->next && cur->next->type != 2)
		{
			i++;
			cur = cur->next;
		}
		while (cur->next && cur->real != PIPE)
			cur = cur->next;
		new_cmd = malloc(sizeof(t_cmd));
		if (!new_cmd)
			return ;
		ft_bzero(new_cmd, sizeof(t_cmd));
		init_cmd_list_2(&new_cmd, i, head); // verifier si cur est NULL ou pas?
		cmd_add_back(master, new_cmd);
		cur = cur->next;
		if (cur == NULL)
			break ;
	}
}

/*
Dans ta fonction init_cmd, tu vas initialiser une nouvelle commande en remplissant les champs de la structure t_cmd. Par exemple :

    args : une liste des arguments de la commande.
    infile et outfile : les fichiers d'entrée et de sortie associés à la commande (pour les redirections).
    path : le chemin de l'exécutable de la commande (trouvé via get_path et is_intern).
    append : flag pour les redirections avec ou sans append (ajout à la fin du fichier).
    next : un pointeur vers la commande suivante si nécessaire (pour les pipes
*/
// void	init_cmd(t_master **master, t_token *cur_tok, t_cmd *cmd_list)
// {
// 	cmd_list->args = cur_tok->value;

// }

// void	parse_cmd(t_master **master)
// {
// 	t_token	*current;
// 	t_cmd	*cmd_list;

// 	cmd_list = malloc(sizeof(t_cmd));
// 	current = (*master)->token_list;
// 	while (current)
// 	{
// 		if (is_intern(current->value, master))
// 			init_cmd(master, current, cmd_list);
// 			// printf("yes\n");
// 		current = current->next;
// 	}
// }
