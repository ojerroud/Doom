/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:00:35 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/19 19:06:39 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	change_color(t_env *e, t_img *img)
{
	int	h;
	int	w;

	h = -1;
	// if (img->name == SQUARRE)
	// 	put_texture(img, e);
	e->silent++;
	if (img->name >= BUTTON1 && img->name < END)
	{
		scale_texture_to_img(img, e);
		return ;
	}
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
		{
			if (img->name == MAIN)
				img->data[h * img->width + w] = img->color;
			if (img->name == SQUARRE)
				img->data[h * img->width + w] = e->text[0].data[h * img->width + w];
			// if (img->name == SQUARRE2)
			// 	img->data[h * img->width + w] = e->text[1].data[h * img->width + w];
			// if (img->name >= BUTTON1 && img->name < END)
				// img->data[h * img->width + w] = img->color;
		}
	}
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
			img->data[h * img->width + w] = 0x000000;
		}
	}
}

void	create_mlx_img(t_env *e, t_img *img)
{
	img->img_ptr = mlx_new_image(e->mlx.mlx, img->width, img->height);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->size_l), &(img->endian));
	change_color(e, img);
	// draw_shape(img);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, img->img_ptr, img->pos.x, img->pos.y);
} 

void	put_img_pos(t_env	*e)
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

void	add_(t_img **alst, t_img *new)
{
	new->next = *alst;
	*alst = new;
}

t_img	*create_(int name, int width, int height)
{
	t_img   *tmp;

	if(!(tmp = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	tmp->name = name;
	tmp->width = width;
	tmp->height = height;
	return (tmp);
}

void	create_list_img(t_img **list, int name, int width, int height)
{
	t_img	*new;

	new = create_(name, width, height);
	add_(list, new);
}

void	img_sav_pos_n_color(t_img *img, int x, int y, int color)
{
	img->pos.x = x;
	img->pos.y = y;
	img->color = color;
}

void	init_xy(t_img	*list)
{
	t_img	*tmp;
	int		cpt_w;
	int		cpt_h;

	tmp = list;
	cpt_w = 0;
	cpt_h = 0;
	while (tmp)
	{
		if (tmp->name == MAIN)
			img_sav_pos_n_color(tmp, WIDTH - tmp->width, HEIGHT - tmp->height - 1, 0x222222);
		if (tmp->name == SQUARRE)
			img_sav_pos_n_color(tmp, 0, HEIGHT - tmp->height, 0x666666);
		// if (tmp->name == SQUARRE2)
		// 	img_sav_pos_n_color(tmp, tmp->width, HEIGHT - tmp->height, 0x666666);
		if (tmp->name >= BUTTON1)
		{
			img_sav_pos_n_color(tmp, 0 + (BUTTON_W * cpt_w), 0 + (BUTTON_H * cpt_h), 0xFFFFFF);
			if (cpt_w)
				cpt_h ++;
			cpt_w = !cpt_w;
		}
		tmp->color_swap = 1;
		tmp->texture_swap = 0;
		// printf("%d %d %d || %d %d\n", tmp->name, tmp->pos.x, tmp->pos.y, tmp->width, tmp->height);
		tmp = tmp->next;
	}
}

void	create_imgs(t_env *e)
{
	e->mlx.img = NULL;
	create_list_img(&e->mlx.img, MAIN, 2 * WIDTH / 3 - 1, HEIGHT - 1);
	create_list_img(&e->mlx.img, BUTTON1, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON2, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON3, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON4, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON5, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON6, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON7, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON8, BUTTON_W - 1, BUTTON_H - 1);
	// create_list_img(&e->mlx.img, BUTTON9, BUTTON_W - 1, BUTTON_H - 1);
	// create_list_img(&e->mlx.img, BUTTON10, BUTTON_W - 1, BUTTON_H - 1);
	// create_list_img(&e->mlx.img, BUTTON11, BUTTON_W - 1, BUTTON_H - 1);
	// create_list_img(&e->mlx.img, BUTTON12, BUTTON_W - 1, BUTTON_H - 1);
	// create_list_img(&e->mlx.img, BUTTON13, BUTTON_W - 1, BUTTON_H - 1);
	// create_list_img(&e->mlx.img, BUTTON14, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, SQUARRE, 64, 64);
	// create_list_img(&e->mlx.img, SQUARRE2, 64, 64);
	init_xy(e->mlx.img);
	init_texture(e);
	put_img_pos(e);
	// print_list(e->mlx.img);
}