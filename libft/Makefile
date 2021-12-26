NAME = libft.a

HEADER = libft.h

SRC = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c\
ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c\
ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c\
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJ_B = $(BONUS:.c=.o)

.c.o: $(SRC)
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile
	@ar rcs $(NAME) $^
	@echo "**********************************"
	@echo ✅ LibFt is compiled succesfully

bonus: $(OBJ_B)
	ar rcs $(NAME) $^

clean:
	@rm -f $(OBJ) $(OBJ_B)
	@echo "**********************************"
	@echo ✅ LibFt objects are cleaned succesfully

fclean:
	@rm -f $(OBJ) $(OBJ_B)
	@rm -rf $(NAME)
	@echo "**********************************"
	@echo ✅ LibFt is deleted

re: fclean all

.PHONY: bonus all clean fclean re
