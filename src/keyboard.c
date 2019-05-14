/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:28:37 by ojerroud          #+#    #+#             */
/*   Updated: 2019/05/14 17:39:51 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoomNukem.h"

void	key_esc(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	exit(0);
}

int		keyhooked(int keycode, t_env *e)
{
	ft_putnbr(keycode);
	ft_putendl("");
	if (keycode == ESC)
		key_esc(e);
	return (0);
}

void	mouvment_change(int x, int y, t_env *e)
{
	e->character.x += x;
	e->character.y += y;
}

void	rotate(int positif, t_env *e)
{
	e->ray.x += (positif * (cos(e->dir) - sin(e->dir)));
	e->ray.y += (positif * (sin(e->dir) + cos(e->dir)));
}

int		mouvment(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx.mlx, e->mlx.win);
	if (keycode == UP)
		mouvment_change(0, -5, e);
	else if (keycode == DOWN)
		mouvment_change(0, 5, e);
	else if (keycode == LEFT)
		rotate(-1, e);
	else if (keycode == RIGHT)
		rotate(1, e);
	if (keycode == ESC)
		exit (0);
	color_img(e);
	map(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img.img_ptr, 0, 0);
	return (0);
}
