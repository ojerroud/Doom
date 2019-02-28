/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:14:38 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/28 17:20:58 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_ixy	*lstnew2(int x, int y)
{
	t_ixy	*tmp;

	if (!(tmp = (t_ixy *)malloc(sizeof(t_ixy))))
		return (NULL);
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
