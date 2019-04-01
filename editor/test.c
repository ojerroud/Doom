/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:26:32 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/01 14:28:20 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		g_keycode_to_ascii_alphabet[26] = {0, 11, 8, 2, 14, 3, 5, 4, 34, 38, 40, 37, 46
	, 45, 31, 35, 12, 15, 1, 17, 32, 9, 13, 7, 16, 6};

void	color_img(int *data, int width, int height)
{
	int w;
	int h;

	h = -1;
	while (++h < height)
	{
		w = -1;
		while (++w < width)
			data[h * width + w] = 0xFFFFFF;
	}
}

int		keyboard(int keycode, t_env *e)
{
	int		i;
	int		pressed;
	int		len;

	if (keycode == ESC)
		exit (0);
	i = -1;
	if (keycode == 51)
	{
		e->file_name[ft_strlen(e->file_name) - 1] = '\0';
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img_ptr, 5, 8);
		mlx_string_put(e->mlx.mlx, e->mlx.win, 5, 5, 0xFF0000, e->file_name);
	}
	while (++i < 26)
	{
		if (g_keycode_to_ascii_alphabet[i] == keycode)
		{	
			len = ft_strlen(e->file_name);
			if (len * 10 >= FILENAME_SIZE)
				break;
			e->file_name[len] = i + 97;
			e->file_name[len + 1] = '\0';
			mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img_ptr, 5, 8);
			mlx_string_put(e->mlx.mlx, e->mlx.win, 5, 5, 0xFF0000, e->file_name);
			return (0);
		}
	}
			// printf("%c\n", i + 97);
	// printf("len de t_keycode %d\n", ft_strlen(t_keycode A));
	// printf("%d\n", keycode);
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

	// FILENAME_SIZE = FILENAME_SIZE;
	img_height = 20;
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "test");
	e->mlx.img_ptr = mlx_new_image(e->mlx.mlx, FILENAME_SIZE, img_height);
	e->mlx.data = (int *)mlx_get_data_addr(e->mlx.img_ptr, &e->mlx.bpp, &e->mlx.size_l, &e->mlx.endian);
	ft_bzero(e->file_name, FILENAME_SIZE);
	color_img(e->mlx.data, FILENAME_SIZE, img_height);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img_ptr, 5, 8);
	mlx_key_hook(e->mlx.win, keyboard, e);
	mlx_mouse_hook(e->mlx.win, mouse, e);
	mlx_loop(e->mlx.mlx);
}

int 	main(int ac, char **av)
{
	t_env		e;
	int			i;

	// i = -1;
	// while (++i < 27)
	// 	printf("%d\n", g_keycode_to_ascii[i]);
	t(&e);
	return (0);
}
