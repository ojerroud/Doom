/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:14:38 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/22 14:14:07 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_ixy	*lstnew2(t_env *e, int x, int y)
{
	t_ixy	*tmp;

	if (!(tmp = (t_ixy *)malloc(sizeof(t_ixy))))
		return (NULL);
	tmp->x = x;
	tmp->y = y;
	tmp->index = e->index;
	return (tmp);
}

void	add_img2(t_ixy *new, t_ixy **list)
{
	new->next = *list;
	*list = new;
}

void	sav_dots(t_env *e, t_ixy **list, int x, int y)
{
	t_ixy	*new;

	new = lstnew2(e, x, y);
	add_img2(new, list);
}
