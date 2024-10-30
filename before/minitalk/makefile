# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 10:55:35 by daavril           #+#    #+#              #
#    Updated: 2024/10/28 19:19:06 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra -g
AR = ar
ARFLAGS = rcs
HEADER = minitalk.h
CLIENT = client
SERVER = server

SRCS_CLIENT = client.c
SRCS_SERVER = server.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# inclure ft_printf
PRINTF_DIR = Lib_ft/printf/
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

# inclure gnl
GNL_DIR = Lib_ft/gnl/
GNL_LIB = $(GNL_DIR)/gnl.a

all: $(PRINTF_LIB) $(GNL_LIB) $(CLIENT) $(SERVER)

# client
$(CLIENT): $(OBJS_CLIENT) $(PRINTF_LIB) $(GNL_LIB)
		@echo "\033[1;32mBuilding client...\033[m"
		$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) $(PRINTF_LIB) $(GNL_LIB)
		@echo "\033[1;32mClient built successfully!\033[m"

# server
$(SERVER): $(OBJS_SERVER) $(PRINTF_LIB) $(GNL_LIB)
		@echo "\033[1;32mBuilding server...\033[m"
		$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) $(PRINTF_LIB) $(GNL_LIB)
		@echo "\033[1;32mServer built successfully!\033[m"

# object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# printf
$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

# gnl
$(GNL_LIB):
	@make -C $(GNL_DIR)

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	@echo "\033[0;93mCleaning...\033[0;93m"
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

