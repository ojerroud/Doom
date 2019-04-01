/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabdraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:07:34 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/01 16:24:57 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	istab_draw(t_img *img, t_env *e)
{
	if (img->name == END - 1)
	{
		if (img->texture_swap == 1)
		{
			put_grid(e);
		}
		else
		{
			setup_img_data(e, e->central);
			mlx_put_image_to_window(e->mlx.mlx, e->mlx.win,
			e->central->img_ptr, e->central->pos.x, e->central->pos.y);
		}
	}
}

