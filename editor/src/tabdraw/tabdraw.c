/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabdraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:07:34 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/28 19:12:38 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void    istab_draw(t_img *img, t_env *e)
{
    if (img->name == END - 1)
    {
        if (img->texture_swap == 1)
        {
            put_grid(e);
        }
        else
        {
            setup_img_data(e, e->main);
            mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->main->img_ptr, e->main->pos.x, e->main->pos.y);
        }
    }
}