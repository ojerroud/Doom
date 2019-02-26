/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:07:45 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/26 17:05:10 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	sav_dots(t_env *e, int x, int y)
{
	// t_ixy	*list;
	// int		i;

	// i = -1;
	// list = dots;
	create_list_dots(&e->dots, x, y);
	while (e->dots)
	{
		// i++;
		printf("post %d %d ", e->dots->x, e->dots->y);
		e->dots = e->dots->next;
	}
	e->test++;
	printf("\n");
// 	if (i)
// 		printf("ok. (%d)\n", i);
}
