/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:26:05 by daavril           #+#    #+#             */
/*   Updated: 2025/02/10 16:37:06 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
#define MINISHELL_H

#include "../src/lexer/lexer.h"
#include "../src/prompt_main/prompt.h"
#include "../src/lexer/lexer.h"



/*Struct of minishell*/
typedef struct s_master
{
	t_token	*token_list;
	t_clone	*env_clone;
}		t_master;

#endif