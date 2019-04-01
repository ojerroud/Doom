/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:28:37 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/01 14:35:22 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	key_esc(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	exit(0);
}

void	t(t_env *e, double grid)
{
	t_ixy		*tmp;
	t_sector	*sector;

	sector = e->sector;
	while (e->sector)
	{
		tmp = e->sector->dots;
		while (e->sector->dots)
		{
			e->sector->dots->x /= grid;
			e->sector->dots->y /= grid;
			e->sector->dots = e->sector->dots->next;
		}
		e->sector->dots = tmp;
		e->sector = e->sector->next;
	}
	e->sector = sector;
}

/*
**	change scale of grid if G pressed
*/

void	sizegrid_change(t_env *e)
{
	t(e, (double)(e->grid_size));
	e->grid_size /= 1.5;
	if (e->grid_size < GRID_SIZE / (1.5 * 3))
		e->grid_size = GRID_SIZE;
	t(e, (double)(1) / (double)(e->grid_size));
	if (e->select->name == END - 1)
		put_grid(e);
}

void	print_sector(t_env *e)
{
	t_sector	*tmp;
	t_ixy		*tmp2;

	tmp = e->sector;
	while (e->sector)
	{
		ft_putstr("index : ");
		ft_putnbr(e->sector->index);
		ft_putchar('\n');
		tmp2 = e->sector->dots;
		while (e->sector->dots)
		{
			ft_putnbr(e->sector->dots->x);
			ft_putchar(' ');
			ft_putnbr(e->sector->dots->y);
			ft_putchar('\n');
			e->sector->dots = e->sector->dots->next;
		}
		e->sector->dots = tmp2;
		e->sector = e->sector->next;
	}
	e->sector = tmp;
}

int		keyhooked(int keycode, t_env *e)
{
	if (keycode == ESC)
		key_esc(e);
	if (keycode == G)
		sizegrid_change(e);
	if (keycode == A)
		print_sector(e);
	if (keycode == R)
		delete_all_sectors(e);
	return (0);
}
