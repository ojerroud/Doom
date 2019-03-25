/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:26:32 by ojerroud          #+#    #+#             */
/*   Updated: 2019/03/25 14:22:31 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_ixy	*mew(int x, int y)
{
	t_ixy	*new;

	new = malloc(sizeof(t_ixy));
	new->x = x;
	new->y = y;
	return (new);
}

void	add(t_ixy **list, t_ixy	*new)
{
	new->next = *list;
	*list = new;
}

void	merge(t_env *e, int x, int y)
{
	t_ixy	*new;

	new = mew(x, y);
	add(&e->dots, new);
}

void	t(t_env *e, int i)
{
	e->dots = NULL;
	merge(e, 1+i, 1+i);
	merge(e, 2+i, 2+i);
	merge(e, 3+i, 3+i);
	merge(e, 4+i, 4+i);

}

void	print_(t_env *e)
{
	t_ixy		*tmp;

	tmp = e->dots;
	while (tmp)
	{
		printf("%d %d\n" ,tmp->x, tmp->y);
		tmp = tmp->next;
	}
}

void	print2_(t_env *e)
{
	t_portal	*port;
	t_ixy		*tmp;

	port = e->portal;
	while (port)
	{
		printf("index : %d\n", port->index);
		tmp = port->dots;
		while (tmp)
		{
			printf("%d %d\n", tmp->x, tmp->y);
			tmp = tmp->next;
		}
		port = port->next;
	}
}

// void	merge2(t_env *e)
// {

// }


t_portal *mewtwo(t_ixy *dots, int index)
{
	t_portal	*new;

	new = malloc(sizeof(t_portal));
	new->index = index;
	new->dots = dots;
	return (new);
}

void	addtwo(t_portal **list, t_portal *new)
{
	new->next = *list;
	*list = new;
}

void	t2(t_env *e)
{
	t_portal	*new;

	e->portal = NULL;
	t(e, 0);
	new = mewtwo(e->dots, 0);
	addtwo(&e->portal, new);
	t(e, 1);
	new = mewtwo(e->dots, 1);
	addtwo(&e->portal, new);
	t(e, 2);
	new = mewtwo(e->dots, 2);
	addtwo(&e->portal, new);
	t(e, 3);
	new = mewtwo(e->dots, 3);
	addtwo(&e->portal, new);
}

int main(int ac, char **av)
{
	t_env		e;
	
	t2(&e);
	print2_(&e);
	return (0);
}