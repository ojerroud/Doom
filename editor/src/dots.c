/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:07:45 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/26 15:22:35 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	sav_dots(t_env *e, int x, int y)
{
	t_ixy	*list;
	// int		i;

	// i = -1;
	list = e->dots;
	create_list_dots(&list, x, y);
	while (list)
	{
		// i++;
		printf("post %d %d\n", list->x, list->y);
		list = list->next;
	}
// 	if (i)
// 		printf("ok. (%d)\n", i);
}
