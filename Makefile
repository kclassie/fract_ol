NAME = fractol

SRC = fract_ol.c

HEADER = fract_ol.h

LIB_PATH = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

FRAMES = -framework OpenGL -framework AppKit

OBJ = ${SRC: %.c=%.o}$

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		@$(MAKE) -C ./libft
		$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -lmlx $(FRAMES) -o $(NAME)

clean:
	rm -f *.o
	@$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: bonus all clean fclean re

