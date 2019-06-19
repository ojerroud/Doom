/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:38:48 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/19 15:20:52 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

// t_txy	*lstnew_xy(int x, int y)
// {
// 	t_txy	*new;

// 	if (!(new = (t_txy *)malloc(sizeof(t_txy))))
// 		ft_error("malloc fail");
// 	new->x = x;
// 	new->y = y;
// 	return (new);
// }

// void	create_xy_list(t_txy **list, int x ,int y)
// {
// 	t_txy	*new;

// 	new = lstnew_xy(x ,y);
// 	new->next = *list;
// 	*list = new;
// }

// int		mouse(int keycode, int x, int y, t_env *e)
// {
// 	if (keycode == MOUSE_LEFT)
// 		create_xy_list(&e->sprite->pos, x ,y);
// 	return (0);
// }

// void	print_sprites(t_env *e)
// {
// 	t_sprite	*sprite;
// 	t_txy		*xy;

// 	sprite = e->sprite;
// 	while (e->sprite)
// 	{
// 		xy = e->sprite->pos;
// 		while (e->sprite->pos)
// 		{
// 			if (e->sprite->pos->x != -1 && e->sprite->pos->y != -1)
// 				mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->sprite->texture.img_ptr, e->sprite->pos->x, e->sprite->pos->y);
// 			e->sprite->pos = e->sprite->pos->next;
// 		}
// 		e->sprite->pos = xy;
// 		e->sprite = e->sprite->next;
// 	}
// 	e->sprite = sprite;
// }

// int		key(int keycode, t_env *e)
// {
// 	if (keycode == ESC)
// 		exit(0);
// 	if (keycode == A)
// 		print_sprites(e);
// 	if (keycode == C)
// 		mlx_clear_window(e->mlx.mlx, e->mlx.win);
// 	e->index +=0;
// 	return (0);
// }


// void	test(t_env *e)
// {
// 	e->sprite = NULL;
// 	e->mlx.mlx = mlx_init();
// 	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "test");
// 	if (!e->mlx.win)
// 		ft_error("fail create a new window");
// 	get_sprites(e);
// 	mlx_mouse_hook(e->mlx.win, mouse, e);
// 	mlx_key_hook(e->mlx.win, key, e);
// 	mlx_loop(e->mlx.mlx);
// }

int		main(int ac, char **av)
{
	t_env	e;

	e.av = av;
	e.ac = ac;
	// test(&e);
	init_vars(&e);
	init_mlx(&e, "editor");
	return (0);
}
