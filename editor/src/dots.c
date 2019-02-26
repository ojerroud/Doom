/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 10:07:45 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/26 13:44:58 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	sav_dots(t_ixy *list, int x, int y)
{
	t_ixy	*tmp;
	// int		i;

	// i = -1;
	create_list_dots(&list, x, y);
	tmp = list;
	while (list)
	{
		// i++;
		list = list->next;
	}
// 	if (i)
// 		printf("ok. (%d)\n", i);
}