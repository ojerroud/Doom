/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:26:32 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/27 14:59:43 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_ixy	*lstnew22(int x, int y)
{
	t_ixy	*tmp;

	if (!(tmp = (t_ixy *)malloc(sizeof(t_ixy))))
		return (NULL);
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}

void	add_img22(t_ixy *new, t_ixy **list)
{
	new->next = *list;
	*list = new;
}

void	create_list_dots2(t_ixy **list, int x, int y)
{
	t_ixy	*new;

	new = lstnew22(x, y);
	add_img22(new, list);
}

int main(int ac, char **av)
{
    t_env   e;
    t_ixy   *tmp;

    e.dots = NULL;
    create_list_dots2(&e.dots, 5, 10);
    tmp = e.dots;
    
    while (tmp)
    {
        printf("%d %d ", tmp->x, tmp->y);
        tmp = tmp->next;
    }
    create_list_dots2(&e.dots, 55, 10);
    tmp = e.dots;
    printf("\n");
    while (tmp)
    {

        printf("%d %d ", tmp->x, tmp->y);
        tmp = tmp->next;
    }
    create_list_dots2(&e.dots, 5, 100);
    tmp = e.dots;
    printf("\n");
    while (tmp)
    {

        printf("%d %d ", tmp->x, tmp->y);
        tmp = tmp->next;
    }
    tmp = e.dots;
    printf("\n");
    return (0);
}

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