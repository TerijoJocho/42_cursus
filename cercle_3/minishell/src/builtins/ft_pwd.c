/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:45:10 by daavril           #+#    #+#             */
/*   Updated: 2025/03/06 16:09:28 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//affiche le chemin absolu du repertoire actuel

void	ft_pwd()
{
	char	buf[1024]; //1024 car c'est un choix courant en LINUX mais si on veut faire qqchose de plus secur on peut malloc avec PATH_MAX

	getcwd(buf, sizeof(buf));
	printf("%s", buf);
	return ;
}

/*test*/
int	main()
{
	ft_pwd();
	return (0);
}
/*----*/
