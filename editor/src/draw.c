/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:00:35 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/25 17:07:31 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
**	scale textures on buttons
*/

void	scale_texture_to_img(t_img *img, t_env *e)
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
			/ h_t) * e->text[i].width + (int)(((double)w / w_t))];
	}
	if (img->texture_swap == 2)
		e->central->texture_swap = 1;
	img->texture_swap = (img->texture_swap == 2) ? 1 : 2;
}

/*
**	draw points on draw-tab
*/

void	draw_point(t_img *img, int x, int y)
{
	int	i;
	int	j;
	
	i = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
		{
			img->data[(y + j) * img->width + (x + i)] = DOTS_COLOR;
		}
	}
}

/*
**	maybe to see which button is selected
*/

void	draw_shape(t_img *img)
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
**	put grid & points on img central
*/

void	put_grid(t_env *e)
{
	int		h;
	int		w;
	t_ixy	*tmp;

	h = -1;
	while (++h < e->central->height)
	{
		w = -1;
		while (++w < e->central->width)
		{
			if (!(w % e->grid_size) || !(h % e->grid_size))
				e->central->data[h * e->central->width + w] = GREY;
			else
				e->central->data[h * e->central->width + w] = e->central->color;
		}
	}
	tmp = e->dots;
	while (e->dots)
	{
		draw_point(e->central, e->dots->x, e->dots->y);
		if (e->dots->next)
			draw_ligne(e->sector->dots, e->sector->dots->next, e);
		e->dots = e->dots->next;
	}
	e->dots = tmp;
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->central->img_ptr,
	e->central->pos.x, e->central->pos.y);
}

/*
**	draw & sav dots at position
*/

void	select_dots(t_img *img, t_env *e, int x, int y)
{
	int		mod_w;
	int		mod_h;
	int		rest_w;
	int		rest_h;

	x -= img->pos.x;
	y -= img->pos.y;
	mod_w = x / e->grid_size;
	mod_h = y / e->grid_size;
	rest_w = x % e->grid_size;
	rest_h = y % e->grid_size;
	if (rest_w >= e->grid_size / 2)
		mod_w++;
	if (rest_h >= e->grid_size / 2)
		mod_h++;
	x = mod_w * e->grid_size;
	y = mod_h * e->grid_size;
	draw_point(img, x, y);
	sav_dots(&e->sector->dots, x, y);
	if (e->sector->dots->next)
		draw_ligne(e->sector->dots, e->sector->dots->next, e);
}
