/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:14:38 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/22 14:18:30 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	    lstadd(t_img **alst, t_img *new)
{
	new->next = *alst;
	*alst = new;
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

void	        create_list_img(t_img **list, int name, int width, int height)
{
	t_img	*new;

	new = lstnew(name, width, height);
	lstadd(list, new);
}