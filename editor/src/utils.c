/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:35:02 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/29 10:23:48 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	draw_ligne_point_to_point_swap_vars(t_var *var)
{
	int	tmp;

	tmp = var->dx;
	var->dx = var->dy;
	var->dy = tmp;
	tmp = var->x;
	var->x = var->y;
	var->y = tmp;
	tmp = var->xinc;
	var->xinc = var->yinc;
	var->yinc = tmp;
}

void	draw_ligne_point_to_point(t_env *e, t_ixy *dot)
{
	while (++(e->var.i) <= e->var.dx)
	{
		e->var.x += e->var.xinc;
		e->var.cumul += e->var.dy;
		if (e->var.cumul >= e->var.dx)
		{
			e->var.cumul -= e->var.dx;
			e->var.y += e->var.yinc;
		}
		(e->var.swap == 1) ? draw_ligne_point_to_point_swap_vars(&e->var) : 0;
		e->central->data[e->var.y * e->central->width + e->var.x] = dot->color;
		(e->var.swap == 1) ? draw_ligne_point_to_point_swap_vars(&e->var) : 0;
	}
}

void	draw_ligne(t_ixy *dots1, t_ixy *dots2, t_env *e)
{
	e->var.x = dots1->x;
	e->var.y = dots1->y;
	e->var.dx = dots2->x - dots1->x;
	e->var.dy = dots2->y - dots1->y;
	e->var.xinc = (e->var.dx > 0) ? 1 : -1;
	e->var.yinc = (e->var.dy > 0) ? 1 : -1;
	e->var.dx = abs(e->var.dx);
	e->var.dy = abs(e->var.dy);
	e->central->data[e->var.y * e->central->width + e->var.x] = dots1->color;
	e->var.swap = (e->var.dx <= e->var.dy) ? 1 : 0;
	(e->var.dx <= e->var.dy) ? draw_ligne_point_to_point_swap_vars(&e->var) : 0;
	e->var.cumul = e->var.dx / 2;
	e->var.i = 0;
	draw_ligne_point_to_point(e, dots1);
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
