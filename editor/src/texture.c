/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:30:13 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/28 17:06:30 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
**	give texture to button
**	add or delete grid if needed
*/

void	appli_buttons_text(t_img *list, t_env *e)
{
	if (list->name != e->select->name && list->name >= BUTTON1
	&& list->name < END)
	{
		list->texture_swap = 1;
		scale_texture_to_img(list, e);
		if (list->name >= END - 1)
		{
			setup_img_data(e, e->central);
			mlx_put_image_to_window(e->mlx.mlx, e->mlx.win
			, e->central->img_ptr, e->central->pos.x, e->central->pos.y);
		}
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, list->img_ptr
		, list->pos.x, list->pos.y);
	}
}
