/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_computing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 20:56:20 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/07/13 17:05:27 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cl_data.h"
#include "../headers/color_palette.h"

/*
** Recalculates constant values, if zoom changed
*/

static inline void     compute_complex_factor(t_const *var)
{
    var->Re_factor = (var->MaxRe - var->MinRe) / (WWIDTH - 1);
    var->Im_factor = (var->MaxIm - var->MinIm) / (WHEIGHT - 1);
}

static inline void     compute_const_variables(t_const *var, double delta_y, double delta_x)
{
    var->MinRe = var->MinRe * var->zoom + delta_x * (1 - var->zoom);
    var->MaxRe = var->MaxRe * var->zoom + delta_x * (1 - var->zoom);
    var->MinIm = var->MinIm * var->zoom + delta_y * (1 - var->zoom);
    var->MaxIm = var->MaxIm * var->zoom + delta_y * (1 - var->zoom);
    compute_complex_factor(var);
}

/*
** Max depth modification 
*/

void             iter_modify(t_const *var, int step)
{
    int  iter;

    iter = var->MaxIterations + step;
    if (iter < 0)
        var->MaxIterations = 0;
    else
        var->MaxIterations = iter;
}

/*
** Used for color picking
*/

void             set_new_base_color(t_const *var, int new_color)
{
    var->base_color = new_color;
}

/*
** Method to make arrow movement possible
*/

void             arrow_move_vertical(t_const *var, double x, double y)
{
    var->MinIm -= x;
    var->MaxIm -= y;
    compute_complex_factor(var);
}

void             arrow_move_horizontal(t_const *var, double x, double y)
{
    var->MinRe -= x;
    var->MaxRe -= y;
    compute_complex_factor(var);
}
/*
** Function to increase or reduse fractals depth 
*/

void                    zoom_change(t_const *var, double new_zoom, int x, int y)
{
    double delta_x;
    double delta_y;

    var->zoom = new_zoom;
    delta_x = x * var->Re_factor + var->MinRe;
    delta_y = y * var->Im_factor + var->MinIm;
    compute_const_variables(var, delta_y, delta_x);
}

/*
** Method to load current const data to compute unit arg
*/

void                    load_to_arg(t_const *var, cl_double *arg)
{
    arg[0] = var->MaxIterations;
    arg[1] = var->MinRe;
    arg[2] = var->MaxRe;
    arg[3] = var->MinIm;
    arg[4] = var->MaxIm;
    arg[5] = var->Re_factor;
    arg[6] = var->Im_factor;
    arg[7] = var->base_color;
}

/*
** At first – MinRe, MaxRe, MinIm, MaxIm and zoom is predefined due M set definition
*/

void                    const_init(t_const *var, unsigned MaxIterations)
{
    var->zoom = 1;
    var->MinRe = -2.0;
    var->MaxRe = 0.5;
    var->MinIm = 1.25;
    var->MaxIm = -1.25;
    compute_complex_factor(var);
    set_new_base_color(var, CLR0);
    var->MaxIterations = MaxIterations;
}
