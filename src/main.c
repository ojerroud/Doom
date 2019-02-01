/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:02:59 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/01 13:12:20 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoomNukem.h"

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_error("mauvais nombre d'arguments.");
	init_mlx(&e);
	ft_putendl(av[1]);
	return (0);
}
