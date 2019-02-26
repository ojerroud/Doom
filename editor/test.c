/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:26:32 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/26 15:29:32 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void    c(t_env *e)
{
    e->silent = 0 ;
}

void    init(t_env *e)
{
    e->dots = NULL;
}

int main(int ac, char **av)
{
    t_env   e;

    init(&e);
    return (0);
}