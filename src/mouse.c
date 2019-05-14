/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:44:30 by ojerroud          #+#    #+#             */
/*   Updated: 2019/05/14 15:01:25 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoomNukem.h"

int mousehooked(int button, int x, int y, t_env *e)
{
    ft_putnbr(button);
    ft_putchar(' ');
    ft_putnbr(x);
    ft_putchar(' ');
    ft_putnbr(y);
    ft_putchar('\n');
    e->is_title += 0;
    return (0);
}