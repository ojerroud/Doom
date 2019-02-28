/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:30:13 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/28 17:26:31 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
**	scale textures on buttons
*/

void	scale_texture_to_img(t_img *img, t_env *e)
{
	int		w;
	int		h;
	double	w_t;
	double	h_t;
	int		i;

	h = -1;
	i = (img->texture_swap == 1 || img->texture_swap == 0) ? 0 : 1;
	w_t = (double)img->width / e->text[i].width;
	h_t = (double)img->height / e->text[i].height;
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
			img->data[h * img->width + w] = e->text[i].data[(int)((double)h
			/ h_t) * e->text[i].width + (int)(((double)w / w_t))];
	}
	if (img->texture_swap == 2)
		e->main->texture_swap = 1;
	img->texture_swap = (img->texture_swap == 2) ? 1 : 2;
}

void	load_buttons_texture(t_env *e)
{
	int	h;
	int	w;
	int i;

	i = -1;
	e->text[0].name = (char *)malloc(sizeof(char) * (ft_strlen(BALL1) + 1));
	e->text[1].name = (char *)malloc(sizeof(char) * (ft_strlen(BALL2) + 1));
	if (!e->text[0].name || !e->text[1].name)
		ft_error("malloc fail at texture's name");
	ft_strcpy(e->text[0].name, BALL1);
	ft_strcpy(e->text[1].name, BALL2);
	while (++i < LAST)
	{
		e->text[i].img_ptr = mlx_xpm_file_to_image(e->mlx.mlx,
		e->text[i].name, &w, &h);
		if (!e->text[i].img_ptr)
			ft_error("wrong texture");
		e->text[i].data = (int *)mlx_get_data_addr(e->text[i].img_ptr,
		&(e->text[i].bpp), &(e->text[i].size_l), &(e->text[i].endian));
		e->text[i].width = w;
		e->text[i].height = h;
	}
}
