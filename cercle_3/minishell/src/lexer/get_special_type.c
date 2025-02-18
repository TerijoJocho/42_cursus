/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_special_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:20:20 by abastian          #+#    #+#             */
/*   Updated: 2025/02/18 13:24:08 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void	choose_real(char *value, t_real *real)
{
	if (ft_strncmp(value, "|", 1) == 0)
		*real = PIPE;
	else if (ft_strncmp(value, "<<", 2) == 0)
		*real = HEREDOC;
	else if (ft_strncmp(value, ">>", 2) == 0)
		*real = APPEND;
	else if (ft_strncmp(value, "<", 1) == 0)
		*real = REDIR_IN;
	else if (ft_strncmp(value, ">", 1) == 0)
		*real = REDIR_OUT;
}

void	find_word(char *value, t_real *real)
{
	if (ft_strlen(value) == 4 && ft_strncmp(value, "echo", 4) == 0) //ne pas oublier l'option -n
		*real = ECHO;
	else if (ft_strlen(value) == 2 && ft_strncmp(value, "cd", 2) == 0)
		*real = CD;
	else if (ft_strlen(value) == 3 && ft_strncmp(value, "pwd", 2) == 0)
		*real = PWD;
	else if (ft_strlen(value) == 6 && ft_strncmp(value, "export", 2) == 0)
		*real = EXPORT;
	else if (ft_strlen(value) == 5 && ft_strncmp(value, "unset", 2) == 0)
		*real = UNSET;
	else if (ft_strlen(value) == 3 && ft_strncmp(value, "env", 2) == 0)
		*real = ENV;
	else if (ft_strlen(value) == 4 && ft_strncmp(value, "exit", 2) == 0)
		*real = EXIT;
	else
		*real = ARG;
}

void	check_expand(t_token **token_list)
{
	int		i;
	t_token	*current;

	current = *token_list;
	while (current)
	{
		current->is_expand = 0;
		if (current->real == ARG && current->value[0] == '$')
		{
			i = 1;
			while (current->value[i] && ft_isalpha(current->value[i]))
				i++;
			if (i != 1)
				current->is_expand = 1;
		}
		if (current->real == STRING && current->quote_flag == 0)
		{
			i = 0;
			while (current->value[i] != '$' && current->value[i])
				i++;
			if (current->value[i] == '$' && ft_isalpha(current->value[i + 1]))
				current->is_expand = 1;
		}
		current = current->next;
	}
}

void	get_special_type(t_token **token_list)
{
	t_token	*current;

	current = *token_list;
	while (current)
	{
		if (current->type == 1)
			find_word(current->value, &current->real);
		else if (current->type == 2)
			choose_real(current->value, &current->real);
		else
			current->real = STRING;
		current = current->next;
	}
	check_expand(token_list);
}
