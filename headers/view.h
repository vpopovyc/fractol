/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 15:04:04 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/07/08 15:15:31 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VIEW_H
# define __VIEW_H


# include "fractol.h"

# define TRD_NUM        4
# define WSHEIGTH       (WHEIGHT / 2)
# define WSWIDTH        (WWIDTH / 2)

extern pthread_cond_t   g_condition;
extern pthread_t        g_thread_1;
extern pthread_mutex_t  g_mutex;
extern cl_int           *g_model;

#endif