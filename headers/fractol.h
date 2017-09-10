/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 20:10:32 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/07/14 18:32:45 by vpopovyc         ###   ########.fr       */
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
# include "../headers/cl_data.h"
# include "../headers/keys.h"

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

# define ESCAPE         K_ESC
# define SPACE          K_SP
# define ITER_P         K_NP_PLUS
# define ITER_M         K_NP_MINUS
# define ARR_UP         K_UA
# define ARR_DOWN       K_DA
# define ARR_LEFT       K_LA
# define ARR_RIGTH      K_RA

/*
** Window attr - current iMac `27 full screen
*/

# define WHEIGHT        (1280)
# define WWIDTH         (1280)

/*
** OpenCL kernel file max size
*/

# define BUFF           (0x10000)

/*
** Pathes to OpenCL kernel files
*/

# define MANDELBROT     "opencl_kernels/mandelbrot_set.cl"
# define MANDELTRIC     "opencl_kernels/mandelbrot_tricorn_set.cl"
# define JULIA          "opencl_kernels/julia_set.cl"
# define MANDEL_3TH     "opencl_kernels/mandelbrot_3th.cl"
# define MANDEL_4TH     "opencl_kernels/mandelbrot_4th.cl"
# define MANDEL_5TH     "opencl_kernels/mandelbrot_5th.cl"
# define INFIN_JUL      "opencl_kernels/infinite_zoom_backwards_julia.cl"
# define INFIN_MAN      "opencl_kernels/infinite_zoom_backwards_mandelbrot_5tth.cl"

/*
** Arrows move and iter step
*/

# define ARR_STEP_P     (0.0001)
# define ARR_STEP_N     (-0.0001)
# define STEP_IT_P      (50)
# define STEP_IT_N      (-50)

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
    char                *fractal_path;
    char                current_fractal;
}                       t_mlx;

/*
** Main function to compute and draw fractals, depending on what kernel file was given
*/

void    cl_update_model(t_mlx *mlx);


#endif
