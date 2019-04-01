/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:00:35 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/01 18:00:32 by ojerroud         ###   ########.fr       */
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
	int i;
	int j;

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

void	draw_points_on_list(t_env *e)
{
	t_ixy		*dots;
	t_sector	*sector;

	sector = e->sector;
	while (sector)
	{
		dots = sector->dots;
		while (sector->dots)
		{
			draw_point(e->central, sector->dots->x, sector->dots->y);
			if (sector->dots->next)
				draw_ligne(sector->dots, sector->dots->next, e);
			sector->dots = sector->dots->next;
		}
		sector->dots = dots;
		sector = sector->next;
	}
	sector = e->sector;
}

/*
**	put grid & points on img central
*/

void	put_grid(t_env *e)
{
	int			h;
	int			w;

	h = -1;
	while (++h < e->central->height)
	{
		w = -1;
		while (++w < e->central->width)
			e->central->data[h * e->central->width + w] = (!(w % e->grid_size)
			|| !(h % e->grid_size)) ? GREY : e->central->color;
	}
	draw_points_on_list(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->central->img_ptr,
	e->central->pos.x, e->central->pos.y);
}

void	put_file_sav(t_env *e, t_img *central)
{
	int		w;
	int		h;

	h = -1;
	while (++h < 20)
	{
		w = -1;
		while (++w < FILENAME_SIZE)
		{
			central->data[h * FILENAME_SIZE + w] = WHITE;
		}
	}
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
	put_file_sav(e, e->centra);
}
