/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:14:38 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/26 17:02:11 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static t_ixy	*lstnew2(int x, int y)
{
	t_ixy	*tmp;

	if (!(tmp = (t_ixy *)malloc(sizeof(t_ixy))))
		return (NULL);
	tmp->x = x;
	tmp->y = y;
	return (tmp);
}

void			add_img2(t_ixy *new, t_ixy **list)
{
	new->next = *list;
	*list = new;
}

void	        create_list_dots(t_ixy **list, int x, int y)
{
	t_ixy	*new;

	new = lstnew2(x, y);
	add_img2(new, list);
}

static t_img	*lstnew(int name, int width, int height)
{
	t_img	*tmp;

	if (!(tmp = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	tmp->name = name;
	tmp->width = width;
	tmp->height = height;
	return (tmp);
}

void			add_img(t_img *new, t_img **list)
{
	new->next = *list;
	*list = new;
}

void	        create_list_img(t_img **list, int name, int width, int height)
{
	t_img	*new;

	new = lstnew(name, width, height);
	add_img(new, list);
}