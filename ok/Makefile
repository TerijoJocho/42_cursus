# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 23:34:41 by terijo            #+#    #+#              #
#    Updated: 2024/05/28 15:07:59 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
CC = gcc -Wall -Wextra -Werror
SRC = $(shell find . -name 'ft_*' '!' -iname 'ft_lst*')
SRC_BONUS = $(shell find . -name 'ft_lst*')
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME).a $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME).a $(NAME).so

re: fclean all

bonus : $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME).a $(OBJS) $(OBJS_BONUS)
