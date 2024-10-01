# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 11:44:25 by daavril           #+#    #+#              #
#    Updated: 2024/10/01 17:47:40 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = clang
CFLAGS = -Wall -Werror -Wextra -g
AR = ar
ARFLAGS = rcs
HEADER = push_swap.h
SRCS = main.c init_lst.c swap.c push.c\

OBJS = $(SRCS:.c=.o)

#inclu ft_printf
PRINTF_DIR = Lib_ft/printf/
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

#inclu gnl
GNL_DIR = Lib_ft/gnl/
GNL_LIB = $(GNL_DIR)/gnl.a

all: $(PRINTF_LIB) $(GNL_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

$(NAME): $(OBJS) $(PRINTF_LIB)
	@echo "\033[1;32mBuilding...\033[m"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(PRINTF_LIB) $(GNL_LIB)
	@echo "\033[1;32mEvrything OK\033[m"

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
