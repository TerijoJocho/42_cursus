/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:38:05 by daavril           #+#    #+#             */
/*   Updated: 2025/02/21 16:48:39 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void	clean_env(t_clone **lst)
{
	t_clone	*current;

	current = *lst;
	while (current)
	{
		if (current->value != NULL)
			free(current->value);
		current = current->next;
	}
	while (*lst)
	{
		current = (*lst)->next;
		free(*lst);
		*lst = current;
	}
	*lst = NULL;
}

void	clean_values(t_token **lst)
{
	t_token	*current;

	current = *lst;
	while (current)
	{
		if (current->value != NULL)
			free(current->value);
		if (current->value_2 != NULL)
			free(current->value_2);
		current = current->next;
	}
}

void	free_all(t_master *master)
{
	clean_values(&master->token_list);
	token_clear(&master->token_list); //pour liberer tous les neeouds
	clean_env(&master->env_clone); //clean les neouds de l'env
}
