/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 20:10:32 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/06/29 16:57:17 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

/*
** Compile rigth version of mlx correspoding to macos version
*/


# if defined(__OSXSIERRA__)
    # include "mlx_10.12/mlx.h"
# else
    # include "mlx_10.11/mlx.h"
# endif

# include <stdlib.h>
# include <stdio.h>

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

/*
** Window attr
*/

# define WHEIGHT        400
# define WWIDTH         800

#endif