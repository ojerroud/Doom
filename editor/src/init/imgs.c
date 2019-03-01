/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:42:05 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/01 10:58:41 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_img	*lstnew(int name, int width, int height)
{
	t_img	*tmp;

	if (!(tmp = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	tmp->name = name;
	tmp->width = width;
	tmp->height = height;
	return (tmp);
}

void	add_img(t_img *new, t_img **list)
{
	new->next = *list;
	*list = new;
}

void	create_list_img(t_img **list, int name, int width, int height)
{
	t_img	*new;

	new = lstnew(name, width, height);
	add_img(new, list);
}

void	create_imgs(t_env *e)
{
	int		i;

	create_list_img(&e->mlx.img, CENTRAL, 2 * WIDTH / 3 - SPACING, HEIGHT - SPACING);
	i = BUTTON1 - 1;
	while (++i < END)
	{
		create_list_img(&e->mlx.img, i, BUTTON_W - SPACING, BUTTON_H - SPACING);
	}
	init_xy(e->mlx.img, e);
	sav_img_pos(e);
	e->select = e->mlx.img;
	// create_list_img(&e->mlx.img, SQUARRE, 64, 64);
	// create_list_img(&e->mlx.img, SQUARRE2, 64, 64);
	// print_list(e->mlx.img);
}