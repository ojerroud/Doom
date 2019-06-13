/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:14:38 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/13 13:57:20 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_ixy		*lstnew_dots(int x, int y)
{
	t_ixy	*tmp;

	if (!(tmp = (t_ixy *)malloc(sizeof(t_ixy))))
		ft_error("malloc fail");
	tmp->x = x;
	tmp->y = y;
	tmp->next_sector = -1;
	tmp->color = DOTS_COLOR;
	return (tmp);
}

void		sav_dots(t_ixy **list, int x, int y)
{
	t_ixy	*new;

	new = lstnew_dots(x, y);
	new->next = *list;
	*list = new;
}

t_sector	*lstnew_sector(int index)
{
	t_sector *tmp;

	if (!(tmp = (t_sector *)malloc(sizeof(t_sector))))
		ft_error("malloc fail");
	tmp->dots = NULL;
	tmp->index = index;
	return (tmp);
}

void		sav_sector(t_sector **list, int index)
{
	t_sector	*new;

	new = lstnew_sector(index);
	new->next = *list;
	*list = new;
}

// t_wall		*lstnew_wall(t_ixy a, t_ixy b)
// {
// 	t_wall	*tmp;

// 	if (!(tmp = (t_wall *)malloc(sizeof(t_wall))))
// 		ft_error("malloc fail");
// 	tmp->a = a;
// 	tmp->b = b;
// 	return (tmp);
// }

// void		sav_walls(t_wall **list, t_ixy a, t_ixy b)
// {
// 	t_wall	*new;
// 	new = lstnew_wall(a, b);
// 	new->next = *list;
// 	*list = new;
// }

t_portal	*lstnew_wall(t_ixy a, t_ixy b)
{
	t_portal	*tmp;

	if (!(tmp = (t_portal *)malloc(sizeof(t_portal))))
		ft_error("malloc fail");
	// tmp.a = a;
	a.color+=0;
	b.color+=0; 
	// tmp.b = b;
	return (tmp);
}

void		sav_walls(t_portal **list, t_ixy a, t_ixy b)
{
	t_portal	*new;
	new = lstnew_wall(a, b);
	new->next = *list;
	*list = new;
}