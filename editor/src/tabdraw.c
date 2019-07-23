/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabdraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:07:34 by ojerroud          #+#    #+#             */
/*   Updated: 2019/07/01 13:13:34 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	istab_draw(t_img *img, t_env *e)
{
	// t_img	*lst;
	if (img->name == END - 1)
	{
		// lst = e->mlx.lst_sprite;
		// while (lst)
		// {
		// 	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.lst_sprite->img_ptr, e->mlx.lst_sprite->pos.x, e->mlx.lst_sprite->pos.y);
		// 	lst = lst->next;
		// }
		if (img->texture_swap == 1)
		{
			e->mlx.todraw_sprite = 1;
			put_grid(e);
			// mlx_clear_window(e->mlx.mlx, e->mlx.win);
			// draw_lst(e);
		}
		else
		{
			e->mlx.todraw_sprite = 0;
			setup_img_data(e, e->central);
			mlx_put_image_to_window(e->mlx.mlx, e->mlx.win,
			e->central->img_ptr, e->central->pos.x, e->central->pos.y);
		}
	}
}
