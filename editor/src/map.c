/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:42:20 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/22 16:36:37 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	put_grid(t_env *e)
{
	t_img	*main;
	int		h;
	int		w;

	main = e->mlx.img;
	while (main)
	{
		if (main->name == MAIN)
			break ;
		main = main->next;
	}
	h = -1;
	while (++h < main->height)
	{
		w = -1;
		while (++w < main->width)
		{
			if (!(w % e->grid_size) || !(h % e->grid_size))
				main->data[h * main->width + w] = WHITE;
			else
				main->data[h * main->width + w] = main->color;
		}
	}
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, main->img_ptr, main->pos.x, main->pos.y);
}
