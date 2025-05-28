# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daavril <daavril@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 00:52:43 by terijo            #+#    #+#              #
#    Updated: 2025/05/23 12:58:46 by daavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Repertoire
CC	 = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

#directories
SRC_DIR = Contact/ phoneBook/
OBJ_DIR = obj/
INC_DIR = Contact/ phoneBook/

#controll codes
RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K

#sources files
SRC_FILES = contactClass.cpp phoneBookClass.cpp main.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

#paths
SRC_PATH = Contact/contactClass.cpp phoneBook/phoneBookClass.cpp main.cpp
OBJ_PATH = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

#all rule
all: $(NAME)
		@printf "$(BLUE)Welcome to EX01 of CPP00\n$(RESET)"

#compile the executable
$(NAME): $(OBJ_PATH)
		@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
		@$(CC) $(CFLAGS) $(OBJ_PATH) -o $(NAME)
		@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

#compile objects
$(OBJ_DIR)%.o: Contact/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling Contact [$<]...$(RESET)"
	@$(CC) $(CFLAGS) -I Contact/ -I phoneBook/ -c $< -o $@

$(OBJ_DIR)%.o: phoneBook/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling phoneBook [$<]...$(RESET)"
	@$(CC) $(CFLAGS) -I Contact/ -I phoneBook/ -c $< -o $@

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) -I Contact/ -I phoneBook/ -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(BLUE)Deleting all objects from /ex01...$(RESET)"; else \
	echo "No objects to remove from /ex01."; \
	fi;

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(BLUE)Deleting $(NAME) from ex01...$(RESET)"; else \
	echo "No Executable to remove from ex01."; \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re
