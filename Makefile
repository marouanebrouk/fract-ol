# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbrouk <mbrouk@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 01:59:55 by mbrouk            #+#    #+#              #
#    Updated: 2025/03/09 15:58:55 by mbrouk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
