# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastian <abastian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 15:42:55 by daavril           #+#    #+#              #
#    Updated: 2025/03/28 11:11:48 by abastian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	gcc
FLAG		=	-Wall -Werror -Wextra -g3
LDFLAGS		=	-lreadline

C_FILE		=	lexer/extract_quoted_string.c lexer/extract_special_char.c lexer/extract_word.c lexer/get_special_type.c \
				lexer/lexer.c lexer/utils_token.c parser/expand_string.c parser/parser.c parser/utils_parser.c \
				parser/handle_redir.c parser/init_cmd_list.c parser/make_heredoc.c parser/merge_token.c parser/directory_check.c \
				parser/parse_cmd.c prompt_main/prompt.c prompt_main/free.c signals/signals.c executor/executor.c \
				builtins/ft_pwd.c builtins/ft_env.c builtins/ft_cd.c builtins/ft_unset.c builtins/ft_echo.c builtins/ft_exit.c \
				parser/file_management.c parser/read_heredoc.c builtins/ft_export.c

SRC_DIR		=	./src/
SRC			=	$(addprefix $(SRC_DIR), $(C_FILE))

OBJ_PATH	=	./obj/
OBJ			=	$(C_FILE:%.c=%.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a

$(OBJ_PATH)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;34m\nBuilding libft...\n"
	make -C $(LIBFT_DIR)
	@echo "\033[0;33m\nCOMPILING MINISHELL...\n"
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -L$(LIBFT_DIR) -lft
	@echo "\033[1;32m./minishell created\n"

clean:
	@echo "\033[0;31mDeleting minishell object files...\n"
	@rm -rf $(OBJ_PATH)
	make -C $(LIBFT_DIR) clean
	@echo "\033[1;32mDone\n"

fclean: clean
	@echo "\033[0;31mDeleting minishell executable...\n"
	@rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	@echo "\033[1;32mDone\n"

re: fclean all

.PHONY: all clean fclean re


