/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:56:45 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/03 16:16:36 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	img_param(t_img *img, int x, int y, int color)
{
	img->pos.x = x;
	img->pos.y = y;
	img->color = color;
}

/*
**	init x, y & init texture/color swap
*/

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
		if (tmp->name == CENTRAL)
		{
			img_param(tmp, WIDTH - tmp->width, 0, GREY2);
			e->central = tmp;
		}
		if (tmp->name == WRITE)
			img_param(tmp, WIDTH - tmp->width, HEIGHT - (tmp->height * 2) - 1, WHITE);
		if (tmp->name == SAV)
			img_param(tmp, WIDTH - tmp->width, HEIGHT - tmp->height, 0x005555);
		if (tmp->name >= BUTTON1 && tmp->name < END)
		{
			img_param(tmp, 0 + (BUTTON_W * cpt_w), 0 + (BUTTON_H * cpt_h)
			, WHITE);
			(cpt_w) ? cpt_h++ : 0;
			cpt_w = !cpt_w;
		}
		tmp->color_swap = 1;
		tmp->texture_swap = 0;
		tmp = tmp->next;
	}
}

void	init_vars(t_env *e)
{
	e->mlx.img = NULL;
	e->dots = NULL;
	e->sector = NULL;
	e->index = 0;
	e->sav_zone_bool = 0;
	sav_sector(&e->sector, e->index);
	e->grid_size = GRID_SIZE;
	e->var.swap = 0;
	ft_bzero(e->sav_button.str, FILENAME_SIZE_W);
	ft_strcpy(e->sav_button.str, "Valider");
	ft_bzero(e->write_zone.str, FILENAME_SIZE_W);
}

void	init_mlx(t_env *e, char *title)
{
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, title);
	if (!e->mlx.win)
		ft_error("fail create a new window");
	load_buttons_texture(e);
	create_imgs(e);
	mlx_mouse_hook(e->mlx.win, mousehooked, e);
	mlx_key_hook(e->mlx.win, keyhooked, e);
	mlx_loop(e->mlx.mlx);
}
