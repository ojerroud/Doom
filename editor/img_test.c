/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:02:37 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/19 18:46:17 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int     k(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
	return (0);
}

void	change_img(t_test *img, t_test texture, int taille)
{
	int w;
	int h;
	double	t;

	h = -1;
	t = taille / 64.0;
	while (++h < taille)
	{
		w = -1;
		while (++w < taille)
		{
			img->data[h * taille + w] = texture.data[(int)((double)h / t) * 64 + (int)((double)w / t)];
			// img->data[h * taille + w] = 0xFFFFFF;
		}
	}
}   

int 	main(int ac, char **av)
{
	t_env   e;
	t_test  img;
	t_test	texture;
	int		t;
	int		taille;

	taille = 500;
	e.mlx.mlx = mlx_init();
	e.mlx.win = mlx_new_window(e.mlx.mlx, WIDTH, HEIGHT, "test");
	img.img = mlx_new_image(e.mlx.mlx, taille, taille);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);
	texture.img = mlx_xpm_file_to_image(e.mlx.mlx, BALL1, &t, &t);
	texture.data = (int *)mlx_get_data_addr(texture.img, &texture.bpp, &texture.size_l, &texture.endian);
	change_img(&img, texture, taille);
	mlx_put_image_to_window(e.mlx.mlx, e.mlx.win, texture.img, 400, 400);
	mlx_put_image_to_window(e.mlx.mlx, e.mlx.win, img.img, 0, 0);
	mlx_key_hook(e.mlx.win, k, &e);
	mlx_loop(e.mlx.mlx);
	return (0);
}