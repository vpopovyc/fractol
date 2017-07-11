/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <vpopovyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:42:12 by vpopovyc          #+#    #+#             */
/*   Updated: 2017/07/10 14:43:21 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTROL_H
# define __CONTROL_H

int     win_close(void);
int     key_event(int keycode, void *argument);
int     mouse_event(int keycode, int x, int y, void *argument);
int     motion_notify(int x, int y, void *argument);

#endif
