/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:38:48 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/21 16:53:46 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	t(t_env *e)
{
	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, 400, 400, "t");
	e->mlx.img_ptr = mlx_new_image(e->mlx.mlx, 400, 400);
	e->mlx.data = (int *)mlx_get_data_addr(e->mlx.img_ptr, &e->mlx.bpp, &e->mlx.size_l, &e->mlx.endian);
	ligne(40,40,300,300, e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img_ptr, 0 ,0);
	mlx_loop(e->mlx.mlx);
}

int	main(int ac, char **av)
{
	t_env	e;

	// e.av = av;
	// e.ac = ac;
	if (av)
		ac += 0;
	// t(&e);
	init_vars(&e);
	init_mlx(&e, "editor");
	return (0);
}
