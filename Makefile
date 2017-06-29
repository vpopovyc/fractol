# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 19:25:38 by vpopovyc          #+#    #+#              #
#    Updated: 2017/06/29 15:04:55 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = fractol

# Compile rigth version of mlx correspoding to macos version
MACSYSTEMVERSION = shell sw_vers -productVersion | cut -d '.' -f 1,2
ifeq ($(MACSYSTEMVERSION), 10.12)
	MLX_DIRECTORY = mlx_10.12/
else
	MLX_DIRECTORY = mlx_10.11/
endif
MLX = $(addprefix $(MLX_DIRECTORY), libmlx.a)

SRC = main.c
OBJ = $(SRC:.c=.o)
CC = clang
HEADER = fractol.h
EXECFLAGS = -Wall -Wextra -Werror -framework AppKit -framework OpenGL
CCMACSYSTEMVERSION = -D__MACSYSTEMVERSION__=MACSYSTEMVERSION; 
OBJFLAGS = -g -Wall -Wextra -Werror

.phony: all clean fclean re mlxclean
 
all: $(MLX) $(OBJ)
	$(CC) $(EXECFLAGS) $(CCMACSYSTEMVERSION) $(OBJ) $(MLX) -o $(EXEC) 


%.o: %.c ${HEADER}
	$(CC) $(CCFLAGS) $(CCMACSYSTEMVERSION) -o $@ -c $< 

clean: 
	/bin/rm -f $(OBJ) 

fclean: 
	/bin/rm -f $(OBJ) 
	/bin/rm -f $(EXEC) 

re: fclean all 

$(MLX): 
	make -C $(MLX_VERSION)

mlxclean:
	make -C $(MLX_VERSION) clean
