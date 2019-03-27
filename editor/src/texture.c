	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:30:13 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/01 12:59:20 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
**	scale textures on buttons
*/

// void	scale_texture_to_img(t_img *img, t_env *e)
// {
// 	int		w;
// 	int		h;
// 	double	w_t;
// 	double	h_t;
// 	int		i;

// 	h = -1;
// 	i = (img->texture_swap == 1 || img->texture_swap == 0) ? 0 : 1;
// 	w_t = (double)img->width / e->text[i].width;
// 	h_t = (double)img->height / e->text[i].height;
// 	while (++h < img->height)
// 	{
// 		w = -1;
// 		while (++w < img->width)
// 			img->data[h * img->width + w] = e->text[i].data[(int)((double)h
// 			/ h_t) * e->text[i].width + (int)(((double)w / w_t))];
// 	}
// 	if (img->texture_swap == 2)
// 		e->central->texture_swap = 1;
// 	img->texture_swap = (img->texture_swap == 2) ? 1 : 2;
// }
