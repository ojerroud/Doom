/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yoann_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:30:23 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/03 11:07:53 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yoan.h"


void    load_texture(t_env *e)
{
    e->img[0].img = mlx_xpm_file_to_image(e->mlx.mlx, "texture/vincent.xpm", &e->img[0].width, &e->img[0].height);
    e->img[0].data =(int *)mlx_get_data_addr(e->img[0].img, &e->img[0].bpp, &e->img[0].size_line, &e->img[0].endian);
}

int     keyhook(int keycode, t_env *e)
{
    if (keycode == 53)
        exit(0);
    return (0);
}

void    color_img(t_env *e)
{
    int h;
    int w;
    double h_scale;
    double w_scale;

    h_scale = (double)HEIGHT / e->img[0].height;
    w_scale = (double)WIDTH / e->img[0].width;
    h = -1;
    while (++h < HEIGHT)
    {
        w = -1;
        while (++w < WIDTH)
            e->mlx.data[h * WIDTH + w] = e->img[0].data[(int)((double)h / h_scale) * e->img[0].width + (int)((double)w / w_scale)];
    }
}

void    init(t_env *e)
{
    e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "test");
    e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
    e->mlx.data = (int *)mlx_get_data_addr(e->mlx.img, &e->mlx.bpp, &e->mlx.size_line, &e->mlx.endian);
    color_img(e);
    mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	mlx_key_hook(e->mlx.win, keyhook, e);
	mlx_loop(e->mlx.mlx);
}

int main(int ac, char **av)
{
    t_env e;

    load_texture(&e);
    init(&e);
    return (0);
}