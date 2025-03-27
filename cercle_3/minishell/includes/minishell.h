/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:26:05 by daavril           #+#    #+#             */
/*   Updated: 2025/03/27 12:25:39 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

/*clone envp*/
typedef struct s_clone
{
	char			*value;
	struct s_clone	*prev;
	struct s_clone	*next;
}					t_clone;

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
}					t_real;

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
	int				real; // changemenet en int
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

/*Struct of cmd*/
typedef struct s_cmd
{
	char			**args;
	char			**infile;
	char			**outfile;
	char			*path;
	int				*append;
	int				nb_heredoc;
	char			**heredoc;
	char			**link;
	int				pfd[2];
	int				error;
	int				builtins;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

/*Struct of minishell*/
typedef struct s_master
{
	t_token			*token_list;
	t_clone			*env_clone;
	t_clone			*export_list;
	char			**env;
	t_cmd			*cmd_list;
	int				exit_status;
}					t_master;

/*Lexer's prototype*/
int					is_special_char(char c);
int					check_quote(char *input);

int					lexer(char *input, t_token **token_list);
int					check_quote(char *input);
int					is_whitespace(char c);
int					is_special_char(char c);
int					is_quote(char c);
void				add_token_list(t_token **token_list, int type, char *value);

void				add_token_back(t_token **lst, t_token *new);
void				token_clear(t_token **lst);
char				*extract_special_char(char *input);
int					is_sequence(char *input, char *sequence);
int					special_char_len(char *input, t_token **token_list);
char				*extract_quoted_string(char *input, char quote);
int					quoted_string_len(char *input, t_token **token_list);
char				*extract_word(char *input);
int					word_len(char *input, t_token **token_list);
void				get_special_type(t_token **token_list);
void				choose_real(char *value, t_token *token);
/*-----------------*/

/*Parser's prototype*/
int		parser(t_master *master);
int		syntax_check(t_token **token_list);
int		expand_string(t_token *token, t_clone **env, char *cpy);
int		check_is_expand(t_token **token_list, t_clone **env);
void	parse_cmd(t_master **master, int i, int flag);
void	directory_check(t_token **token_list);
void	merge_token(t_token **token_list);
void	init_cmd_list(t_master **master, int i);
void	cmd_add_back(t_master **master, t_cmd *node);
void	handle_redir(t_master **master, int i, int j, int h);
void	file_management(t_cmd **cmd);
int		*ft_append(t_token *token);
int		make_heredoc(char **heredoc, int *error, char **link);

/*------------------*/

/*free functions*/
void				free_all(t_master *master);
void				clean_env(t_clone **lst);
void				free_tab(char **tab);
void				clean_exit(int value, t_master *master, int flag);
/*------------------*/

/*Executor's prototype*/
int					executor(t_master *master);
char	**clone_tab_env(t_clone *env, int size);

/*Builtins*/
void				ft_pwd(void);
void				ft_env(t_master *master);
int					ft_cd(t_master *master, t_cmd *cmd);
void	ft_unset(t_master *master, t_cmd *cur_cmd);
void	delete_node(t_clone **head, t_clone *ec);
void	ft_echo(t_cmd *cur_cmd, int i, t_master *master);
void	ft_export(t_master *master, t_cmd *cur_cmd);
void	ft_exit(t_master *master, t_cmd *cur_cmd, int flag);

#endif
