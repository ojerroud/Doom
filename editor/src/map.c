/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:42:20 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/25 17:10:53 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	put_grid(t_env *e)
{
	int		h;
	int		w;

	h = -1;
	while (++h < e->main->height)
	{
		w = -1;
		while (++w < e->main->width)
		{
			if ((!(w % e->grid_size) && w )|| (!(h % e->grid_size) && h))
				e->main->data[h * e->main->width + w] = GREY;
			else
				e->main->data[h * e->main->width + w] = e->main->color;
		}
	}
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->main->img_ptr, e->main->pos.x, e->main->pos.y);
}
