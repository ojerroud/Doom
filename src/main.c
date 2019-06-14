/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:02:59 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/13 15:27:38 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoomNukem.h"

void	init_var(t_env *e)
{
	e->character.x = 70;
	e->character.y = 70;

	e->map[0].x = 60;
	e->map[0].y = 20;

	e->map[1].x = 60;
	e->map[1].y = 320;

	e->map[2].x = 200;
	e->map[2].y = 340;

	e->map[3].x = 360;
	e->map[3].y = 360;

	e->map[4].x = 360;
	e->map[4].y = 260;
	
	e->map[5].x = 260;
	e->map[5].y = 220;

	e->map[6].x = 220;
	e->map[6].y = 80;

	e->map[7].x = 180;
	e->map[7].y = 20;

	e->map[8].x = 60;
	e->map[8].y = 20;

	e->ray.x = e->character.x + 20;
	e->ray.y = e->character.y + 0;
	e->dir.x = e->ray.x - e->character.x;
	e->dir.y = e->ray.y - e->character.y;
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		exit(0);
	e.texture = ft_strnew(ft_strlen(av[1]));
	e.texture = ft_strcpy(e.texture, av[1]);
	test(&e);
	// 	ft_error("mauvais nombre d'arguments.");
	ft_putendl(av[ac - 1]);
	// read_file(&e, av[1]);
	// init_vars(&e);
	// init_mlx(&e, "init");
	return (0);
}
