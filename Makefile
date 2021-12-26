NAME = fractol
MAIN_NAME = fractol.c
HEADER = fractol.h
LIBFT = libft/libft.a
LIBFT_PATH = libft/

SRC_NAME = fractol.c calculate_fractals.c mouse_events.c\
	key_events.c utils.c utils2.c draw_fractal.c

CC = gcc
MLX = -lmlx -framework OpenGL -framework Appkit
FLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_BONUS_NAME = $(SRC_NAME:.c=.o)

all:
	@$(MAKE) -C $(LIBFT_PATH)
	@$(MAKE) $(NAME)

$(NAME): $(OBJ_NAME) $(HEADER) $(LIBFT) Makefile
	@$(CC) $(FLAGS) $(LIBFT) $(MLX) $(OBJ_NAME) -o $(NAME)
	@echo "**********************************"
	@echo ✅ Fractol is compiled succesfully

bonus: all

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -f $(OBJ_NAME)
	@echo "**********************************"
	@echo ✅ Fractol objects are cleaned succesfully

fclean:
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -f $(OBJ_NAME)
	@rm -rf $(NAME)
	@echo "**********************************"
	@echo ✅ Fractol is deleted

re: fclean all

.PHONY: clean fclean re bonus
