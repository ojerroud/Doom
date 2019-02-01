/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:56:45 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/01 15:56:47 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoomNukem.h"

int     init_mlx(t_env *e)
{
    e->mlx.mlx = mlx_init();
    e->mlx.win = mlx_new_window(e->mlx.mlx, WEIGH, HEIGH, "Init");
    mlx_key_hook(e->mlx.win, keyhooked, e);
    mlx_loop(e->mlx.mlx);
    return (0);
}