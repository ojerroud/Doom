/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:44:30 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/22 17:12:12 by ojerroud         ###   ########.fr       */
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

void	paint_if_img(t_img	*img, int x, int y, t_env *e)
{
	if (img->pos.x <= x && (img->pos.x + img->width) >= x && img->pos.y <= y && (img->pos.y + img->height) >= y)
	{
		img->color += (img->color_swap * 0x222222);
		img->color_swap *= -1;
		e->select = img;
		if (img->name == SQUARRE)
			img_paint(e, img);
		else if (img->name >= BUTTON1 && img->name < END)
		{
			scale_texture_to_img(img, e);
			put_grid(e);
		}
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, img->img_ptr,
		img->pos.x, img->pos.y);
	}
	printf("%d\n", e->select->name);
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
}

int		mousehooked(int button, int x, int y, t_env *e)
{
	if (button == MOUSE_LEFT)
		left_click(x, y, e);
	// print_click(button, x ,y);
	return (0);
}
