/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:02:59 by ojerroud          #+#    #+#             */
/*   Updated: 2019/05/14 17:39:04 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoomNukem.h"

void	init_vars(t_env *e)
{
	e->character.x = 70;
	e->character.y = 70;

	e->map[0].x = 60;
	e->map[0].y = 40;
	e->map[1].x = 60;
	e->map[1].y = 140;
	e->map[2].x = 160;
	e->map[2].y = 140;
	e->map[3].x = 160;
	e->map[3].y = 40;
	e->map[4].x = 60;
	e->map[4].y = 40;
	e->dir = 0;
	e->ray.x = e->character.x + 20;
	e->ray.y = e->character.y + 0;
}

int		main(int ac, char **av)
{
	t_env	e;

	ac += 0;
	// if (ac != 2)
	// 	ft_error("mauvais nombre d'arguments.");
	ft_putendl(av[1]);
	// read_file(&e, av[1]);
	init_vars(&e);
	init_mlx(&e, "init");
	return (0);
}
