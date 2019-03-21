/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:44:30 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/21 16:08:17 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"


/*
**	check if click is on the img, then do what should do
*/

void	paint_if_img(t_img *img, int x, int y, t_env *e)
{
	if (img->pos.x <= x && (img->pos.x + img->width) >= x && img->pos.y <= y && (img->pos.y + img->height) >= y)
	{
		if (img->name >= BUTTON1 && img->name < END)
		{
			e->select = img;
			scale_texture_to_img(img, e);
			istab_draw(img, e);
		}
		if (img->name == CENTRAL && e->select->name == END - 1 && img->texture_swap)
			select_dots(img, e, x, y);
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, img->img_ptr, img->pos.x, img->pos.y);
	}
}

/*
**	give texture to button
**	add or delete grid if needed
*/

void	appli_buttons_text(t_img *list, t_env *e)
{
	if (list->name != e->select->name && list->name >= BUTTON1 && list->name < END)
	{
		list->texture_swap = 1;
		scale_texture_to_img(list, e);
		if (list->name >= END - 1)
		{
			setup_img_data(e, e->central);
			mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->central->img_ptr, e->central->pos.x, e->central->pos.y);
		}
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, list->img_ptr, list->pos.x, list->pos.y);
	}
}

void	left_click(int x, int y, t_env *e)
{
	t_img	*list;

	list = e->mlx.img;
	while (list)
	{
		paint_if_img(list, x, y, e);
		list = list->next;
	}
	list = e->mlx.img;
	while (list)
	{
		appli_buttons_text(list, e);
		list = list->next;
	}
	if (e->select->texture_swap == 2)
		e->select = e->central;
}

void	right_click(t_env *e)
{
	t_ixy	*tmp;

	tmp = e->dots;
	if (!e->dots)
		return ;
	while (tmp && tmp->next)
		tmp = tmp->next;
	sav_dots(&e->dots, tmp->x, tmp->y);
	tmp = e->dots;
}

int		mousehooked(int button, int x, int y, t_env *e)
{
	if (button == MOUSE_LEFT)
		left_click(x, y, e);
	if (button == MOUSE_RIGHT)
		right_click(e);
		// printf("%d\n", e->test);
	// print_click(button, x ,y);
	return (0);
}
