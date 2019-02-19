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

void	init_texture(t_env *e)
{
	int	h;
	int	w;
	int i;

	i = -1;
	ft_strcpy(e->text[0].name, BALL1);
	ft_strcpy(e->text[1].name, BALL2);
	// e->text[1].name = BALL2;
	while (++i < LAST)
	{
		e->text[i].img_ptr = mlx_xpm_file_to_image(e->mlx.mlx, e->text[i].name, &h, &w);
		e->text[i].data = (int *)mlx_get_data_addr(e->text[i].img_ptr, &(e->text[i].bpp), &(e->text[i].size_l), &(e->text[i].endian));
	}
	// h = -1;
	// printf("%d %d\n", img->height, img->width);
	// while (++h < img->height)
	// {
	// 	w = -1;
	// 	while (++w < img->width)
	// 	{
	// 		// img->data[h * img->width + w] = 0xFFFFFF;
	// 	}
	// }
	// printf("%d %d\n", img->pos.x, img->pos.y);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->text[0].img_ptr, 65, HEIGHT - 65);
}