/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 16:02:14 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/07/12 19:43:08 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CL_DATA_H
# define __CL_DATA_H

# include "OpenCL/opencl.h"

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

# define CONST          (7)
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
    unsigned            MaxIterations;
}                       t_const;

/*
** Models 
*/

void                    init_model(t_cl *cl);

/*
** Fts to update const values
** desription in definition
*/

void                    const_init(t_const *var, unsigned MaxIterations);
void                    load_to_arg(t_const *var, cl_double *arg);
void                    zoom_change(t_const *var, double new_zoom, int x, int y);
#endif