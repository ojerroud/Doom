/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:42:20 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/01 15:13:30 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
**	put grid & points on img central
*/

// void	put_grid(t_env *e)
// {
// 	int		h;
// 	int		w;
// 	t_ixy	*tmp;

// 	h = -1;
// 	while (++h < e->central->height)
// 	{
// 		w = -1;
// 		while (++w < e->central->width)
// 		{
// 			if (!(w % e->grid_size) || !(h % e->grid_size))
// 				e->central->data[h * e->central->width + w] = GREY;
// 			else
// 				e->central->data[h * e->central->width + w] = e->central->color;
// 		}
// 	}
// 	tmp = e->dots;
// 	while (e->dots)
// 	{
// 		draw_point(e->central, e->dots->x, e->dots->y);
// 		e->dots = e->dots->next;
// 	}
// 	e->dots = tmp;
// 	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->central->img_ptr,
// 	e->central->pos.x, e->central->pos.y);
// }
