/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yoan.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:31:12 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/03 11:02:25 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DOOM_H_
# define _DOOM_H_

# include <mlx.h>
# include <stdlib.h>

# define KEY_ESC 53
# define KEY_ENTER 36
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define WIDTH 1080
# define HEIGHT 720

typedef struct    s_img
{
    void        *img;
    char        *buffer;
    int         *data;
    int         height;
    int         width;
    int         bpp;
    int         size_line;
    int         endian;
}                t_img;

typedef struct    s_mlx
{
    void        *mlx;
    void        *win;
    void        *img;
    int        *data;
    int        bpp;
    int        size_line;
    int        endian;
}                t_mlx;

typedef struct    s_env
{
    t_mlx    mlx;
    t_img    img[1];
}                t_env;

#endif