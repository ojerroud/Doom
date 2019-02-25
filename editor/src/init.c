/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:56:45 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/25 14:07:32 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	img_sav_pos_n_color(t_img *img, int x, int y, int color)
{
	img->pos.x = x;
	img->pos.y = y;
	img->color = color;
}

void	init_xy(t_img *list, t_env *e)
{
	t_img	*tmp;
	int		cpt_w;
	int		cpt_h;

	tmp = list;
	cpt_w = 0;
	cpt_h = 0;
	while (tmp)
	{
		if (tmp->name == MAIN)
		{
			img_sav_pos_n_color(tmp, WIDTH - tmp->width, HEIGHT - tmp->height - 1, 0x222222);
			e->main = tmp;
		}
		if (tmp->name == SQUARRE)
			img_sav_pos_n_color(tmp, 0, HEIGHT - tmp->height, 0x666666);
		if (tmp->name == SQUARRE2)
			img_sav_pos_n_color(tmp, tmp->width, HEIGHT - tmp->height, 0x666666);
		if (tmp->name >= BUTTON1 && tmp->name < END)
		{
			img_sav_pos_n_color(tmp, 0 + (BUTTON_W * cpt_w), 0 + (BUTTON_H * cpt_h), 0xFFFFFF);
			if (cpt_w)
				cpt_h++;
			cpt_w = !cpt_w;
		}
		tmp->color_swap = 1;
		tmp->texture_swap = 1;
		tmp = tmp->next;
	}
}

int		init_mlx(t_env *e, char *title)
{
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, title);
	init_texture(e);
	create_imgs(e);
	if (!e->mlx.win)
		ft_error("fail create a new window");
	// e->select = e->mlx.img;
	e->grid_size = 64;
	// e->select = 0;
	mlx_mouse_hook(e->mlx.win, mousehooked, e);
	mlx_key_hook(e->mlx.win, keyhooked, e);
	mlx_loop(e->mlx.mlx);
	return (0);
}
