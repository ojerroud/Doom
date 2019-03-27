/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:44:30 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/27 18:02:34 by ojerroud         ###   ########.fr       */
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

void	left_click(t_env *e, int x, int y)
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

void	is_portal(t_env *e, t_ixy *to_check)
{
	if ((to_check->x == e->sector->dots->x
	&& to_check->y == e->sector->dots->y
	&& to_check->next->x == e->sector->dots->next->x
	&& to_check->next->y == e->sector->dots->next->y)
	|| (to_check->x == e->sector->dots->next->x
	&& to_check->y == e->sector->dots->next->y
	&& to_check->next->x == e->sector->dots->x
	&& to_check->next->y == e->sector->dots->y))
		printf("%d %d %d = %d %d\n\n", e->sector->index, e->sector->dots->x, e->sector->dots->y, to_check->x, to_check->y);
}

void	check_portails(t_env *e)
{
	t_sector	*sector;
	t_ixy		*dots;
	t_ixy		*to_check;
	t_sector	*tmp_sector;
	t_ixy		*tmp_dots;

	sector = e->sector;
	while (sector)
	{
		dots = sector->dots;
		while (dots)
		{
			if (dots->next)
				to_check = dots;
			else
				break ;
			tmp_sector = e->sector;
			// e->sector = sector->next;
			while (e->sector)
			{
				if (sector->index == e->sector->index)
				{
					e->sector = e->sector->next;
					continue ;
				}
				tmp_dots = e->sector->dots;
				while (e->sector->dots && e->sector->dots->next)
				{
					is_portal(e, to_check);
					e->sector->dots = e->sector->dots->next;
				}
				e->sector->dots = tmp_dots;
				e->sector = e->sector->next;
			}
			e->sector = tmp_sector;
			dots = dots->next;
		}
		dots = e->sector->dots;
		sector = sector->next;
	}
	sector = e->sector;
}

void	right_click(t_env *e)
{
	t_ixy	*dots;

	dots = e->sector->dots;
	if (!e->sector->dots)
		return ;
	while (dots && dots->next)
		dots = dots->next;
	sav_dots(&e->sector->dots, dots->x, dots->y);
	draw_ligne(e->sector->dots, e->sector->dots->next, e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->central->img_ptr, e->central->pos.x, e->central->pos.y);
	dots = e->sector->dots;
	check_portails(e);
	printf("passage\n");
	e->index++;
	sav_sector(&e->sector, e->index);
}

int		mousehooked(int button, int x, int y, t_env *e)
{
	if (button == MOUSE_LEFT)
		left_click(e, x, y);
	if (button == MOUSE_RIGHT)
		right_click(e);
	return (0);
}
