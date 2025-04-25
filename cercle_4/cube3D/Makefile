NAME = cube3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRC = src/main.c src/parsing/parsing.c src/parsing/parse_file.c
OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
GNL_DIR = gnl
LIBFT_DIR = libft
GNL_LIB = $(GNL_DIR)/gnl.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(GNL_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(GNL_LIB) $(LIBFT_LIB)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)/parsing
	$(CC) $(CFLAGS) -c $< -o $@

$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(GNL_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(GNL_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all