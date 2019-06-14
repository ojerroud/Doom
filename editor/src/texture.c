/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:30:13 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/14 16:39:00 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

// void	init_texture(char *path, )

void	scale_texture_to_img(t_img *img, t_text texture)
{
	int		w;
	int		h;
	double	w_t;
	double	h_t;

	h = -1;
	w_t = (double)img->width / texture.width;
	h_t = (double)img->height / texture.height;
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
			img->data[h * img->width + w] = texture.data[(int)((double)h
			/ h_t) * texture.width + (int)(((double)w / w_t))];
	}
}

/*
**	scale textures on buttons
*/

void	scale_texture_to_buttons(t_img *img, t_env *e)
{
	int		w;
	int		h;
	double	w_t;
	double	h_t;
	int		i;

	h = -1;
	i = (img->texture_swap == 1 || img->texture_swap == 0) ? 0 : 1;
	w_t = (double)img->width / e->text[i].width;
	h_t = (double)img->height / e->text[i].height;
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
			img->data[h * img->width + w] = e->text[i].data[(int)((double)h
			/ h_t) * e->text[i].width + (int)((double)w / w_t)];
	}
	if (img->texture_swap == 2)
		e->central->texture_swap = 1;
	img->texture_swap = (img->texture_swap == 2) ? 1 : 2;
}

void	put_texture_transparency(t_env *e, t_img *img, t_sprite list)
{
	int w;
	int h;

	h = -1;
	while (++h < list.texture.height)
	{
		w = -1;
		while (++w < list.texture.width)
			if (list.texture.data[h * list.texture.width + w] != 0xFFFFFF)
				img->data[((h * e->grid_size / 20) + list.pos.y) * img->width + ((w * e->grid_size / 20)+ list.pos.x)] = list.texture.data[h * list.texture.width + w];
	}
	draw_cross(e, e->spawn.pos.x, e->spawn.pos.y);
}
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
		scale_texture_to_buttons(list, e);
		if (list->name == END - 1)
		{
			setup_img_data(e, e->central);
			mlx_put_image_to_window(e->mlx.mlx, e->mlx.win
			, e->central->img_ptr, e->central->pos.x, e->central->pos.y);
		}
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, list->img_ptr
		, list->pos.x, list->pos.y);
	}
}
