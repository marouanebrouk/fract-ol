CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm
RM = rm -rf
SRC = main.c event_handl.c fractol.c math_utils.c utils_fractol.c

OBJ = $(SRC:%.c=%.o)

NAME = fractol

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(MLX_FLAGS) -o $@

bonus: all

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re # NAME iam gonna see
