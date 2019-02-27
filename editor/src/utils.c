/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:35:02 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/27 15:40:42 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void    ligne(int xi,int yi,int xf,int yf, t_env *e)
{
	int dx,dy,i,xinc,yinc,cumul,x,y;
	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y , 0xFFFFFF);
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
			mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y , 0xFFFFFF);
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
			mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y , 0xFFFFFF);
		}
	}
}

void    ligne22(int xi,int yi,int xf,int yf, t_env *e);
void    ligne2(t_ixy *dots1, t_ixy *dots2, t_env *e)
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
	mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y , 0xFFFFFF);
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
			mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y , 0xFFFFFF);
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
			mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y , 0xFFFFFF);
		}
	}
}

void    points(t_env *e, char **av)
{
	ligne(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), e);
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
