
NAME =  cube3

SRC =  src/cube3d.c src/main.c src/map.c src/check.c src/gnl/get_next_line.c src/gnl/get_next_line_utils.c src/parser.c src/scan_map.c

OBJ = ${SRC:%.c=%.o}

FLAGS = -Wall -Werror -Wextra

MLX_INC = -I /usr/X11/include 

MLX_LINK = -L /usr/X11/lib -lmlx -framework OpenGL -framework AppKit

COMPILER = gcc 

all: lib $(NAME) 

%.o:%.c
	$(COMPILER) -c $(FLAGS) $(MLX_INC) $< -o $@

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS)  $(OBJ) -L ./libft -lft $(MLX_LINK) -o $@

lib:
	@echo "compiling libft"
	make -C ./libft
	make bonus -C ./libft

clean: libftclean
	rm -rf $(OBJ)

libftclean:
	make clean -C ./libft

fclean: libftfclean clean
	rm -rf $(NAME)

libftfclean:
	make fclean -C ./libft

re: fclean all

