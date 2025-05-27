# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aistierl <aistierl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 15:13:42 by daavril           #+#    #+#              #
#    Updated: 2025/05/21 14:26:27 by aistierl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb -g3
INCLUDES = -Iincludes -I/usr/include -Imlx_linux -Ilibft -Ignl

SRC = src/main.c src/parsing/parsing.c src/parsing/parse_file.c src/exit/exit.c src/init/init.c \
      src/parsing/check_texture.c src/parsing/check_colors.c src/parsing/check_map.c \
      src/parsing/check_map_utils.c src/exec/img_util.c \
      src/raycasting/raycasting.c src/raycasting/raycasting_utils.c src/exec/movement.c \
      src/exec/rotation.c src/exec/movement_utils.c

BONUS_SRC = src_bonus/main.c src_bonus/parsing/parsing.c src_bonus/parsing/parse_file.c src_bonus/exit/exit.c src_bonus/init/init.c \
            src_bonus/parsing/check_texture.c src_bonus/parsing/check_colors.c src_bonus/parsing/check_map.c \
            src_bonus/parsing/check_map_utils.c src_bonus/exec/img_util.c \
            src_bonus/raycasting/raycasting_bonus.c src_bonus/raycasting/raycasting_utils.c src_bonus/raycasting/bonus_mini_map.c src_bonus/exec/movement_bonus.c \
            src_bonus/exec/rotation.c src_bonus/exec/movement_utils_bonus.c

OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:src/%.c=$(OBJ_DIR)/%.o)

MLX_DIR = ./mlx_linux
GNL_DIR = ./gnl
LIBFT_DIR = ./libft
GNL_LIB = $(GNL_DIR)/gnl.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

MLX_FLAGS = -L/usr/lib -lXext -lX11 -lm -lpthread -ldl -lz \
            $(MLX_LIB) $(LIBFT_LIB) $(GNL_LIB)

all: $(GNL_LIB) $(LIBFT_LIB) $(MLX_LIB) $(NAME)
	@echo "✅ $(NAME) built successfully!"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

bonus: $(GNL_LIB) $(LIBFT_LIB) $(MLX_LIB) $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX_FLAGS) -o $(NAME)
	@echo "✨ Bonus version built!"

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(GNL_LIB):
	@$(MAKE) -C $(GNL_DIR)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) clean -C $(GNL_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "🧹 CUB3D : Clean done"

fclean: clean
	@$(MAKE) fclean -C $(GNL_DIR)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "🔥 CUB3D : Full Clean done"

re: fclean all

.PHONY: all clean fclean re bonus
