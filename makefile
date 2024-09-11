# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 10:55:35 by daavril           #+#    #+#              #
#    Updated: 2024/09/11 13:31:12 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
UNAME = $(shell uname)
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
HEADER = so_long.h
SRCS = so_long.c \

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
PRINTF_DIR = ./libftprintf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(PRINTF_LIB) $(MLX_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES) -I$(HEADER)

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(PRINTF_LIB)

$(PRINTF_LIB):
	@echo "\033[1;32mBuilding libftprintf\033[m"
	@make -C $(PRINTF_DIR)

$(MLX_LIB):
	@echo "\033[1;32mBuilding minilibx\033[m"
	@make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(PRINTF_LIB)

re: fclean all

.PHONY: all clean fclean re
