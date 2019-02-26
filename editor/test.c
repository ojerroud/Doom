/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:26:32 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/26 17:02:54 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void    c(t_env *e)
{
    create_list_dots(&e->dots, 5, 10);
    create_list_dots(&e->dots, 10, 15);
    create_list_dots(&e->dots, 55, 10);
}

void    init(t_env *e)
{
    c(e);
}

int main(int ac, char **av)
{
    t_env   e;

    e.dots = NULL;
    init(&e);
    while (e.dots)
    {
        printf("%d %d\n", e.dots->x, e.dots->y);
        e.dots = e.dots->next;
    }
    return (0);
}