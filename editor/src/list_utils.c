/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:14:38 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/25 17:07:55 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_ixy	*lstnew2(int x, int y)
{
	t_ixy	*tmp;

	if (!(tmp = (t_ixy *)malloc(sizeof(t_ixy))))
		ft_error("malloc fail");
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}

void	add_img2(t_ixy *new, t_ixy **list)
{
	new->next = *list;
	*list = new;
}

void	sav_dots(t_ixy **list, int x, int y)
{
	t_ixy	*new;

	new = lstnew2(x, y);
	add_img2(new, list);
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

void	add_sector(t_sector **list, t_sector *new)
{
	new->next = *list;
	*list = new;
}

void	sav_sector(t_sector **list, int index)
{
	t_sector	*new;

	new = lstnew_sector(index);
	add_sector(list, new);
}



// void	select_sector(t_env *e, int x, int y)
// {
// 	t_sector	*port;
// 	t_ixy		*tmp;

// 	port = e->sector;
// 	tmp = e->dots;
// 	while (port)
// 	{
// 		if (port->index == e->index)
// 		{
// 			sav_dots(e->sector->dots, x, y);
// 			break ;
// 		}
// 		port = port->next;
// 	}
// }
