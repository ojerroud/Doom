/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:02:59 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/18 10:45:19 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoomNukem.h"

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_error("mauvais nombre d'arguments.");
	ft_putendl(av[1]);
	read_file(&e, av[1]);
	init_mlx(&e, "init");
	return (0);
}
