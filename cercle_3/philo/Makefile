# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 09:06:01 by daavril           #+#    #+#              #
#    Updated: 2024/12/10 09:13:11 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
HEADER = philo.h
SRCS = main.c ft_parsing.c ft_init.c ft_threads.c ft_routine.c ft_monitor.c utils.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "\033[1;32mPhilosophers has been built\033[m"

clean:
	rm -f $(OBJS)

fclean: clean
	@echo "\033[0;93mCleaning\033[0;93m"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
