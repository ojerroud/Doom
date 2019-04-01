/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sav_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:04:52 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/01 17:53:34 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

// static int	g_keycode_to_ascii_alphabet[26] = {0, 11, 8, 2, 14, 3, 5, 4, 34, 38
// 	, 40, 37, 46, 45, 31, 35, 12, 15, 1, 17, 32, 9, 13, 7, 16, 6};

void		color_img(int *data, int width, int height, int color)
{
	int	w;
	int	h;

	h = -1;
	while (++h < height)
	{
		w = -1;
		while (++w < width)
			data[h * width + w] = color;
	}
}

void		put_str_on_window(t_env *e, char *entry, int nbr)
{
	char		*str;
	char		*itoa;

	itoa = ft_itoa(nbr);
	str = ft_strnew(ft_strlen(entry) + nbr);
	str = ft_strcat(ft_strcpy(str, entry), itoa);
	ft_strdel(&itoa);
	mlx_string_put(e->mlx.mlx, e->mlx.win, e->file.pos.x, e->file.pos.y
	, WHITE, str);
}

// void		bouton_validate(t_env *e)
// {

// }

// void		put_sav_values(t_env *e)
// {
// 	t_sector	*sector;
// 	t_ixy		*dots;
// 	int			cpt;

	
// 	e->file.pos.y = e->central->pos.y + 10;
// 	e->file.pos.x = e->central->pos.x + 10;
// 	sector = e->sector->next;
// 	// put_str_on_window(e, "Nombre de secteur(s) : ", e->sector->index);
// 	// while (sector)
// 	// {
// 	// 	e->file.pos.y += 20;
// 	// 	e->file.pos.x = e->central->pos.x + 10;
// 	// 	put_str_on_window(e, "Sector ", sector->index);
// 	// 	dots = sector->dots;
// 	// 	cpt = 0;
// 	// 	while (dots && dots->next)
// 	// 	{
// 	// 		cpt++;
// 	// 		dots = dots->next;
// 	// 	}
// 	// 	dots = sector->dots;
// 	// 	sector = sector->next;
// 	// }
// }
