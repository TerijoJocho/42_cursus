/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:52:31 by abastian          #+#    #+#             */
/*   Updated: 2025/03/26 11:49:18 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* exit quitte le shell au moment ou il est rencontre

il prend en argument soit rien soit un seul autre arg

si il a trop d'arg, il envoie une erreur et ne quitte pas (dans tous les autres cas, il quittera)

si on ne lui donne rien, il quitte avec 0, si on lui donne un chiffre il quitte avec ce chiffre

si on lui donne qq chose qui n'est pas des chiffres, il affiche une erreur et quitte avec 2 (code erreur)

si le chiffre donne depasse LONG MIN ou LONG MAX, affiche une erreur et quitte avec 2

exit convertit en positif si on lui donne un chiffre negatif :
exemple de chatgpt : [exit -5 : Quitte avec 251 (-5 en unsigned char)]

PISTE :

faut il rajouter a notre boucle while infinie dans notre prompt une condition avec une variable dans master genre
while (1 && master->exit_flag != 1) ?
En vrai je ne pense pas car ce serait trop simple pour etre viable, et puis le programme va quand meme vouloir finir sa boucle
Je pense qu'il faut faire comme avec les signaux
Mais attends jsuis con jme  prends la tete j'ai juste a use exit tout court... nan ah ptn mais est-ce que ca va finir le prog ???
*/

int	get_value(char *arg)
{
	int	keep;
	keep = ft_atoi(arg);

	if (keep < 0)
		keep *= -1;
	if (keep > 255)
		keep = (keep % 256);
	return (keep);
}

void	clean_exit(int value, t_master *master, int flag)
{
	free_all(master);
	clean_env(&master->env_clone); // adresse de env_clone ?
	clean_env(&master->export_list);
	if (master)
	{
		free(master);
		master = NULL;
	}
	if (flag == 1)
		printf("exit\n");
	exit(value);
}

void	ft_exit(t_master *master, t_cmd *cur_cmd)
{
	int	i;
	int	keep;

	keep = 0;
	i = 0;
	if (!cur_cmd->args[1])
		clean_exit(0, master, 1);
	if (cur_cmd->args[2])
	{
		printf("exit: too many arguments\n");
		return ;
	}
	while (cur_cmd->args[1][i])
	{
		if (ft_isdigit(cur_cmd->args[1][i]) == 0)
		{
			printf("exit: %s: numeric argument required\n", cur_cmd->args[1]);
			clean_exit(2, master, 1);
		}
		i++;
	}
	keep = get_value(cur_cmd->args[1]);
	clean_exit(keep, master, 1);
}
