/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:44:30 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/19 12:10:18 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void    cell_pressed()
{

}

int     mousehooked(int button, int x, int y, t_env *e)
{
    t_img   *list;

    list = e->mlx.img;
    while (list)
    {
        if (button == 1 && list->pos.x <= x && (list->pos.x + list->width) >= x && list->pos.y <= y && (list->pos.y + list->height) >= y)
        {
            list->color += (list->color_swap * 0x222222);
            list->color_swap *= -1;
            put_img_pos(e);
        }
        list = list->next;
    }
    ft_putnbr(button);
    ft_putchar(' ');
    ft_putnbr(x);
    ft_putchar(' ');
    ft_putnbr(y);
    ft_putchar('\n');
    e->is_title += 0;

    return (0);
}