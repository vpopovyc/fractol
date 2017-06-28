# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 19:25:38 by vpopovyc          #+#    #+#              #
#    Updated: 2017/06/28 23:48:40 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = fractol
MLX = mlx/libmlx.a
SRC = main.c
OBJ = $(SRC:.c=.o)
CC = clang
HEADER = fractol.h
EXECFLAGS = -Wall -Wextra -Werror -framework AppKit -framework OpenGL
OBJFLAGS = -g -Wall -Wextra -Werror

.phony: all clean fclean re mlxclean
 
all: $(MLX) $(OBJ)
	$(CC) $(EXECFLAGS) $(OBJ) $(MLX) -o $(EXEC) 


%.o: %.c ${HEADER}
	$(CC) $(CCFLAGS) -o $@ -c $< 

clean: 
	/bin/rm -f $(OBJ) 

fclean: 
	/bin/rm -f $(OBJ) 
	/bin/rm -f $(EXEC) 

re: fclean all 

$(MLX): 
	make -C mlx

mlxclean:
	make -C mlx/ clean
