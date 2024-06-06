# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 12:32:20 by daavril           #+#    #+#              #
#    Updated: 2024/06/06 13:51:01 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDES = ./includes/
CC = cc
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_print_char.c ft_print_id.c ft_print_p.c ft_print_str.c \
		ft_printf_hexa.c ft_printf_undec.c main.c \

OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c -I $(INCLUDES) $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@make -C libft
	@cp libft/libft.a .
	@mv libft.a ${NAME}
	${AR} ${NAME} ${OBJS}
	@ranlib ${NAME}

clean:
	@make clean -C libft
	rm -f ${OBJS}

fclean:        clean
	rm -f libft/libft.a
	rm -f ${NAME}

re:    fclean all

.PHONY: all clean fclean re libft

