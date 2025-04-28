NAME = cube3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g

SRC = src/main.c src/parsing/parsing.c src/parsing/parse_file.c src/exit/exit.c src/init/init.c \
		src/parsing/check_texture.c src/parsing/check_colors.c src/parsing/check_map.c

OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

GNL_DIR = gnl
LIBFT_DIR = libft
GNL_LIB = $(GNL_DIR)/gnl.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)
	@echo "✅ $(NAME) built successfully!"

$(NAME): $(OBJ) $(GNL_LIB) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(GNL_LIB) $(LIBFT_LIB)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(GNL_LIB):
	@$(MAKE) -C $(GNL_DIR)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) clean -C $(GNL_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "🧹 CUBE3D : Clean done"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(GNL_DIR)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "🔥 CUBE3D : clean done"

re: fclean all

.PHONY: all clean fclean re
