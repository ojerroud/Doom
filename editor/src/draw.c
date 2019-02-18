/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:00:35 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/18 09:55:05 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include <stdio.h>

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

void    points(t_env *e, char **av)
{
	ligne(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), e);
}

void	print_list(t_img *list)
{
	while (list)
	{
		printf("|%s| %d %d\n", list->name, list->width, list->height);
		list = list->next;
	}
}

void	add_(t_img **alst, t_img *new)
{
	new->next = *alst;
	*alst = new;
}

t_img	*create_(char *name, int width, int height)
{
	t_img   *tmp;

	if(!(tmp = (t_img *)malloc(sizeof(t_img))) || !(tmp->name = (char *)malloc(sizeof(char))))
		return (NULL);
	if (name)
		ft_strcpy(tmp->name, name);
	tmp->width = width;
	tmp->height = height;
	return (tmp);
}

void	create_n_add(t_img **list, char *name, int width, int height)
{
	t_img	*new;

	new = create_(name, width, height);
	add_(list, new);
}

void	draw_imgs(t_env *e)
{
	e->mlx.img = NULL;
	create_n_add(&e->mlx.img, "1", 60, 30);
	create_n_add(&e->mlx.img, "2", 60, 30);
	create_n_add(&e->mlx.img, "3", 400, 400);
	create_n_add(&e->mlx.img, "4", 40, 40);
	print_list(e->mlx.img);
}