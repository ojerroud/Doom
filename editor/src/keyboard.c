/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:28:37 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/27 16:12:29 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	key_esc(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	exit(0);
}

// void	select_img(t_env *e)
// {
// 	t_img	*tmp;

// 	tmp = e->mlx.img;
// 	printf("avant : |%d| =>", e->select->name);
// 	while (tmp)
// 	{
// 		if (!tmp)
// 			tmp = e->mlx.img;
// 		if (e->select->name == tmp->name)
// 		{
// 			if (!(tmp->next))
// 			{
// 				e->select = e->mlx.img;
// 				break ;
// 			}
// 			e->select = tmp->next;
// 			break ;
// 		}
// 		tmp = tmp->next;
// 	}
// 	printf("|%d|\n", e->select->name);
// }

// void	move(t_env *e, int x, int y)
// {
// 	e->select->pos.x += x;
// 	e->select->pos.y += y;
// 	put_img_pos(e);
// }

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
	// if (e->select->name == END - 1 && e->select->texture_swap == 1)
	// {
	// 	while (e->dots)
	// 	{
	// 		draw_point(e->main, e->dots->x, e->dots->y);
	// 		e->dots = e->dots->next;
	// 	}
	// 	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->main->img_ptr, e->main->pos.x, e->main->pos.y);
	// }
	// e->dots = tmp;
}

int		keyhooked(int keycode, t_env *e)
{
	// printf("%d\n", keycode);
	if (keycode == ESC)
		key_esc(e);
	// if (keycode == C)
	// 	select_img(e);
	if (keycode == G)
		sizegrid_change(e);
	// if (keycode == LEFT)
	// 	move(e, -10, 0);
	// if (keycode == RIGHT)
	// 	move(e, 10, 0);
	// if (keycode == DOWN)
	// 	move(e, 0, 10);
	// if (keycode == UP)
	// 	move(e, 0, -10);
	if (keycode == W)
		mlx_clear_window(e->mlx.mlx, e->mlx.win);
	return (0);
}
