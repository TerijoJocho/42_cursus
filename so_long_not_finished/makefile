# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 10:55:35 by daavril           #+#    #+#              #
#    Updated: 2024/09/23 16:04:36 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
UNAME = $(shell uname)
CC = clang
CFLAGS = -Wall -Werror -Wextra -g
AR = ar
ARFLAGS = rcs
HEADER = so_long.h
SRCS = core/so_long.c core/read_map.c core/get_map.c core/init_game.c core/map_check.c \
		core/map_check_utils.c core/map_playable.c core/init_window.c core/init_img.c core/move.c\

OBJS = $(SRCS:.c=.o)


#for universal compilation
ifeq ($(shell uname), Linux)
	MLX_DIR = ./minilibx/minilibx-linux
	INCLUDES = -I/usr/include -I$(MLX_DIR) -I$(PRINTF_DIR)/include
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_DIR = ./minilibx/minilibx-mms20200219
	INCLUDES = -I/opt/X11/include -I$(MLX_DIR) -I$(PRINTF_DIR)/include
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

#inclu ft_printf
PRINTF_DIR = Lib_ft/printf/
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

#inclu gnl
GNL_DIR = Lib_ft/gnl/
GNL_LIB = $(GNL_DIR)/gnl.a

all: $(PRINTF_LIB) $(GNL_LIB) $(MLX_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) -I$(HEADER)

$(NAME): $(OBJS) $(PRINTF_LIB)
	@echo "\033[1;32mBuilding...\033[m"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(PRINTF_LIB) $(GNL_LIB)
	@echo "\033[1;32mEvrything OK\033[m"

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

$(GNL_LIB):
	@make -C $(GNL_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	@echo "\033[0;93mCleaning...\033[0;93m"
	$(MAKE) -C Lib_ft/printf fclean
	$(MAKE) -C Lib_ft/gnl fclean

re: fclean all

.PHONY: all clean fclean re
