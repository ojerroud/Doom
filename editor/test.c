/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:26:32 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/29 18:26:34 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	color_img(int *data, int width, int height)
{
	int w;
	int h;
	int i;

	h = -1;
	while (++h < height)
	{
		w = -1;
		while (++w < width)
		// i = 0;
			data[h * width + w] = 0xFFFFFF;
	}
}

int		keyboard(int keycode, t_env *e)
{
	int		i;
	int		pressed;

	if (keycode == ESC)
		exit (0);
	i = -1;
	while (++i <= 46)
		if (i == keycode)
			pressed = keycode;
	printf("%c\n", pressed);
	// if (keycode == A)
	// {
	// 	e->file_name = strcat(e->file_name, "a");
	// 	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img_ptr, 5, 5);
	// 	mlx_string_put(e->mlx.mlx, e->mlx.win, 5, 5, 0xFF0000, e->file_name);
	// }
	return (0);
}

int		mouse(int keycode, int x, int y, t_env *e)
{

	return (0);
}

void	t(t_env *e)
{
	int img_width;
	int img_height;

	img_width = 80;
	img_height = 20;
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "test");
	e->mlx.img_ptr = mlx_new_image(e->mlx.mlx, img_width, img_height);
	e->mlx.data = (int *)mlx_get_data_addr(e->mlx.img_ptr, &e->mlx.bpp, &e->mlx.size_l, &e->mlx.endian);
	e->file_name = ft_strnew(0);
	color_img(e->mlx.data, img_width, img_height);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img_ptr, 5, 5);
	mlx_key_hook(e->mlx.win, keyboard, e);
	mlx_mouse_hook(e->mlx.win, mouse, e);
	mlx_loop(e->mlx.mlx);
}

int 	main(int ac, char **av)
{
	t_env		e;
	
	t(&e);
	return (0);
}