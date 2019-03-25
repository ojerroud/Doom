/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:38:48 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/25 12:11:51 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int	mouse(int keyword, int x, int y, t_env *e)
{
	// printf("%d %d %d\n", keyword, x, y);
	e->silent +=0;
	if (keyword == MOUSE_LEFT)
	{

	}
	if (keyword == MOUSE_RIGHT)
	{
		e->mlx.data[y * 400 + x] = 0xFFFFFF;
		sav_dots(&e->dots, x ,y);	
	}
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img_ptr, 0, 0);
	return (0);
}

int	key(int keyword, t_env *e)
{
	t_ixy	*tmp;

	if (keyword == ESC)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
	if (keyword == D)
	{
		tmp = e->dots;
		while (e->dots)
		{
			printf("%d %d\n", e->dots->x, e->dots->y);
			e->dots = e->dots->next;
		}
		printf("\n");
		e->dots = tmp;
	}
	return (0);
}

void	t(t_env *e)
{
	e->dots = NULL;
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, 400, 400, "t");
	e->mlx.img_ptr = mlx_new_image(e->mlx.mlx, 400, 400);
	e->mlx.data = (int *)mlx_get_data_addr(e->mlx.img_ptr, &e->mlx.bpp, &e->mlx.size_l, &e->mlx.endian);
	// ligne(40,40,300,300, e);
	// mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img_ptr, 0 ,0);
	mlx_mouse_hook(e->mlx.win, mouse, e);
	mlx_key_hook(e->mlx.win, key, e);
	mlx_loop(e->mlx.mlx);
}

int	main(int ac, char **av)
{
	t_env	e;

	// e.av = av;
	// e.ac = ac;
	if (av)
		ac += 0;
	// t(&e);
	init_vars(&e);
	init_mlx(&e, "editor");
	return (0);
}
