/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:40:57 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/07/13 21:35:02 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include "../headers/color_palette.h"

int     win_close(void) 
{
    exit(EXIT_SUCCESS);
    return (0);
}

/*
** Get needed color
*/

void    color_picker(int kc, t_mlx * mlx)
{
    if (kc == 18)
        set_new_base_color(mlx->var, CLR1);
    else if (kc == 19)
        set_new_base_color(mlx->var, CLR2);
    else if (kc == 20)
        set_new_base_color(mlx->var, CLR3);
    else if (kc == 21)
        set_new_base_color(mlx->var, CLR4);
    else if (kc == 23)
        set_new_base_color(mlx->var, CLR0);
    cl_update_model(mlx);
}

/*
** Move fractal corresponding to key pressed
*/

void    arrows_movement(int kc, t_mlx *mlx)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    if (kc == ARR_UP)
        arrow_move_vertical(mlx->var, ARR_STEP_P, ARR_STEP_P);
    else if (kc == ARR_DOWN)
        arrow_move_vertical(mlx->var, ARR_STEP_N, ARR_STEP_N);
    else if (kc == ARR_LEFT)
        arrow_move_horizontal(mlx->var, ARR_STEP_N, ARR_STEP_N);
    else if (kc == ARR_RIGTH)
        arrow_move_horizontal(mlx->var, ARR_STEP_P, ARR_STEP_P);
    cl_update_model(mlx);
}

/*
** Iter addition and substraction
*/

void    iter_change(int kc, t_mlx *mlx)
{
    if (kc == ITER_P)
        iter_modify(mlx->var, STEP_IT_P);
    else if (kc == ITER_M)
        iter_modify(mlx->var, STEP_IT_N);
    cl_update_model(mlx);
}

int     key_event(int kc, void *argument) 
{
    printf("kc [%d]\n", kc);
    if (kc == ESCAPE)
        win_close();
    else if (kc == 83)
    {
        ((t_mlx*)argument)->current_fractal = 1; 
        ((t_mlx*)argument)->fractal_path = MANDELBROT;
        cl_update_model((t_mlx*)argument);
    }
    else if (kc == 84)
    {
        ((t_mlx*)argument)->current_fractal = 2; 
        ((t_mlx*)argument)->fractal_path = JULIA;
        cl_update_model((t_mlx*)argument);
    }
    else if (kc == 85)
    {
        ((t_mlx*)argument)->current_fractal = 3; 
        ((t_mlx*)argument)->fractal_path = MANDELTRIC;
        cl_update_model((t_mlx*)argument);
    }
    else if (kc == 18 || kc == 19 || kc == 20 || kc == 21 || kc == 23)
        color_picker(kc, (t_mlx*)argument);
    else if (kc == 126 || kc == 123 || kc == 125 || kc == 124)
        arrows_movement(kc, (t_mlx*)argument);
    else if (kc == 69 || kc == 78)
        iter_change(kc, (t_mlx*)argument);
    return (0);
}

int     mouse_event(int keycode, int x, int y, void *argument) 
{
    if (keycode == 5)
        zoom_change(((t_mlx*)argument)->var, 0.9, x, y);
    if (keycode == 4)
        zoom_change(((t_mlx*)argument)->var, 1.1, x, y);
    cl_update_model((t_mlx*)argument);
    return (0);
}

int     motion_notify(int x, int y, void *argument)
{
    int     in_window;
    int     is_julia;

    printf("Keycode  x[%d] y[%d]\n", x, y);
    is_julia = ((t_mlx*)argument)->current_fractal == 2;
    in_window = (x >= 0 && x <= WWIDTH && y >= 0 && y <= WHEIGHT);
    if (in_window && is_julia)
    {
        julia_moves(((t_mlx*)argument)->var, x, y);
        cl_update_model((t_mlx*)argument);
    }
    return (0);

}