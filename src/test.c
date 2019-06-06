/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:57:00 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/06 15:42:39 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoomNukem.h"

void    c(t_env *e)
{
    color_img(e);
    draw_ligne(e->character, e->ray, 0xAAAAAA, e);
    // e->mlx.img.data[e->character.y * WIDTH + e->character.x] = 0xFF0000;
    mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img.img_ptr, 0, 0);
}

void    rot(int x, t_env *e)
{
    double tmpx = e->ray.x - e->character.x;
    double tmpy = e->ray.y - e->character.y;

    printf("%f %f\n",tmpx, tmpy);

    x+=0;
    e->ray.x = tmpx * cos(x * M_PI / 6) - tmpy * sin(x * M_PI / 6);// + e->character.x;
    e->ray.y = tmpx * sin(x * M_PI / 6) + tmpy * cos(x * M_PI / 6);// + e->character.y;
    e->ray.x += e->character.x;
    e->ray.y += e->character.y;
    c(e);
    mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img.img_ptr, 0, 0);
}

void    mv(int x, t_env *e)
{
    e->character.y += x;
    e->ray.y += x;
    c(e);
}

int     test2(int key, t_env *e)
{
    if (key == ESC)
        exit (0);
    else if (key == LEFT)
        rot(-1, e);
    else if (key == RIGHT)
        rot(1, e);
    else if (key == UP)
        mv(-5, e);
    else if (key == DOWN)
        mv(5, e);
    return (0);
}

void    nlx(t_env *e)
{
    e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "test");
	e->mlx.img.img_ptr = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->mlx.img.data = (int *)mlx_get_data_addr(e->mlx.img.img_ptr, &e->mlx.img.bpp, &e->mlx.img.size_l, &e->mlx.img.endian);
    c(e);
    mlx_hook(e->mlx.win, 2, 2, test2, e);
    mlx_loop(e->mlx.mlx);
}

void    i(t_env *e)
{
    e->character.x = WIDTH / 2;
    e->character.y = WIDTH / 2;
    e->ray.x = e->character.x + 50;
    e->ray.y = e->character.y;
}

void    test(t_env *e)
{
    i(e);
    nlx(e);
}