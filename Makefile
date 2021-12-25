NAME = fractol
LIBFT_NAME = libft.a
MAIN_NAME = fractol.c
HFILENAME = fractol.h

SRC_NAME = fractol.c calculate_fractals.c color_functions.c mouse_press_button_control.c \
	keyboard_control.c init.c utils.c draw_fractal.c mouse_motion_control.c

CC = gcc

LIB_PATH = libft/

MLX = -lmlx -framework OpenGL -framework Appkit
FLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_BONUS_NAME = $(SRC_NAME:.c=.o)

SRC = $(SRC_NAME)
OBJ = $(OBJ_NAME)
LIBFT = $(addprefix $(LIB_PATH), $(LIBFT_NAME))

all:
	@$(MAKE) -C $(LIB_PATH)
	@$(MAKE) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -Imlx -o $@ -c $<

$(NAME): $(OBJ) $(HFILENAME) $(LIBFT) Makefile
	@$(CC) $(FLAGS) $(LIBFT) $(MLX) $(OBJ) -o $(NAME)

bonus: all

clean:
	@$(MAKE) -C $(LIB_PATH) clean
	@rm -rf $(OBJ_NAME)


fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re bonus run
