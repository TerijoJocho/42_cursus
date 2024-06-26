# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 12:32:20 by daavril           #+#    #+#              #
#    Updated: 2024/06/11 15:37:58 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC            = cc
CFLAGS        = -Wall -Wextra -Werror
AR = ar 
INCLUDE        =    -I include\
                -I libft

OBJS_DIR    =    obj/
OBJ            =    $(SRC_FILES:.c=.o)
OBJS        =    $(addprefix $(OBJS_DIR), $(OBJ))

SRCS_DIR    =    src/

SRC_FILES    =  ft_print_char.c \
                ft_print_p.c \
                ft_print_id.c \
                ft_print_str.c \
                ft_print_hexa.c \
                ft_print_undec.c \
                ft_printf.c \
#				main.c  
				
SRCS        =    $(addprefix $(SRCS_DIR), $(SRC_FILES))


LIBFT_PATH     = libft/
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
			@echo "Libft \033[1;32mOK\033[m"

$(NAME):    $(OBJS)
#			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDE)
			@cp $(LIBFT) $(NAME)
			@ar rcs $(NAME) $(OBJS) 
			@echo "$(GREEN)My Printf compiled!$(DEF_COLOR)"

clean:
			@rm -rf $(OBJS_DIR)
			@make clean -C $(LIBFT_PATH)

fclean:        clean
			@rm -rf $(NAME)
			@rm -rf $(LIBFT_PATH)$(LIBFT_NAME) 

re:         fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"
