/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   central.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:44:58 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/14 11:43:35 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	reset_spawn(t_env *e)
{
	e->spawn.compteur = 0;
	e->spawn.pos.x = -1;
	e->spawn.pos.y = -1;
}

void	delete_all_sectors(t_env *e)
{
	t_sector	*sector;
	t_ixy		*dots;

	while (e->sector)
	{
		sector = e->sector->next;
		while (e->sector->dots)
		{
			dots = e->sector->dots->next;
			free(e->sector->dots);
			e->sector->dots = dots;
		}
		free(e->sector);
		e->sector = sector;
	}
	reset_spawn(e);
	e->index = 0;
	sav_sector(&e->sector, e->index);
	if (e->select->name == END - 1)
		put_grid(e);
	// else if (e->select->name == END - 2)
	// {
	// 	setup_img_data(e, e->central);
	// 	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win,
	// 	e->central->img_ptr, e->central->pos.x, e->central->pos.y);
	// 	// put_sav_values(e);
	// }
	// else
	// {
	// 	setup_img_data(e, e->central);
	// 	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win,
	// 	e->central->img_ptr, e->central->pos.x, e->central->pos.y);
	// }
}
