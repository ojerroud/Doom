/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:00:35 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/27 10:26:05 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	img_paint(t_env *e, t_img *img)
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
	// if (img->name == MAIN)
	// 	put_grid(e);
}

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

void	create_mlx_img(t_env *e, t_img *img)
{
	img->img_ptr = mlx_new_image(e->mlx.mlx, img->width, img->height);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->size_l), &(img->endian));
	img_paint(e, img);
	// draw_shape(img);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, img->img_ptr, img->pos.x, img->pos.y);
}

void	put_img_pos(t_env *e)
{
	t_img	*tmp;

	tmp = e->mlx.img;
	mlx_clear_window(e->mlx.mlx, e->mlx.win);
	while (tmp)
	{
		if (tmp->name >= MAIN && tmp->name < END)
			create_mlx_img(e, tmp);
		tmp = tmp->next;
	}
}

void	create_imgs(t_env *e)
{
	int		i;

	create_list_img(&e->mlx.img, MAIN, 2 * WIDTH / 3 - SPACING, HEIGHT - SPACING);
	i = 0;
	while (++i < END)
	{
		create_list_img(&e->mlx.img, i, BUTTON_W - SPACING, BUTTON_H - SPACING);
	}
	init_xy(e->mlx.img, e);
	put_img_pos(e);
	e->select = e->mlx.img;
	// create_list_img(&e->mlx.img, BUTTON1, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON2, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON3, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON4, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON5, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON6, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON7, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON8, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON9, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON10, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON11, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON12, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON13, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, BUTTON14, BUTTON_W - SPACING, BUTTON_H - SPACING);
	// create_list_img(&e->mlx.img, SQUARRE, 64, 64);
	// create_list_img(&e->mlx.img, SQUARRE2, 64, 64);
	// print_list(e->mlx.img);
}
