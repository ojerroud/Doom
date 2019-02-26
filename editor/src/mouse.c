/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:44:30 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/26 13:57:39 by ojerroud         ###   ########.fr       */
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

void	draw_point(t_img *img, int w, int h)
{
	int	i;
	int	j;
	
	i = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
		{
			img->data[(h + j) * img->width + (w + i)] = DOTS_COLOR;
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
	// save_list(e, x, y);
	draw_point(img, x, y);
	// sav_dots(e->dots, x, y);
	// printf("%d %d \n", mod_w, mod_h);
}

void	paint_if_img(t_img	*img, int x, int y, t_env *e)
{
	if (img->pos.x <= x && (img->pos.x + img->width) >= x && img->pos.y <= y && (img->pos.y + img->height) >= y)
	{
		if (img->name >= BUTTON1 && img->name < END)
			e->select = img;
		if (img->name == SQUARRE)
			img_paint(e, img);
		if (img->name >= BUTTON1 && img->name < END)
		{
			scale_texture_to_img(img, e);
			if (img->name == END - 1)
			{
				if (img->texture_swap == 1)
					put_grid(e);
				else
				{
					img_paint(e, e->main);
					mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->main->img_ptr, e->main->pos.x, e->main->pos.y);
				}
			}
		}
		if (img->name == MAIN && e->select->name == END - 1)
			select_dots(img, e, x, y);
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, img->img_ptr, img->pos.x, img->pos.y);
	}
}

void	left_click(int x, int y, t_env *e)
{
	t_img	*list;

	list = e->mlx.img;
	// printf("name = %d => ",e->select->name);
	while (list)
	{
		paint_if_img(list, x, y, e);
		list = list->next;
	}
	list = e->mlx.img;
	while (list)
	{
		if (list->name != e->select->name && list->name >= BUTTON1 && list->name < END)
		{
			list->texture_swap = 1;
			scale_texture_to_img(list, e);
			if (list->name == END - 1)
			{
				img_paint(e, e->main);
				mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->main->img_ptr, e->main->pos.x, e->main->pos.y);
			}
			mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, list->img_ptr, list->pos.x, list->pos.y);
		}
		list = list->next;
	}
	if (e->select->texture_swap == 2)
		e->select = e->main;
	// printf("%d\n",e->select->name);
}

int		mousehooked(int button, int x, int y, t_env *e)
{
	if (button == MOUSE_LEFT)
		left_click(x, y, e);
	// print_click(button, x ,y);
	return (0);
}
