# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 15:01:40 by daavril           #+#    #+#              #
#    Updated: 2024/09/12 16:26:01 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
SRCS = gnl_src/
HEADER = get_next_line.h
SOURCES = get_next_line.c get_next_line_utils.c

OBJECTS = $(addprefix $(SRCS), $(SOURCES:.c=.o))
#BONUS_OBJECTS = $(addprefix $(SRCS), $(BONUS_SOURCES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "\033[1;32mBuilding gnl...\033[m"
	$(AR) $(ARFLAGS) $@ $^
	@echo "\033[1;32mGnl OK\033[m"

$(SRCS)%.o: $(SRCS)%.c
	$(CC) $(CFLAGS) -I$(HEADER) -o $@ -c $<

#bonus : $(BONUS_OBJECTS)
#$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJECTS)

clean:
	rm -f $(OBJECTS)
#$(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all


