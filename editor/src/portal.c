/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:58:42 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/13 14:49:29 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
**	check on sector if walls match with other sectors, then portal
*/

void	is_portal(t_env *e, t_ixy *to_check, int index)
{	
	if ((to_check->x == e->sector->dots->x
	&& to_check->y == e->sector->dots->y
	&& to_check->next->x == e->sector->dots->next->x
	&& to_check->next->y == e->sector->dots->next->y)
	|| (to_check->x == e->sector->dots->next->x
	&& to_check->y == e->sector->dots->next->y
	&& to_check->next->x == e->sector->dots->x
	&& to_check->next->y == e->sector->dots->y))
	{
		e->sector->dots->next_sector = index;
		e->sector->dots->color = PORTAL_COLOR;
	}
}

/*
**  compare with all others wall's portal
*/

void	compare_with_others(t_env *e, t_ixy *to_check, t_sector *sector)
{
	t_sector	*tmp_sector;
	t_ixy		*tmp_dots;

	tmp_sector = e->sector;
	while (e->sector)
	{
		if (sector->index == e->sector->index)
		{
			e->sector = e->sector->next;
			continue ;
		}
		tmp_dots = e->sector->dots;
		while (e->sector->dots && e->sector->dots->next)
		{
			is_portal(e, to_check, sector->index);
			e->sector->dots = e->sector->dots->next;
		}
		e->sector->dots = tmp_dots;
		e->sector = e->sector->next;
	}
	e->sector = tmp_sector;
}

/*
**  select portal & compare with others
*/

void	check_portals(t_env *e)
{
	t_sector	*sector;
	t_ixy		*dots;
	t_ixy		*to_check;

	sector = e->sector;
	while (sector)
	{
		dots = sector->dots;
		while (dots)
		{
			if (dots->next)
				to_check = dots;
			else
				break ;
			compare_with_others(e, to_check, sector);
			dots = dots->next;
		}
		dots = e->sector->dots;
		sector = sector->next;
	}
	sector = e->sector;
}
