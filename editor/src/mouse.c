/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:44:30 by ojerroud          #+#    #+#             */
/*   Updated: 2019/07/01 13:16:45 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	reset_texture_buttons(t_env *e, t_img *img)
{
	t_img	*list;

	list = img;
	while (img)
	{
		if (img->name != e->select->name && img->name >= BUTTON1 && img->name < END)
		{
			img->texture_swap = 2;
			scale_texture_to_buttons(img, e);
		}
		img = img->next;
	}
}

void	left_click(t_env *e, int x, int y)
{
	t_img	*list;

	e->sav_zone_bool = 0;
	list = e->mlx.lst_img;
	while (list)
	{
		paint_if_img(list, x, y, e);
		list = list->next;
	}
	list = e->mlx.lst_img;
	while (list)
	{
		appli_buttons_text(list, e);
		list = list->next;
	}
	// if (e->select->name == END - 2)
	// {
	// 	if (e->select->texture_swap <= 1)
	// 		put_sav_values(e);
	// 	else
	// 	{
	// 		setup_img_data(e, e->central);
	// 		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win,
	// 		e->central->img_ptr, e->central->pos.x, e->central->pos.y);
	// 	}	
	// } 
	// printf("|%s|\n", e->write_zone.str);
	// if (e->sector->next)
	// 	printf("pas vide\n");
	// else
	// 	printf("vide\n");
	if (e->select->texture_swap == 2)
		e->select = e->central;
}

void	right_click(t_env *e)
{
	t_ixy	*dots;

	finish_put_sprite(e);
	dots = e->sector->dots;
	if (!e->sector->dots)
		return ;
	while (dots && dots->next)
		dots = dots->next;
	sav_dots(&e->sector->dots, dots->x, dots->y);
	dots = e->sector->dots;
	check_portals(e);
	put_grid(e);
	e->index++;
	sav_sector(&e->sector, e->index);
}

/*
**	put draw on put_sav_on_window, it draw the central image.
*/

int		mousehooked(int button, int x, int y, t_env *e)
{
	mlx_clear_window(e->mlx.mlx, e->mlx.win);
	if (button == MOUSE_LEFT)
		left_click(e, x, y);
	else if (button == MOUSE_RIGHT)
		right_click(e);
	draw_lst(e);
	if ((e->select->name == END - 1 && e->select->texture_swap == 1) 
	|| (e->select->name >= WRITE && e->select->name < BUTTON1))
		put_sav_on_window(e);
	return (0);
}
