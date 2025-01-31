/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:26:05 by daavril           #+#    #+#             */
/*   Updated: 2025/01/31 11:28:25 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
#define MINISHELL_H

#include "lexer.h"


/*Struct of minishell*/
typedef struct s_master
{
	struct s_token	*token_struct;
}		t_master;

#endif