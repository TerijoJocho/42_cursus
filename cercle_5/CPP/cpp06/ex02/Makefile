NAME = Identify
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
SRC_FILES = main.cpp BaseClass/Base.cpp EmptyClasses/A.cpp EmptyClasses/B.cpp EmptyClasses/C.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

#paths
SRC_PATH =
OBJ_PATH = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

#all rule
all: $(NAME)
		@printf "$(BLUE)Welcome to EX02 of CPP06\n$(RESET)"

#compile the executable
$(NAME): $(OBJ_PATH)
		@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
		@$(CC) $(CFLAGS) $(OBJ_PATH) -o $(NAME)
		@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

#compile objects
$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

#clean rule
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(BLUE)Deleting all objects from /ex02...$(RESET)"; else \
	echo "No objects to remove from /ex02."; \
	fi;

#fclean rule
fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(BLUE)Deleting $(NAME) from ex02...$(RESET)"; else \
	echo "No Executable to remove from ex02."; \
	fi;

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re

#fclean rule
