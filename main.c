/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 19:24:46 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/06/28 22:32:52 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
    return (0);
}

int     mouse_event(int keycode, int x, int y, void *argument) 
{
    printf("Keycode [%d] x[%d] y[%d]\n", keycode, x, y);
    return (0);
}

int     motion_notify(int x, int y, void *argument)
{
    if (x >= 0 && x <= WWIDTH && y >= 0 && y <= WHEIGHT)
    {
        printf("x[%d] y[%d]\n", x, y);
    }
    return (0);
}

int     main(void)
{
    void *init = mlx_init();
    void *win = mlx_new_window(init, WWIDTH, WHEIGHT, "fractol / vpopovyc");


    mlx_hook(win, DESTROYNOTIFY, STRCTNOTMASK, win_close, NULL);
    mlx_hook(win, KEYPRESS, KEYPRESSMASK, key_event, NULL);
    mlx_hook(win, MOTIONNOTIFY, BUTTMOTNMASK, motion_notify, NULL);
    
    mlx_mouse_hook(win, mouse_event, NULL);
    mlx_key_hook(win, key_event, NULL);
    mlx_loop(init);
    return (0);
}