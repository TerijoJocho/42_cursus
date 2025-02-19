/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:07:53 by abastian          #+#    #+#             */
/*   Updated: 2025/02/19 14:58:31 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

/*exemple :
	bash-5.1$ echo "aaaaaaaa$HOMEaaaaaa"
	aaaaaaaa

	bash-5.1$ echo "aaaaaaaa$HOMEaaaaaa"
	aaaaaaaa

	bash-5.1$ echo aaaaaaaa$HOMEaaaaaa
	aaaaaaaa

	bash-5.1$ echo " aaaaaaaa$HOMEaaaaaa "
	aaaaaaaa

	bash-5.1$ echo " aaaaaaaaaaaaaa $HOME "
	aaaaaaaaaaaaaa /home/abastian

	bash-5.1$ echo " aaaaaaaaaaaaaa $HOME aaa "
	aaaaaaaaaaaaaa /home/abastian aaa

	bash-5.1$ echo " aaaaaaaaaaaaaa $HOMEaaa "
	aaaaaaaaaaaaaa

	bash-5.1$ echo " aaaaaaaaaaaaaa$HOME aaa "
	aaaaaaaaaaaaaa/home/abastian aaa

	bash-5.1$ echo " aaaaaaaa$HOMEaaaaaa e"
	aaaaaaaa e
*/
//Premiere idee
	// int	i;
	// t_clone	*cur_env;
	// char	*res;

	// res = NULL;
	// i = 0;
	// cur_env = *env;
	// while(token->value[i])
	// {
	// 	if (token->value[i] == '$')
	// 		fonction(&token->value[i], res);
	// 	if (res == NULL)
	// 		break;

	// 	i++;
	// }
	// token->value_2 = ft_substr(token->value, 0, i);
	// return (0);


// 2e idee

char	*extract_expand_2(char *str, int j)
{
	char	*new_value;
	int	i;

	i = 0;
	while (str[i])
		i++;
	new_value = malloc(sizeof(char) * i - j);
	if (!new_value)
		return (NULL);
	i = 0;
	while (str[j])
	{
		new_value[i++] = str[j++];
	}
	new_value[i] = '\0';
	printf("%s\n", new_value);
	return (new_value);
}

char	*take_var(char *value, t_clone **env)
{
	char	*var;
	int	i;
	t_clone	*cur_env;

	i = 0;
	cur_env = *env;
	while (value[i] && value[i] != ' ' && value[i] != '$')
		i++;
	var = malloc(sizeof(char) * i + 2);
	i = 0;
	while (value[i] && value[i] != ' ' && value[i] != '$')
	{
		var[i] = value[i];
		i++;
	}
	var[i++] = '=';
	var[i] = '\0';
	printf("var :%s\n", var);
	while (cur_env)
	{
		if (ft_strncmp(cur_env->value, var, i - 1) == 0)
		{
			printf("caca_2\n");
			var = extract_expand_2(cur_env->value, i);
			return (var);
		}
		cur_env = cur_env->next;
	}
	return (NULL);
}

int	expand_string(t_token *token, t_clone **env)
{
	int	i;
	char	*before;
	char	*tmp;
	char	*var;


	i = 0;
	tmp = NULL;
	var = NULL;
	before = NULL;
	while (token->value[i])
	{
		if (token->value[i] == '$')
		{
			before = ft_substr(token->value, 0, i);
			i++;
			printf("caca\n");
			tmp = take_var(&token->value[i], env);

		}
		else
			i++;
	}
	token->value = ft_strjoin(before, tmp);
	token->value_2 = var;
	printf("value_2: %s\n", token->value_2);
	if (token->value_2 == NULL)
		return (0);
	return (1);
}

/*3e idee
void	extract_expand_2(char *str, char *buffer)
{
	int	i;
	char	*expand;

	i = 0;
	expand = NULL;
	while (str[i] && str[i] != '=')
		i++;
	expand = ft_strdup(&str[i+1]); //prevoir free
	ft_strjoin(buffer, expand); //mdr mais du coup je dois free chaque strjoin avec une variable temp jpense
	free (expand);
	// printf("%s\n", value); PRESQUE LACHE PAS
}

int	expand_arg_for_string(char *value, char *buffer_og, t_clone **env)
{
	int	i;
	int	j;
	char buffer[70000]; //idee en attendant
	t_clone	*cur_env;

	i = 0;
	j = 0;
	cur_env = *env;
	if (value[0] != '$')
		return (printf("Fatal expand error\n"), 0);
	while (value[++i] && value[i] != ' ' && (value[i] != '$' || i == 0))
	{
		buffer[j] = value[i];
		j++;
	}
	buffer[i] = '\0';
	printf("valeur petit buffer : %s\n", buffer);
	while (cur_env)
	{
		if (ft_strncmp(cur_env->value, buffer, i - 1) == 0 &&
				cur_env->value[i - 1] == '=')
		{
			extract_expand_2(cur_env->value, buffer_og); // a voir
			return (i);
		}
		cur_env = cur_env->next;
	}
	return (-1);
}

int	expand_string(t_token *token, t_clone **env)
{
	int	i;
	int	get;
	char buffer[70000];

	get = 0;
	i = 0;
	while(token->value[i])
	{
		if (token->value[i] == '$')
		{
			get = expand_arg_for_string(&token->value[i], (char *)buffer, env);
			printf("get value : %d\n", get);
			if (get == -1)
				return (1); // free ????
			i += get;
		}
		else
		{
			buffer[i] = token->value[i];
			i++;
		}
		buffer[i] = '\0';
	}
	token->value_2 = ft_strdup(buffer);
	printf("token value_2 : %s\n token value_1 : %s\n", token->value_2, token->value);
	return (0);
}*/


/*

	bash-5.1$ echo " eeee $HOME $HOME 0"
 	eeee /home/abastian /home/abastian 0

	bash-5.1$ echo " eeee $HOME$HOME 0"
 	eeee /home/abastian/home/abastian 0

*/
