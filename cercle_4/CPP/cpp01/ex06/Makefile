# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/01 23:49:32 by terijo            #+#    #+#              #
#    Updated: 2025/06/13 16:10:50 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter
CC	 = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

#directories
SRC_DIR =
OBJ_DIR = obj/
INC_DIR =

#controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

#sources files
SRC_FILES = main.cpp Harl.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

#paths
SRC_PATH =
OBJ_PATH = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

#all rule
all: $(NAME)
		@printf "$(BLUE)Welcome to EX06 of CPP01\n$(RESET)"

#compile the executable
$(NAME): $(OBJ_PATH)
		@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
		@$(CC) $(CFLAGS) $(OBJ_PATH) -o $(NAME)
		@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

#compile objects
$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(BLUE)Deleting all objects from /ex06...$(RESET)"; else \
	echo "No objects to remove from /ex06."; \
	fi;

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(BLUE)Deleting $(NAME) from ex06...$(RESET)"; else \
	echo "No Executable to remove from ex06."; \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re

#fclean rule
