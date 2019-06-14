/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:57:00 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/13 15:27:20 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoomNukem.h"

int     test2(int key, t_env *e)
{
    if (key == ESC)
        exit (0);
        e->is_title +=0;
    return (0);
}

void color(t_env *e)
{
    int h;
    int w;

    h = -1;
    while (++h < HEIGHT - 10)
    {
        w = -1;
        while (++w < WIDTH - 10)
            e->mlx.img.data[h * (WIDTH - 10) + w] = 0xAAAAAA;
    }
}

void    get_texture(t_env *e)
{
    e->mlx.texture.img_ptr = mlx_xpm_file_to_image(e->mlx.mlx, e->texture, &e->mlx.texture.width, &e->mlx.texture.height);
    if (!e->mlx.texture.img_ptr)
        exit(0);
    e->mlx.texture.data = (int *)mlx_get_data_addr(e->mlx.texture.img_ptr, &e->mlx.texture.bpp, &e->mlx.texture.size_l, &e->mlx.img.endian);
}

void    scale_texture(t_env *e)
{
    int w;
    int h;
    double w_scale;
    double h_scale;

    h = w = -1;
    w_scale = (double)WIDTH / e->mlx.texture.width;
    h_scale = (double)HEIGHT / e->mlx.texture.height;
    printf("%f %f\n" ,w_scale ,h_scale);
    while (++h < HEIGHT - 10)
    {
        w = -1;
        while (++w < WIDTH - 10)
            e->mlx.img.data[h * (WIDTH - 10) + w] = e->mlx.texture.data[(int)((double)h / h_scale) * e->mlx.texture.width + (int)((double)w / w_scale)];
    }
}

void    nlx(t_env *e)
{
    e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "test");
	e->mlx.img.img_ptr = mlx_new_image(e->mlx.mlx, WIDTH - 10, HEIGHT - 10);
	e->mlx.img.data = (int *)mlx_get_data_addr(e->mlx.img.img_ptr, &e->mlx.img.bpp, &e->mlx.img.size_l, &e->mlx.img.endian);
    // color(e);
    // mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img.img_ptr, 5, 5);
    get_texture(e);
    scale_texture(e);
    mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img.img_ptr, 5, 5);
    mlx_hook(e->mlx.win, 2, 2, test2, e);
    mlx_loop(e->mlx.mlx);
}

void    test(t_env *e)
{
    // i(e);
    nlx(e);
}