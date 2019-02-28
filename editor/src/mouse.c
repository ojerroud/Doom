/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:44:30 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/28 19:10:29 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	print_click(int button, int x, int y)
{
	ft_putnbr(button);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

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
	sav_dots(&e->dots, x, y);
}

/*
**	check if click is on the img, then do what should do
*/

void	paint_if_img(t_img	*img, int x, int y, t_env *e)
{
	if (img->pos.x <= x && (img->pos.x + img->width) >= x && img->pos.y <= y && (img->pos.y + img->height) >= y)
	{
		// if (img->name == SQUARRE)
		// 	img_paint(e, img);
		if (img->name >= BUTTON1 && img->name < END)
		{
			e->select = img;
			scale_texture_to_img(img, e);
			istab_draw(img, e);
		}
		if (img->name == MAIN && e->select->name == END - 1 && img->texture_swap)
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
			setup_img_data(e, e->main);
			mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->main->img_ptr, e->main->pos.x, e->main->pos.y);
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
		e->select = e->main;
}

void	right_click(t_env *e)
{
	t_ixy	*tmp;

	tmp = e->dots;
	if (!e->dots)
		return ;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
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
