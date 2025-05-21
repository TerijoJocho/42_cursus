# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terijo <terijo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 00:52:43 by terijo            #+#    #+#              #
#    Updated: 2025/05/22 01:55:57 by terijo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Repertoire
CC	 = g++
CFLAGS = -Wall -Werror -Wextra -std=c++98

#directories
SRC_DIR = Contact/ PhoneBook/
OBJ_DIR = obj/
INC_DIR = Contact/

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
SRC_PATH = Contact/contactClass.cpp PhoneBook/phoneBookClass.cpp main.cpp
OBJ_PATH = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

#all rule
all: $(NAME)
		@printf "$(BLUE)Welcome to EX00 of CPP\n$(RESET)"

#compile the executable
$(NAME): $(OBJ_PATH)
		@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
		@$(CC) $(CFLAGS) $(OBJ_PATH) -o $(NAME)
		@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

#compile objects
$(OBJ_DIR)%.o: Contact/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling Contact [$<]...$(RESET)"
	@$(CC) $(CFLAGS) -I Contact/ -I PhoneBook/ -c $< -o $@

$(OBJ_DIR)%.o: Phonebook/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling Phonebook [$<]...$(RESET)"
	@$(CC) $(CFLAGS) -I Contact/ -I PhoneBook/ -c $< -o $@
	
$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) -I Contact/ -I Phonebook/ -o $@ -c $<
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