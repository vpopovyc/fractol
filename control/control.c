/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:40:57 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/07/11 18:14:50 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int     win_close(void) 
{
    exit(EXIT_SUCCESS);
    return (0);
}

int     key_event(int keycode, void *argument) 
{
    printf("Keycode [%d]\n", keycode);
    if (keycode == ESCAPE)
        win_close();
    else if (keycode == 83)
    {
        ((t_mlx*)argument)->current_fractal = 1; 
        cl_update_model((t_mlx*)argument, MANDELBROT);
    }
    return (0);
}

int     mouse_event(int keycode, int x, int y, void *argument) 
{
    printf("Keycode [%d] x[%d] y[%d]\n", keycode, x, y);
    (void)argument;
    return (0);
}

int     motion_notify(int x, int y, void *argument)
{
    if (x >= 0 && x <= WWIDTH && y >= 0 && y <= WHEIGHT)
    {
        printf("x[%d] y[%d]\n", x, y);
    }
    (void)argument;
    return (0);
}