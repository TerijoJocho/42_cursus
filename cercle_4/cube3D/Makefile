# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terijo <terijo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 15:13:42 by daavril           #+#    #+#              #
#    Updated: 2025/05/06 13:56:02 by terijo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g

SRC = src/main.c src/parsing/parsing.c src/parsing/parse_file.c src/exit/exit.c src/init/init.c \
		src/parsing/check_texture.c src/parsing/check_colors.c src/parsing/check_map.c \
		src/parsing/check_map_utils.c

OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

GNL_DIR = gnl
LIBFT_DIR = libft
GNL_LIB = $(GNL_DIR)/gnl.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)
	@echo "✅ $(NAME) built successfully!"

$(NAME): $(OBJ) $(GNL_LIB) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(GNL_LIB) $(LIBFT_LIB)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(GNL_LIB):
	@$(MAKE) -C $(GNL_DIR)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) clean -C $(GNL_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "🧹 CUBD : Clean done"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(GNL_DIR)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "🔥 CUBD : clean done"

re: fclean all

.PHONY: all clean fclean re
