/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:03:14 by daavril           #+#    #+#             */
/*   Updated: 2025/02/28 16:41:44 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

char	*get_path(t_clone *envp_clone)
{
	t_clone	*current;
	char	*path_envp;

	current = envp_clone;
	path_envp = NULL;
	while (current)
	{
		if (ft_strncmp(current->value, "PATH=", 5) == 0)
		{
			path_envp = current->value + 5;
		}
		current = current->next;
	}
	if (path_envp == NULL)
	{
		perror("PATH not found in environment");
		exit(EXIT_FAILURE);
	}
	return (path_envp);
}

int	is_intern(char *value, t_master **master)
{
	char	**path_dir;
	char	*full_path;
	int		i;

	path_dir = ft_split(get_path((*master)->env_clone), ':');
	i = 0;
	while (path_dir[i])
	{
		full_path = ft_strjoin(path_dir[i], "/");
		full_path = ft_strjoin(full_path, value);
		if (access(full_path, X_OK) == 0)
		{
			printf("path[%d] = %s\n",i , path_dir[i]);
			free(full_path);
			return (1);
		}
		free(full_path);
		i++;
	}
	return (0);
}

/*
Dans ta fonction init_cmd, tu vas initialiser une nouvelle commande en remplissant les champs de la structure t_cmd. Par exemple :

    args : une liste des arguments de la commande.
    infile et outfile : les fichiers d'entrée et de sortie associés à la commande (pour les redirections).
    path : le chemin de l'exécutable de la commande (trouvé via get_path et is_intern).
    append : flag pour les redirections avec ou sans append (ajout à la fin du fichier).
    next : un pointeur vers la commande suivante si nécessaire (pour les pipes
*/
void	init_cmd(t_master **master, t_token *cur_tok, t_cmd *cmd_list)
{
	cmd_list->args = cur_tok->value;
	
}

void	parse_cmd(t_master **master)
{
	t_token	*current;
	t_cmd	*cmd_list;

	cmd_list = malloc(sizeof(t_cmd));
	current = (*master)->token_list;
	while (current)
	{
		if (is_intern(current->value, master))
			init_cmd(master, current, cmd_list);
			// printf("yes\n");
		current = current->next;
	}
}
