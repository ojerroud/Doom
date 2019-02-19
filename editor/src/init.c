/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:56:45 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/19 18:49:08 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		init_mlx(t_env *e, char *title)
{
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, title);
	create_imgs(e);
	e->select = e->mlx.img;
	mlx_mouse_hook(e->mlx.win, mousehooked, e);
	// mlx_hook(e->mlx.win, 17, (1L << 1), key_esc, 0);
	// mlx_loop_hook(e->mlx.mlx, keyhooked, e);
	mlx_key_hook(e->mlx.win, keyhooked, e);
	mlx_loop(e->mlx.mlx);
	return (0);
}