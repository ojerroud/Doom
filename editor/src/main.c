/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:38:48 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/18 09:42:08 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_env   e;
	int		i;

	e.av = av;
	e.ac = ac;
	i = -1;
	init_mlx(&e, "editor");
	return (0);
}
