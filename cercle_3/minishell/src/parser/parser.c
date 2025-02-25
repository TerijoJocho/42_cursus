/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:40:34 by daavril           #+#    #+#             */
/*   Updated: 2025/02/25 15:01:37 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

int	check_is_expand(t_token **token_list, t_clone **env)
{
	t_token	*current;
	char	*cpy;

	current = *token_list;
	while (current)
	{
		cpy = ft_strdup(current->value);
		printf("value before expand: %s\n", cpy);
		if (current->is_expand == 1)
		{
			if (!expand_string(current, env, cpy))
				return (1);
		}
		current = current->next;
		free(cpy);
	}
	return (0); // des int partout ? je pense que je me perds
}

int	parser(t_master *master)
{
	if (check_is_expand(&master->token_list, &master->env_clone) == 1)
		return (printf("PROBLEME EXPAND\n"), 1);
	parse_cmd(&master);
	return (0);
}


// char *expand_variable(char *var_name) {
//     char *value = getenv(var_name);
//     if (value)
//         return ft_strdup(value);  // Si défini, retourner la valeur
//     return ft_strdup("");         // Sinon, retourner une string vide
// }
