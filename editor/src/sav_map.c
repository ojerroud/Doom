/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sav_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:04:52 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/03 16:14:44 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static int	g_keycode_to_ascii_alphabet[26] = {0, 11, 8, 2, 14, 3, 5, 4, 34, 38, 40, 37, 46
	, 45, 31, 35, 12, 15, 1, 17, 32, 9, 13, 7, 16, 6};

void	fill_write_zone(t_env *e, int keycode)
{
	int		i;
	int		len;

	if (keycode == 51)
	{
		if (ft_strlen(e->write_zone.str))
			e->write_zone.str[ft_strlen(e->write_zone.str) - 1] = '\0';
	}
	i = -1;
	while (++i < 26)
	{
		if (g_keycode_to_ascii_alphabet[i] == keycode)
		{	
			len = ft_strlen(e->write_zone.str);
			if (len * 10 >= FILENAME_SIZE)
				break;
			e->write_zone.str[len] = i + 97;
			e->write_zone.str[len + 1] = '\0';
			break ;
		}
	}
}

void		writing_area(t_env *e, t_img *img)
{
	e->write_zone.pos.x = img->pos.x;
	e->write_zone.pos.y = img->pos.y;
}

void		button_sav_area(t_env *e, t_img *img)
{
	e->sav_button.pos.x = img->pos.x + (FILENAME_SIZE_W - ft_strlen(e->sav_button.str) * 10) / 2;
	e->sav_button.pos.y = img->pos.y;
}

void		sav_area(t_env *e)
{
	t_img	*list;

	list = e->mlx.img;
	while (list)
	{
		if (list->name == WRITE)
			writing_area(e, list);
		if (list->name == SAV)
			button_sav_area(e, list);
		list = list->next;
	}
	list = e->mlx.img;
	mlx_string_put(e->mlx.mlx, e->mlx.win, e->sav_button.pos.x, e->sav_button.pos.y - 3, WHITE, e->sav_button.str);
	mlx_string_put(e->mlx.mlx, e->mlx.win, e->write_zone.pos.x, e->write_zone.pos.y - 3, 0xFF0000, e->write_zone.str);
}

void		put_sav_on_window(t_env *e)
{
	t_img	*list;

	list = e->mlx.img;
	while (list)
	{
		if (list->name == WRITE || list->name == SAV)
			if (e->select->name == END - 1 && e->select->texture_swap)
				mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, list->img_ptr, list->pos.x, list->pos.y);
		list = list->next;
	}
	list = e->mlx.img;
	sav_area(e);
}
