/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abastian <abastian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:30:55 by abastian          #+#    #+#             */
/*   Updated: 2025/01/28 15:33:50 by abastian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "../libft/libft.h"
# include <stdio.h>

typedef enum e_real
{
	WORD = 1,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HEREDOC,
	STRING
}		t_real;

typedef struct s_token
{
	char			*value;
	int				type;
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
int		quoted_string_len(char *input);
char	*extract_word(char *input);
int		word_len(char *input);
void	get_special_type(t_token **token_list);
void	choose_real(char *value, t_real *real);

#endif
