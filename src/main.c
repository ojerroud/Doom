/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:59:32 by ojerroud          #+#    #+#             */
/*   Updated: 2018/09/10 11:59:34 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

int init_win(t_env *e)
{
    e->mlx.mlx = mlx_init();
    e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "Doom Nukem");
    mlx_key_hook (e->mlx.win, key_hook, 0);
    mlx_loop(e->mlx.mlx);
    return (0);
}

int main(int ac, char **av)
{
    t_env   e;

    if (ac != 2)
        return (0);
    read_param(&e, av[1]);
    init_win(&e);
    return (0);
}