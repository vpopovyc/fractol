/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 17:41:57 by vrybalko          #+#    #+#             */
/*   Updated: 2017/06/04 14:32:02 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _KEYS_H
# define _KEYS_H
# ifdef linux
#  define XK_LATIN1
#  define XK_MISCELLANY
#  define XK_TECHNICAL
#  include <X11/keysymdef.h>
#  define K_ESC XK_Escape
#  define K_W XK_w
#  define K_S XK_s
#  define K_A XK_a
#  define K_D XK_d
#  define K_LA XK_Left
#  define K_RA XK_Right
#  define K_UA XK_Up
#  define K_DA XK_Down
#  define K_E XK_e
#  define K_M XK_m
#  define K_T XK_t
#  define K_Q XK_q
#  define K_SP XK_space
#  define K_ENT XK_Return
#  define K_PUP XK_Page_Up
#  define K_PDN XK_Page_Down
#  define K_L XK_l
#  define K_J XK_j
#  define K_I XK_i
#  define K_K XK_k
#  define K_U XK_u
#  define K_O XK_o
#  define K_1 XK_1
#  define K_2 XK_2
#  define K_3 XK_3
#  define K_4 XK_4
#  define K_5 XK_5
#  define K_6 XK_6
#  define K_7 XK_7
#  define K_8 XK_8
#  define K_9 XK_9
#  define K_NP_1 65436
#  define K_NP_2 65433
#  define K_NP_3 65435
#  define K_NP_4 65430
#  define K_NP_5 65437
#  define K_NP_6 65432
#  define K_NP_7 65429
#  define K_NP_8 65431
#  define K_NP_9 65434
#  define K_NP_PLUS XK_KP_Add
#  define K_NP_MINUS XK_KP_Subtract
# else
#  define K_ESC 53
#  define K_W 13
#  define K_S 1
#  define K_A 0
#  define K_D 2
#  define K_E 14
#  define K_M 46
#  define K_T 17
#  define K_Q 12
#  define K_LA 123
#  define K_RA 124
#  define K_UA 126
#  define K_DA 125
#  define K_SP 49
#  define K_ENT 36
#  define K_PUP 116
#  define K_PDN 121
#  define K_L 37
#  define K_J 38
#  define K_I 34
#  define K_K 40
#  define K_U 32
#  define K_O 31
#  define K_NP_1 83
#  define K_NP_2 84
#  define K_NP_3 85
#  define K_NP_4 86
#  define K_NP_5 87
#  define K_NP_6 88
#  define K_NP_7 89
#  define K_NP_8 90
#  define K_NP_9 91
#  define K_NP_PLUS 69
#  define K_NP_MINUS 78
# endif
#endif
