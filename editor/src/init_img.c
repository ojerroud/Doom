/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:39:49 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/28 18:17:23 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
**	maybe to see which button is selected
*/

void	draw_shape(t_img	*img)
{
	int	h;
	int	w;

	h = -1;
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
		{
			if (!h || h == img->height - 1 || !w || w == img->width - 1)
			{
				img->data[h * img->width + w] = 0xFF0000;
			}
		}
	}
}

/*
**  get texture or color to img
*/

void	setup_img_data(t_env *e, t_img *img)
{
	int	h;
	int	w;

	if (img->name >= BUTTON1 && img->name < END)
	{
		scale_texture_to_img(img, e);
		return ;
	}
	if (img->name == MAIN)
	{
		h = -1;
		while (++h < img->height)
		{
			w = -1;
			while (++w < img->width)
			{
				img->data[h * img->width + w] = img->color;
			}
		}
	}
}

void	create_mlx_img(t_env *e, t_img *img)
{
	img->img_ptr = mlx_new_image(e->mlx.mlx, img->width, img->height);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->size_l), &(img->endian));
	setup_img_data(e, img);
	// draw_shape(img);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, img->img_ptr, img->pos.x, img->pos.y);
}

/*
**	create images u need on mlx & give the pos
*/

void	sav_img_pos(t_env *e)
{
	t_img	*tmp;

	tmp = e->mlx.img;
	// mlx_clear_window(e->mlx.mlx, e->mlx.win);
	while (tmp)
	{
		if (tmp->name >= MAIN && tmp->name < END)
			create_mlx_img(e, tmp);
		tmp = tmp->next;
	}
}
