# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 19:25:38 by vpopovyc          #+#    #+#              #
#    Updated: 2017/07/11 18:31:07 by vpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = fractol

# Change mlx flags on Linux
UNAME_S = $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_DIRECTORY := minilibx_linux/
	MLX_FLAGS := $(MLX_DIRECTORY)/libmlx.a -lXext -lX11 -lOpenCL
	OPENCL_PATH_FLAG := -D__OS_LINUX_OPENCL__
endif
ifeq ($(UNAME_S),Darwin)
	# Compile rigth version of mlx correspoding to macos version
	MACSYSTEMVERSION := $(shell sw_vers -productVersion | cut -d '.' -f 1,2)
	ifeq ($(MACSYSTEMVERSION), 10.12)
		MLX_DIRECTORY := mlx_10.12/
		CCMACSYSTEMVERSION = -D__OSXSIERRA__
	else
		MLX_DIRECTORY := mlx_10.11/
		CCMACSYSTEMVERSION = -D__OSXELCAPTAIN__
	endif
	MLX_FLAGS := -framework AppKit -framework OpenGL -framework OpenCL
	OPENCL_PATH_FLAG := -D__OSX_OPENCL__
endif
MLX := $(addprefix $(MLX_DIRECTORY), libmlx.a)

HEADER = headers/cl_data.h headers/control.h headers/fractol.h
SRC := view/main.c model/cl_draw.c model/const_computing.c control/control.c model/model.c
OBJ := $(SRC:.c=.o)
CC = clang
OBJFLAGS := -g -Wall -Wextra -Werror


EXECFLAGS := -Wall -Wextra -Werror $(MLX_FLAGS)

.phony: all clean fclean re mlxclean

all: $(MLX) $(OBJ)
	$(CC) -v $(EXECFLAGS) $(CCMACSYSTEMVERSION) $(OPENCL_PATH_FLAG) $(OBJ) $(MLX) -o $(EXEC)


%.o: %.c ${HEADER}
	$(CC) $(OBJFLAGS) $(OPENCL_PATH_FLAG) -o $@ -c $<

clean:
	/bin/rm -f $(OBJ)

fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(EXEC)

re: fclean mlxclean all

$(MLX):
	make -C $(MLX_DIRECTORY)

mlxclean:
	make -C $(MLX_DIRECTORY) clean
