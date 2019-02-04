/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:20:37 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/04 14:20:38 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DoomNukem.h"

void    read_map(t_env *e, char *map)
{
    int     fd;
    char    *line;

    fd = open(map, O_RDONLY);
    while (get_next_line(fd, &line))
        ft_putendl(line);
}