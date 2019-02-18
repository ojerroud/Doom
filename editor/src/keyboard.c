/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:28:37 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/18 17:05:36 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	key_esc(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	exit(0);
}

void	select_img(t_env *e)
{
	t_img	*tmp;

	tmp = e->mlx.img;
	while (tmp)
	{
		if (!tmp)
			tmp = e->mlx.img;
		if (e->select->name == tmp->name)
		{
			if (!(tmp->next))
			{
				e->select = e->mlx.img;
				break;
			}
			e->select = tmp->next;

			break;
		}
		tmp = tmp->next;
	}
	printf("|%d|\n", e->select->name);
}

void	move(t_env *e, int x, int y)
{
	e->select->pos.x += x;
	e->select->pos.y += y;
	put_img_pos(e);
	printf("%d %d\n", e->select->pos.x, e->select->pos.y);
}

int		keyhooked(int keycode, t_env *e)
{
	ft_putnbr(keycode);
	ft_putendl("");
	if (keycode == ESC)
		key_esc(e);
	if (keycode == C)
		select_img(e);
	if (keycode == LEFT)
		move(e, -10, 0);
	if (keycode == RIGHT)
		move(e, 10, 0);
	if (keycode == DOWN)
		move(e, 0, 10);
	if (keycode == UP)
		move(e, 0, -10);
	if (keycode == W)
		mlx_clear_window(e->mlx.mlx, e->mlx.win);
	return (0);
}
