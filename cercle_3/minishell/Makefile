# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/19 15:42:55 by daavril           #+#    #+#              #
#    Updated: 2025/03/03 13:15:46 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	gcc
FLAG		=	-Wall -Werror -Wextra -g3
LDFLAGS		=	-lreadline

C_FILE		=	lexer/extract_quoted_string.c lexer/extract_special_char.c lexer/extract_word.c lexer/get_special_type.c \
				lexer/lexer.c lexer/utils_token.c parser/expand_arg.c parser/expand_string.c parser/parser.c parser/syntax_parse.c \
				parser/parse_cmd.c parser/parser_2.c prompt_main/prompt.c prompt_main/free.c signals/signals.c

SRC_DIR		=	./src/
SRC			=	$(addprefix $(SRC_DIR), $(C_FILE))

OBJ_PATH	=	./obj/
OBJ			=	$(C_FILE:%.c=%.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

LIBFT_DIR	=	./libft/
LIBFT		=	$(LIBFT_DIR)libft.a

# Compilation des objets
$(OBJ_PATH)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAG) -c $< -o $@

# Compilation principale de minishell
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;34m\nBuilding libft...\n"
	make -C $(LIBFT_DIR)  # Compile la libft avec son propre Makefile
	@echo "\033[0;33m\nCOMPILING MINISHELL...\n"
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -L$(LIBFT_DIR) -lft
	@echo "\033[1;32m./minishell created\n"

# Nettoyage des fichiers objets
clean:
	@echo "\033[0;31mDeleting minishell object files...\n"
	@rm -rf $(OBJ_PATH)
	make -C $(LIBFT_DIR) clean  # Nettoie aussi la libft
	@echo "\033[1;32mDone\n"

# Suppression de l'exécutable
fclean: clean
	@echo "\033[0;31mDeleting minishell executable...\n"
	@rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean  # Supprime aussi libft.a
	@echo "\033[1;32mDone\n"

# Recompile tout
re: fclean all

.PHONY: all clean fclean re


