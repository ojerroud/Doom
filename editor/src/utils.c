/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:35:02 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/25 11:58:05 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void    draw_ligne(t_ixy *dots1, t_ixy *dots2, t_env *e)
{
	int		dx;
	int		dy;
	int		i;
	int		xinc;
	int		yinc;
	int		cumul;
	int		x;
	int		y;
	x = dots1->x;
	y = dots1->y;
	dx = dots2->x - dots1->x;
	dy = dots2->y - dots1->y;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	e->central->data[y * e->central->width + x] = DOTS_COLOR;
	// e->mlx.data[y * 400 + x] = DOTS_COLOR;
	// mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y , 0xFFFFFF);
	if (dx > dy)
	{
		cumul = dx / 2;
		i = 0;
		while (++i <= dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			e->central->data[y * e->central->width + x] = DOTS_COLOR;
			// e->mlx.data[y * 400 + x] = DOTS_COLOR;
			// mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y , 0xFFFFFF);
		}
	}
	else
	{
		cumul = dy / 2;
		i = 0;
		while (++i <= dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			e->central->data[y * e->central->width + x] = DOTS_COLOR;
			// e->mlx.data[y * 400 + x] = DOTS_COLOR;
			// mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y , 0xFFFFFF);
		}
	}
}

void	print_list(t_img *list)
{
	t_img	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("|%d| %d %d\n", tmp->name, tmp->width, tmp->height);
		tmp = tmp->next;
	}
}

void	print_click(int button, int x, int y)
{
	ft_putnbr(button);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}