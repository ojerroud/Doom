/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:13:11 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/06 14:16:03 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoomNukem.h"
#include <stdio.h>

void    add(t_parse **alst, t_parse *new)
{
    new->next = *alst;
    *alst = new;
}

t_parse *create(char *content, int begin, int end)
{
    t_parse *tmp;

    if (!(tmp = (t_parse *)malloc(sizeof(t_parse)))
    || !(tmp->title = (char *)malloc(sizeof(char))))
    {
        return (NULL);
    }
    if (content)
    {
        ft_memcpy(tmp->title, content, ft_strlen(content));
    }
    tmp->begin_line = begin;
    tmp->end_line = end;
    return (tmp);
}

void a(t_env *e)
{
    t_parse     *new;
    int         i;

    e->list = NULL;
    new = create("test1", 1, 1);
    add(&(e->list), new);
    new = create("test2", 2, 2);
    add(&(e->list), new);
    new = create("test3", 3, 3);
    add(&(e->list), new);
    new = create("test4", 4, 4);
    add(&(e->list), new);
    i = -1;
    while (e->list)
    {
        printf("%s %d %d\n", e->list->title, e->list->begin_line, e->list->end_line);
        e->list = e->list->next;
    }
}

int main(int ac, char **av)
{
    t_env e;

    a(&e);
    return (0);
}
