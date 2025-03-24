/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:52:31 by abastian          #+#    #+#             */
/*   Updated: 2025/03/24 14:26:15 by daavril          ###   ########.fr       */
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

// void	ft_exit(t_cmd *cur_cmd)
// {
// 	int	i;
// 	int	keep;

// 	keep = 0;
// 	i = 0;
// 	if (!cur_cmd->args[0])
// 	{
// 		printf("Fatal error with exit and **args\n");
// 		return ;
// 	}
// 	if (!cur_cmd->args[1])
// 		exit();
// 	while (cur_cmd->args[i])
// 		i++;
// 	if (i > 2)
// 	{
// 		printf("exit command cant handle more than one option\n");
// 		return ;
// 	}
// 	i = 0;
// 	while (cur_cmd->args[1][i])
// 	{
// 		if (ft_isdigit(cur_cmd->args[1][i] == 0))
// 		{
// 			printf("exit cant handle non digit option\n");
// 			exit(2);
// 		}
// 		i++;
// 	}
// 	keep = ft_atoi(cur_cmd->args[1]);
// 	// if (keep < 0) FAIRE UN TRUC + verif long max etc
// 	exit(keep); // chatgpt dit : exit((unsigned char)exit_code); // On cast pour garder la cohérence avec bash
// }
