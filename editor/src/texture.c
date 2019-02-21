/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:30:13 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/19 19:07:15 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void    scale_texture_to_img(t_img *img, t_env *e)
{
    int     w;
    int     h;
    double  w_t;
    double  h_t;

    h = -1;
    w_t = (double)img->width / 64.0;
    h_t = (double)img->height / 64.0;
    while (++h < img->height)
    {
        w = -1;
        while (++w < img->width)
        {
            if (img->texture_swap == 0 || img->texture_swap == 2)
                img->data[h * img->width + w] = e->text[0].data[(int)((double)h / h_t) * 64 + (int)(((double)w / w_t))];
            else
                img->data[h * img->width + w] = e->text[1].data[(int)((double)h / h_t) * 64 + (int)(((double)w / w_t))];
        }
    }
    img->texture_swap = (img->texture_swap == 0 || img->texture_swap == 2) ? 1 : 2;
}

void	init_texture(t_env *e)
{
	int	h;
	int	w;
	int i;

	i = -1;
	e->text[0].name = (char *)malloc(sizeof(char) * (ft_strlen(BALL1) + 1));
	e->text[1].name = (char *)malloc(sizeof(char) * (ft_strlen(BALL2) + 1));
	ft_strcpy(e->text[0].name, BALL1);
	ft_strcpy(e->text[1].name, BALL2);
	while (++i < LAST)
	{
		e->text[i].img_ptr = mlx_xpm_file_to_image(e->mlx.mlx, e->text[i].name, &h, &w);
		e->text[i].data = (int *)mlx_get_data_addr(e->text[i].img_ptr, &(e->text[i].bpp), &(e->text[i].size_l), &(e->text[i].endian));
	}
}