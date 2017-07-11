/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 20:10:32 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/07/11 18:13:04 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

/*
** Compile rigth version of mlx correspoding to macos version
*/

# if defined(__OSXSIERRA__)
    # include "../mlx_10.12/mlx.h"
# else
    # include "../mlx_10.11/mlx.h"
# endif

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <pthread.h>
# include "../headers/cl_data.h"

/*
** X11/X.h event names
*/

# define KEYPRESS	    2
# define MOTIONNOTIFY   6
# define DESTROYNOTIFY  17

/*
** X11/X.h event masks
*/

# define KEYPRESSMASK   (1L<<0)
# define BUTTMOTNMASK   (1L<<13)
# define STRCTNOTMASK   (1L<<17)
/*
** Buttons keycodes
*/

# define ESCAPE         53
# define SPACE          49

/*
** Window attr - current iMac `27 full screen
*/

# define WHEIGHT        (768)
# define WWIDTH         (1280)

/*
** OpenCL kernel file max size 
*/

# define BUFF           (0x10000)

/*
** Pathes to OpenCL kernel files
*/

# define MANDELBROT     "opencl_kernels/mandelbrot_set.cl"

/*
** Graphic lib data 
*/

typedef struct          s_mlx
{
    void                *mlx;
    void                *win;
    void                *image;
    t_cl                *cl;
    t_const             *var;
    char                current_fractal;
}                       t_mlx;

/*
** Main function to compute and draw fractals, depending on what kernel file was given
*/

void                    cl_update_model(t_mlx *argument, const char *filepath);


#endif