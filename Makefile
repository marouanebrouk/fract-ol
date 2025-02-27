CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L /usr/include/minilibx-linux -lmlx -lX11 -lXext 
RM = rm -rf
SRC = main.c event_handle.c fractol.c math_utils.c utils_fractol.c ft_atod.c
NAME = fractol
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(MLX_FLAGS) -o $@

bonus: all

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
