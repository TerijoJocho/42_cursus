# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 15:01:40 by daavril           #+#    #+#              #
#    Updated: 2025/04/28 13:32:42 by daavril          ###   ########.fr        #
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
	@echo "✅ $(NAME) built successfully!"

$(NAME): $(OBJECTS)
	@$(AR) $(ARFLAGS) $@ $^

$(SRCS)%.o: $(SRCS)%.c
	$(CC) $(CFLAGS) -I$(HEADER) -o $@ -c $<

#bonus : $(BONUS_OBJECTS)
#$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJECTS)

clean:
	@rm -f $(OBJECTS)
	@echo "🧹 GNL : Clean done"
#$(BONUS_OBJECTS)

fclean: clean
	@rm -f $(NAME)
	@echo "🔥 GNL : Full clean done"

re: fclean all


