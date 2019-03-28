/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:44:30 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/28 17:02:06 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

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
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win
	, e->central->img_ptr, e->central->pos.x, e->central->pos.y);
	dots = e->sector->dots;
	check_portals(e);
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
