/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:26:05 by daavril           #+#    #+#             */
/*   Updated: 2025/03/10 15:13:12 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

# include "../libft/libft.h"

/*clone envp*/
typedef struct s_clone
{
	char			*value;
	struct s_clone	*prev;
	struct s_clone	*next;
}		t_clone;

/*structures token*/
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
	char			*value_2;
	int				type;
	int				is_expand;
	int				quote_flag;
	int				space;
	int				dir;
	int				prog;
	t_real			real;
	struct s_token	*prev;
	struct s_token	*next;
}		t_token;

/*Struct of cmd*/
typedef struct s_cmd
{
	char **args;
	char *infile;
	char *outfile;
	char *path;
	int	append;
	int	pfd[2];
	int	error;
	struct s_cmd *next;
}	t_cmd;

/*Struct of minishell*/
typedef struct s_master
{
	t_token	*token_list;
	t_clone	*env_clone;
	char	**env;
	t_cmd	*cmd_list;
}		t_master;


/*Lexer's prototype*/
int		is_special_char(char c);
int		check_quote(char *input);

int		lexer(char *input, t_token **token_list);
int		check_quote(char *input);
int		is_whitespace(char c);
int		is_special_char(char c);
int		is_quote(char c);
void	add_token_list(t_token **token_list, int type, char *value);

void	add_token_back(t_token **lst, t_token *new);
void	token_clear(t_token **lst);
char	*extract_special_char(char *input);
int		is_sequence(char *input, char *sequence);
int		special_char_len(char *input, t_token **token_list);
char	*extract_quoted_string(char *input, char quote);
int		quoted_string_len(char *input, t_token **token_list);
char	*extract_word(char *input);
int		word_len(char *input, t_token **token_list);
void	get_special_type(t_token **token_list);
void	choose_real(char *value, t_real *real);
/*-----------------*/

/*Parser's prototype*/
int	parser(t_master *master);
int	syntax_check(t_token **token_list);
int	expand_arg(t_token *token, t_clone **env);
int	expand_string(t_token *token, t_clone **env, char *cpy);
void	parse_cmd(t_master **master);
void	directory_check(t_token **token_list);

/*------------------*/

/*free functions*/
void	free_all(t_master *master);
void	clean_env(t_clone **lst);
/*------------------*/

/*Executor's prototype*/
int    executor(t_master *master);

#endif
