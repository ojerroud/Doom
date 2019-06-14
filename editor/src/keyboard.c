/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:28:37 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/14 14:30:57 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	key_esc(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	exit(0);
}

void	scale_dots_grid(t_env *e, double grid)
{
	t_ixy		*tmp;
	t_sector	*sector;

	e->spawn.pos.x /= grid;
	e->spawn.pos.y /= grid;
	// e->spawn.texture.width /= grid;
	// e->spawn.texture.height /= grid;
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
	scale_dots_grid(e, (double)(e->grid_size));
	e->grid_size /= 1.5;
	if (e->grid_size < GRID_SIZE / (1.5 * 3))
		e->grid_size = GRID_SIZE;
	scale_dots_grid(e, (double)(1) / (double)(e->grid_size));
	if (e->select->name == END - 1)
		put_grid(e);
}

void	print_sector(t_env *e)
{
	t_sector	*tmp;
	t_ixy		*tmp2;

	tmp = e->sector->next;
	while (tmp)
	{
		ft_putstr("sector : ");
		ft_putnbr(tmp->index);
		ft_putchar('\n');
		tmp2 = tmp->dots;
		while (tmp2 && tmp2->next)
		{
			printf("a(%d,%d) b(%d,%d)\n", tmp2->x, tmp2->y, tmp2->next->x, tmp2->next->y);
			// ft_putnbr(tmp2->x);
			// ft_putchar(' ');
			// ft_putnbr(tmp2->y);
			// ft_putchar('\n');
			tmp2 = tmp2->next;
		}
		tmp2 = tmp->dots;
		tmp = tmp->next;
	}
	printf("\n SECTORS\n\n");
	tmp = e->sector->next;
	while (tmp)
	{
		ft_putstr("sector : ");
		ft_putnbr(tmp->index);
		ft_putchar('\n');
		tmp2 = tmp->dots;
		while (tmp2 && tmp2->next)
		{
			printf("%d\n", tmp2->next_sector);
			if (tmp2->next_sector == 1)
				printf("a(%d,%d) b(%d,%d)\n", tmp2->x, tmp2->y, tmp2->next->x, tmp2->next->y);
			tmp2 = tmp2->next;
		}
		tmp2 = tmp->dots;
		tmp = tmp->next;
	}
	tmp = e->sector;
}

int		keyhooked(int keycode, t_env *e)
{
	if (keycode == ESC)
		key_esc(e);
	if (!e->sav_zone_bool)
	{
		if (keycode == G)
			sizegrid_change(e);
		if (keycode == A)
			print_sector(e);
		if (keycode == R)
			delete_all_sectors(e);
	}
	else
		fill_write_zone(e, keycode);
	if (e->select->name == END - 1 && e->select->texture_swap)
		put_sav_on_window(e);
	return (0);
}
