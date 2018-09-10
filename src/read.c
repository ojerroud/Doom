/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:06:58 by ojerroud          #+#    #+#             */
/*   Updated: 2018/09/10 16:06:59 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"
#include <stdio.h>

void     check_fil_s_params(t_env *e, int fd)
{
    char    *line;
    char    **str;
    int     i;

    if (get_next_line(fd, &line) <= 0)
        error("File empty");
    str = ft_strsplit(line, ' ');
    ft_strdel(&line);
    i = -1;
    while (++i < 4)
    {
        // printf("i = %d\n", i);
        e->map.params[i] = ft_atoi(str[i]);
        ft_strdel(&str[i]);
    }
    free(str);
    i = -1;
    while (++i < 4)
    {
        ft_putnbr(e->map.params[i]);
        ft_putchar('\n');
    }
}
void    read_file(t_env *e, int fd)
{
    char    *line;

    check_fil_s_params(e, fd);
    while (get_next_line(fd, &line) > 0)
    {
        ft_putchar('|');
        ft_putstr(line);
        ft_putendl("|");
    }
    e->a = 0;
}

void    read_param(t_env *e, char *input_map)
{
    int fd;

    e->input = input_map;
    if ((fd = open(e->input, O_RDONLY)) == -1)
        error("Could'nt open file!");
    read_file(e, fd);
    if (close(fd) == -1)
        error("Coundn't close FileDescriptor!");
}