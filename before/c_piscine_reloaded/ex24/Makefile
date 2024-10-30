# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:06:16 by daavril           #+#    #+#              #
#    Updated: 2024/05/16 17:50:03 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
SRCS = ./srcs/
INCLUDES = ./includes/
SOURCES = ft_putchar.c \
			ft_putstr.c \
			ft_strcmp.c \
			ft_strlen.c \
			ft_swap.c \

OBJS = ${addprefix ${SRCS}, ${SOURCES:.c=.o}}

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

${SRCS}%.o : ${SRCS}%.c
	${CC} ${CFLAGS} -I${INCLUDES} -o $@ -c $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all