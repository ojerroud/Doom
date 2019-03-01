/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:28:37 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/01 16:58:39 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	key_esc(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	exit(0);
}

/*
**	change scale of grid if G pressed
*/

void	sizegrid_change(t_env *e)
{
	t_ixy	*tmp;

	tmp = e->dots;
	while (e->dots)
	{
		e->dots->x /= e->grid_size;
		e->dots->y /= e->grid_size;
		e->dots = e->dots->next;
	}
	e->dots = tmp;
	e->grid_size /= 1.5;
	if (e->grid_size < GRID_SIZE / (1.5 * 3))
		e->grid_size = GRID_SIZE;
	while (e->dots)
	{
		e->dots->x *= e->grid_size;
		e->dots->y *= e->grid_size;
		e->dots = e->dots->next;
	}
	e->dots = tmp;
	if (e->select->name == END - 1)
		put_grid(e);
}

int		keyhooked(int keycode, t_env *e)
{
	if (keycode == ESC)
		key_esc(e);
	if (keycode == G)
		sizegrid_change(e);
	if (keycode == W)
		mlx_clear_window(e->mlx.mlx, e->mlx.win);
	return (0);
}
