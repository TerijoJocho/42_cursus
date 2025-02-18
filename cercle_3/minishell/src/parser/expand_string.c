/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:07:53 by abastian          #+#    #+#             */
/*   Updated: 2025/02/18 16:06:52 by abastian         ###   ########.fr       */
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
//	int	i;
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

char	*fonction(char *str, t_clone **env)
{
	int	i;
	char	*buffer;

	i = 1;
	while (str[i] && str[i] != ' ' && str[i] != '$')
	{

	}
	return (buffer);
}
void	get_i(int *tab, t_token *token)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (token->value[i])
	{
		if (token->value[i] == '$')
		{
			tab[j] = i;
			j++;
		}
		i++;
	}
}

int	expand_string(t_token *token, t_clone **env)
{
	int		*tab;
	char	*res;
	char	*buffer;
	int	k;
	int	j;
	int	i;

	k = 0;
	j = 0;
	i = 0;
	get_i(tab, token);
	while (tab[j])
	{
		if (token->value[i] == '$')
		{
			buffer = fonction(&token->value[tab[j]], env); //renvoie le reste de la string quand on atteint $
			autre_fonction(buffer, res); //cpy le buffer dans res
		}

		else
			res[k] = token->value[i];
		j++;
	}
}


/*

	bash-5.1$ echo " eeee $HOME $HOME 0"
 	eeee /home/abastian /home/abastian 0

	bash-5.1$ echo " eeee $HOME$HOME 0"
 	eeee /home/abastian/home/abastian 0

*/
