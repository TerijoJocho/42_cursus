# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 15:23:41 by daavril           #+#    #+#              #
#    Updated: 2025/04/07 15:14:35 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIC
AR = ar
ARFLAGS = rcs
SRCS = libft_src/
HEADER = libft.h
SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memchr.c \
			ft_memcmp.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
			ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
			ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c \

OBJECTS = $(addprefix $(SRCS), $(SOURCES:.c=.o))
#BONUS_OBJECTS = $(addprefix $(SRCS), $(BONUS_SOURCES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "\033[1;32mBuilding libft...\033[m"
	$(AR) $(ARFLAGS) $@ $^
	@echo "\033[1;32mLibft OK\033[m"

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
