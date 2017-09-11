/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 19:24:46 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/07/14 18:35:14 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

#include "../headers/cl_data.h"
#include "../headers/control.h"

inline static void     main_struct_init(t_mlx *mlx)
{
    int a;
    int b;
    int c;

    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, WWIDTH, WHEIGHT, "fractol / vpopovyc");
    mlx->image = mlx_new_image(mlx->mlx, WWIDTH, WHEIGHT);

    mlx->cl = malloc(sizeof(t_cl));
    mlx->cl->image = (cl_char*)mlx_get_data_addr(mlx->image, &a, &b, &c);
    init_model(mlx->cl);
    mlx->var = malloc(sizeof(t_const));
    const_init(mlx->var, 100);
/*
*/
    mlx_string_put(mlx->mlx, mlx->win, WWIDTH / 2 - 50, WHEIGHT / 2 - 50,  0xffffff, "fainting spells");
    mlx_string_put(mlx->mlx, mlx->win, WWIDTH / 2, WHEIGHT / 2,  0xffffff, "OpenCL fractal set renderer");
    mlx_string_put(mlx->mlx, mlx->win, WWIDTH / 2, WHEIGHT / 2 + 20,  0xffffff, "mandelbrot            - 1");
    mlx_string_put(mlx->mlx, mlx->win, WWIDTH / 2, WHEIGHT / 2 + 40,  0xffffff, "julia                 - 2");
    mlx_string_put(mlx->mlx, mlx->win, WWIDTH / 2, WHEIGHT / 2 + 60,  0xffffff, "mandelbrot_tricorn    - 3");
    mlx_string_put(mlx->mlx, mlx->win, WWIDTH / 2, WHEIGHT / 2 + 80,  0xffffff, "mandelbrot_4th        - 4");
    mlx_string_put(mlx->mlx, mlx->win, WWIDTH / 2, WHEIGHT / 2 + 100, 0xffffff, "mandelbrot_5th        - 5");
    mlx_string_put(mlx->mlx, mlx->win, WWIDTH / 2, WHEIGHT / 2 + 120, 0xffffff, "infinite julia        - 6");
    mlx_string_put(mlx->mlx, mlx->win, WWIDTH / 2, WHEIGHT / 2 + 140, 0xffffff, "infinite mandelbrot   - 7");
    mlx_string_put(mlx->mlx, mlx->win, WWIDTH / 2, WHEIGHT / 2 + 160, 0xffffff, "mandelbrot_3th        - 8");
/*
*/
}

int             main(void)
{
    t_mlx   *mlx;

    mlx = malloc(sizeof(t_mlx));
    main_struct_init(mlx);

    mlx_hook((*mlx).win, DESTROYNOTIFY, STRCTNOTMASK, win_close, NULL);
    mlx_hook((*mlx).win, KEYPRESS, KEYPRESSMASK, key_event, (void*)mlx);
    mlx_hook((*mlx).win, MOTIONNOTIFY, BUTTMOTNMASK, motion_notify, (void*)mlx);

    mlx_mouse_hook((*mlx).win, mouse_event, (void*)mlx);
    mlx_loop((*mlx).mlx);
    return (0);
}
