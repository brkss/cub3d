
NAME =  cube3

SRC =  src/cube3d.c src/main.c src/map.c src/check.c src/gnl/get_next_line.c src/gnl/get_next_line_utils.c src/parser.c

OBJ = ${SRC:%.c=%.o}

FLAGS = -Wall -Werror -Wextra

MLX_INC = -I /usr/X11/include 

MLX_LINK = -L /usr/X11/lib -lmlx -framework OpenGL -framework AppKit

COMPILER = gcc 


all: $(NAME)

%.o:%.c
	$(COMPILER) -c $(FLAGS) $(MLX_INC) $< -o $@


$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS)  $(OBJ)  $(MLX_LINK) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

