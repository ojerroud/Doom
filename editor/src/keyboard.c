/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:28:37 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/27 11:46:24 by ojerroud         ###   ########.fr       */
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
	t_ixy		*tmp;
	t_sector	*sector;

	sector = e->sector;
	while (e->sector)
	{
		tmp = e->sector->dots;
		while (e->sector->dots)
		{
			e->sector->dots->x /= e->grid_size;
			e->sector->dots->y /= e->grid_size;
			e->sector->dots = e->sector->dots->next;
		}
		e->sector->dots = tmp;
		e->sector = e->sector->next;
	}
	e->sector = sector;
	e->grid_size /= 1.5;
	if (e->grid_size < GRID_SIZE / (1.5 * 3))
		e->grid_size = GRID_SIZE;
	sector = e->sector;
	while (e->sector)
	{
		tmp = e->sector->dots;
		while (e->sector->dots)
		{
			e->sector->dots->x *= e->grid_size;
			e->sector->dots->y *= e->grid_size;
			e->sector->dots = e->sector->dots->next;
		}
		e->sector->dots = tmp;
		e->sector = e->sector->next;
	}
	e->sector = sector;
	if (e->select->name == END - 1)
		put_grid(e);
}

void	print_sector(t_env *e)
{
	t_sector	*tmp;
	t_ixy		*tmp2;

	tmp = e->sector;
	while (tmp)
	{
		ft_putstr("index : ");
		ft_putendl(ft_itoa(tmp->index));
		tmp2 = tmp->dots;
		while (tmp2)
		{
			ft_putnbr(tmp2->x);
			ft_putchar(' ');
			ft_putendl(ft_itoa(tmp2->y));
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	tmp = e->sector;
}

int		keyhooked(int keycode, t_env *e)
{
	if (keycode == ESC)
		key_esc(e);
	if (keycode == G)
		sizegrid_change(e);
	if (keycode == W)
		mlx_clear_window(e->mlx.mlx, e->mlx.win);
	if (keycode == A)
		print_sector(e);
	return (0);
}
