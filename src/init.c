/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:56:45 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/06 17:13:23 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoomNukem.h"

void	draw_ligne_point_to_point_swap_vars(t_var *var)
{
	int	tmp;

	tmp = var->dx;
	var->dx = var->dy;
	var->dy = tmp;
	tmp = var->x;
	var->x = var->y;
	var->y = tmp;
	tmp = var->xinc;
	var->xinc = var->yinc;
	var->yinc = tmp;
}

void	draw_ligne_point_to_point(t_env *e, int color)
{
	while (++(e->var.i) <= e->var.dx)
	{
		e->var.x += e->var.xinc;
		e->var.cumul += e->var.dy;
		if (e->var.cumul >= e->var.dx)
		{
			e->var.cumul -= e->var.dx;
			e->var.y += e->var.yinc;
		}
		(e->var.swap == 1) ? draw_ligne_point_to_point_swap_vars(&e->var) : 0;
		e->mlx.img.data[e->var.y * WIDTH + e->var.x] = color;
		(e->var.swap == 1) ? draw_ligne_point_to_point_swap_vars(&e->var) : 0;
	}
}

void	draw_ligne(t_dxy dots1, t_dxy dots2, int color, t_env *e)
{
	e->var.x = dots1.x;
	e->var.y = dots1.y;
	e->var.dx = dots2.x - dots1.x;
	e->var.dy = dots2.y - dots1.y;
	e->var.xinc = (e->var.dx > 0) ? 1 : -1;
	e->var.yinc = (e->var.dy > 0) ? 1 : -1;
	e->var.dx = abs(e->var.dx);
	e->var.dy = abs(e->var.dy);
	e->mlx.img.data[e->var.y * WIDTH + e->var.x] = color;
	e->var.swap = (e->var.dx <= e->var.dy) ? 1 : 0;
	(e->var.dx <= e->var.dy) ? draw_ligne_point_to_point_swap_vars(&e->var) : 0;
	e->var.cumul = e->var.dx / 2;
	e->var.i = 0;
	draw_ligne_point_to_point(e, color);
}

void	map(t_env *e)
{
	int i;

	i = -1;
	while (++i < 8)
		draw_ligne(e->map[i], e->map[i + 1], 0xFFFFFF, e);
	draw_ligne(e->ray, e->character, 0xAAAAAA , e);
}

void	color_img(t_env *e)
{
	int w;
	int h;

	w = -1;
	while (++w < HEIGHT)
	{
		h = -1;
		while (++h < WIDTH)
			e->mlx.img.data[h * HEIGHT + w] = 0x002222;
	}
}

int		init_mlx(t_env *e, char *title)
{
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, title);
	e->mlx.img.img_ptr = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->mlx.img.data = (int *)mlx_get_data_addr(e->mlx.img.img_ptr, &e->mlx.img.bpp, &e->mlx.img.size_l, &e->mlx.img.endian);
	color_img(e);
	map(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img.img_ptr, 0, 0);
	mlx_mouse_hook(e->mlx.win, mousehooked, e);
	// mlx_key_hook(e->mlx.win, mouvment, e);
	mlx_hook(e->mlx.win, 2, 2, mouvment, e);
	mlx_loop(e->mlx.mlx);
	return (0);
}
