/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:30:55 by abastian          #+#    #+#             */
/*   Updated: 2025/02/10 14:17:10 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "../../libft/libft.h"
# include <stdio.h>

typedef enum e_real
{
	ARG = 1,
	ECHO = 2,
	CD = 3,
	PWD = 4,
	EXPORT = 5,
	UNSET = 6,
	ENV = 7,
	EXIT = 8,
	PIPE = 9,
	REDIR_IN = 10,
	REDIR_OUT = 11,
	APPEND = 12,
	HEREDOC = 13,
	STRING = 14
}		t_real;

typedef struct s_token
{
	char			*value;
	int				type;
	int				is_expand;
	int				quote_flag;
	t_real			real;
	struct s_token	*prev;
	struct s_token	*next;
}		t_token;

int		is_special_char(char c);
int		check_quote(char *input);

/*Prototypes--------------------------------*/
/*lexer--------------*/
int		lexer(char *input, t_token **token_list);
int		check_quote(char *input);
int		is_whitespace(char c);
int		is_special_char(char c);
void	add_token_list(t_token **token_list, int type, char *value);

void	add_token_back(t_token **lst, t_token *new);
void	token_clear(t_token **lst);
char	*extract_special_char(char *input);
int		is_sequence(char *input, char *sequence);
int		special_char_len(char *input);
char	*extract_quoted_string(char *input, char quote);
int		quoted_string_len(char *input, t_token **token_list);
char	*extract_word(char *input);
int		word_len(char *input);
void	get_special_type(t_token **token_list);
void	choose_real(char *value, t_real *real);

#endif
