/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:42:05 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/01 16:17:01 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
**	check if click is on the img, then draw
*/

void	paint_if_img(t_img *img, int x, int y, t_env *e)
{
	if (img->pos.x <= x && (img->pos.x + img->width) >= x
	&& img->pos.y <= y && (img->pos.y + img->height) >= y)
	{
		if (img->name >= BUTTON1 && img->name < END)
		{
			e->select = img;
			scale_texture_to_img(img, e);
			istab_draw(img, e);
		}
		if (img->name == CENTRAL && e->select->name == END - 1
		&& img->texture_swap)
			select_dots(img, e, x, y);
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, img->img_ptr
		, img->pos.x, img->pos.y);
	}
	
}

t_img	*lstnew(int name, int width, int height)
{
	t_img	*tmp;

	if (!(tmp = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	tmp->name = name;
	tmp->width = width;
	tmp->height = height;
	return (tmp);
}

void	create_list_img(t_img **list, int name, int width, int height)
{
	t_img	*new;

	new = lstnew(name, width, height);
	new->next = *list;
	*list = new;
}

void	create_imgs(t_env *e)
{
	int		i;

	create_list_img(&e->mlx.img, CENTRAL, 2 * WIDTH
	/ 3 - SPACING, HEIGHT - SPACING);
	i = BUTTON1 - 1;
	while (++i < END)
	{
		create_list_img(&e->mlx.img, i, BUTTON_W - SPACING, BUTTON_H - SPACING);
	}
	init_xy(e->mlx.img, e);
	sav_img_pos(e);
	e->select = e->mlx.img;
}
