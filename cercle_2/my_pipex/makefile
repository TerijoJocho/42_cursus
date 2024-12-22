# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terijo <terijo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 10:55:35 by daavril           #+#    #+#              #
#    Updated: 2024/12/22 10:52:47 by terijo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = pipex.h
SRCS = main.c init_pipex.c parse_args.c ft_cleanup.c 
OBJS = $(SRCS:.c=.o)

# Inclure ft_printf
PRINTF_DIR = Lib_ft/printf/
PRINTF_LIB = $(PRINTF_DIR)libftprintf.a

# Inclure gnl
GNL_DIR = Lib_ft/gnl/
GNL_LIB = $(GNL_DIR)gnl.a

# Règles principales
all: $(NAME)

# Construire le programme principal
$(NAME): $(OBJS) $(PRINTF_LIB) $(GNL_LIB)
	@echo "\033[1;32mBuilding $(NAME)...\033[m"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF_LIB) $(GNL_LIB)
	@echo "\033[1;32m$(NAME) built successfully!\033[m"

# Règle pour les fichiers objets
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation de ft_printf
$(PRINTF_LIB):
	@echo "\033[0;34mBuilding ft_printf...\033[m"
	@$(MAKE) -C $(PRINTF_DIR)

# Compilation de gnl
$(GNL_LIB):
	@echo "\033[0;34mBuilding gnl...\033[m"
	@$(MAKE) -C $(GNL_DIR)

# Nettoyage des fichiers objets
clean:
	@echo "\033[0;93mCleaning object files...\033[m"
	rm -f $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean

# Nettoyage complet
fclean: clean
	@echo "\033[0;93mCleaning all files...\033[m"
	rm -f $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean

# Recompiler tout
re: fclean all

# Indiquer les cibles qui ne sont pas des fichiers
.PHONY: all clean fclean re


