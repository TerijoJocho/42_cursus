# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 12:32:20 by daavril           #+#    #+#              #
#    Updated: 2024/09/20 15:51:30 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC            = cc
CFLAGS        = -Wall -Wextra -Werror
AR = ar
INCLUDE        =    -I ft_printf.h\

OBJS_DIR    =    obj/
OBJ            =    $(SRC_FILES:.c=.o)
OBJS        =    $(addprefix $(OBJS_DIR), $(OBJ))

SRCS_DIR    =    printf_src/

SRC_FILES    =  ft_print_char.c \
                ft_print_p.c \
                ft_print_id.c \
                ft_print_str.c \
                ft_print_hexa.c \
                ft_print_undec.c \
                ft_printf.c \
#				main.c

SRCS        =    $(addprefix $(SRCS_DIR), $(SRC_FILES))


LIBFT_PATH     = ../libft/
LIBFT_NAME    = libft.a
LIBFT        = $(LIBFT_PATH)$(LIBFT_NAME)

NORME_ME    =    norminette -R CheckForbiddenSourceHeader

# RAINBOOOW

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all:        $(LIBFT) $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
			@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJS): $(OBJS_DIR)

$(OBJS_DIR):
		@mkdir -p $(OBJS_DIR)

$(LIBFT):
			@make -sC $(LIBFT_PATH)

$(NAME):    $(OBJS)
#			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDE)
			@echo "\033[1;32mBuilding printf...\033[m"
			@cp $(LIBFT) $(NAME)
			@ar rcs $(NAME) $(OBJS)
			@echo "\033[1;32mPrintf OK\033[m"

clean:
			@rm -rf $(OBJS_DIR)
			@make clean -C $(LIBFT_PATH)

fclean:        clean
			@rm -rf $(NAME)
			@rm -rf $(LIBFT_PATH)$(LIBFT_NAME)

re:         fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"
