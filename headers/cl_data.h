/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 16:02:14 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/07/13 20:16:18 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CL_DATA_H
# define __CL_DATA_H

# ifdef __OSX_OPENCL__
#  include "OpenCL/opencl.h"
#endif
# ifdef __OS_LINUX_OPENCL__

/*
** use clCreateCommandQueue on device that don't support OpenCL 2.0 API
*/

#  define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#  include "CL/opencl.h"
# endif

# include <unistd.h>

/*
** Capacity of iMac's SIMD unit
*/

# define SIMD           (256)

/*
** Window attr - current iMac `27 full screen
*/

# define WHEIGHT        (1280)
# define WWIDTH         (1280)

/*
** Input and output memmory buffers
*/

# define CONST          (10)
# define SIZE           (WHEIGHT*WWIDTH)

/*
** Opencl data
*/

typedef struct          s_cl
{
    cl_device_id        device;
    cl_context          context;
    cl_command_queue    queue;

    cl_program          program;
    cl_kernel           kernel;

    cl_mem              input;
    cl_mem              constants;
    /* optimization purpose */
    cl_char             *image;
    cl_double           *constant;
}                       t_cl;

/*
** Constant values, that compute units need
*/

typedef struct          s_const
{
    double              zoom;
    double              MinRe;
    double              MaxRe;
    double              MinIm;
    double              MaxIm;
    double              Re_factor;
    double              Im_factor;
    int                 base_color;
    int                 MaxIterations;
    int                 x_shift;
    int                 y_shift;
}                       t_const;

/*
** Models
*/

void                    init_model(t_cl *cl);

/*
** Fts to update const values
** desription in definition
*/

void                    set_new_base_color(t_const *var, int new_color);

/*
** Arrows move
*/

void                    arrow_move_vertical(t_const *var, double x, double y);
void                    arrow_move_horizontal(t_const *var, double x, double y);

/*
** Iter modify
*/

void                    iter_modify(t_const *var, int step);

/*
** Julia moves
*/

void                    julia_moves(t_const *var, int x, int y);

void                    const_init(t_const *var, unsigned MaxIterations);
void                    load_to_arg(t_const *var, cl_double *arg);
void                    zoom_change(t_const *var, double new_zoom, int x, int y);
#endif
