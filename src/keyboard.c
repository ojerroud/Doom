/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:28:37 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/06 17:21:46 by ojerroud         ###   ########.fr       */
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

void	mouvment_change(int x, t_env *e)
{
	if (e->character.x + e->dir.x * x * 2 > WIDTH || e->character.x + e->dir.x * x * 2 < 0 ||
	e->character.y + e->dir.y * x * 2 > HEIGHT || e->character.y + e->dir.y * x * 2 < 0)
		return ;
	e->character.x += e->dir.x * x;
	e->character.y += e->dir.y * x;
	e->ray.x += e->dir.x * x;
	e->ray.y += e->dir.y * x;
}

void	rotate(int positif, t_env *e)
{
	double x;
	double y;

	x = e->ray.x - e->character.x;
	y = e->ray.y - e->character.y;

	e->ray.x = (x * cos(positif * ROTATION) - y * sin(positif * ROTATION)) + e->character.x;
	e->ray.y = (y * cos(positif * ROTATION) + x * sin(positif * ROTATION)) + e->character.y;
	e->dir.x = e->ray.x - e->character.x;
	e->dir.y = e->ray.y - e->character.y;
}

int		mouvment(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx.mlx, e->mlx.win);
	if (keycode == UP)
		mouvment_change(1, e);
	else if (keycode == DOWN)
		mouvment_change(-1, e);
	else if (keycode == LEFT)
		rotate(-1, e);
	else if (keycode == RIGHT)
		rotate(1, e);
	else if (keycode == ESC)
		exit (0);
	color_img(e);
	map(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img.img_ptr, 0, 0);
	return (0);
}
