/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:39:49 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/02 14:59:12 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	load_buttons_texture(t_env *e)
{
	int	h;
	int	w;
	int i;

	i = -1;
	e->text[0].name = (char *)malloc(sizeof(char) * (ft_strlen(BALL1) + 1));
	e->text[1].name = (char *)malloc(sizeof(char) * (ft_strlen(BALL2) + 1));
	if (!e->text[0].name || !e->text[1].name)
		ft_error("malloc fail at texture's name");
	ft_strcpy(e->text[0].name, BALL1);
	ft_strcpy(e->text[1].name, BALL2);
	while (++i < LAST)
	{
		e->text[i].img_ptr = mlx_xpm_file_to_image(e->mlx.mlx,
		e->text[i].name, &w, &h);
		if (!e->text[i].img_ptr)
			ft_error("wrong texture");
		e->text[i].data = (int *)mlx_get_data_addr(e->text[i].img_ptr,
		&(e->text[i].bpp), &(e->text[i].size_l), &(e->text[i].endian));
		e->text[i].width = w;
		e->text[i].height = h;
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
		scale_texture_to_buttons(img, e);
		return ;
	}
	if (img->name == CENTRAL)
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
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &(img->bpp)
	, &(img->size_l), &(img->endian));
	setup_img_data(e, img);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, img->img_ptr
	, img->pos.x, img->pos.y);
}

/*
**	create images u need on mlx & give the pos
*/

void	sav_img_pos(t_env *e)
{
	t_img	*tmp;

	tmp = e->mlx.img;
	while (tmp)
	{
		if (tmp->name >= CENTRAL && tmp->name < END)
			create_mlx_img(e, tmp);
		tmp = tmp->next;
	}
}
