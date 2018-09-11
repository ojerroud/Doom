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

void    check_map(t_env *e, int fd)
{
    char    *line;
    char    **tmp;
    int     i;
    int     j;
    int     ret;

    // printf("%d\n", e->map.height);
    i = -1;
    while ((ret =get_next_line(fd, &line)) > 0)
    {
        (++i >= e->map.height) ? error("wrong number of lines.") : 0;
        e->map.map[i] = (int *)malloc(sizeof(int) * (unsigned long)(e->map.width));
        tmp = ft_strsplit(line, ' ');
        ft_strdel(&line);
        j = -1;
        while (tmp[++j])
        {
            e->map.map[i][j] = (ft_atoi(tmp[j])) ? 1 : 0;
            (j >= e->map.width) ? error("wrong number of columns.") : 0;
            ft_strdel(&tmp[j]);
        }
        (j != e->map.width) ? error("wrong map width.") : 0;
		free(tmp);
    }
    (i + 1 != e->map.height) ? error("wrong map height.") : 0;
	(ret == -1) ? error("gnl") : 0;
}

void    check_files_params(t_env *e, int fd)
{
    char    *line;
    char    **str;
    int     i;

    if (get_next_line(fd, &line) <= 0)
        error("File empty");
    str = ft_strsplit(line, ' ');
    ft_strdel(&line);
    e->map.width = ft_atoi(str[0]);
    e->map.height = ft_atoi(str[1]);
    e->player.pos.x = ft_atoi(str[2]);
    e->player.pos.y = ft_atoi(str[3]);
    i = -1;
    while (++i < 4)
        ft_strdel(&str[i]);
    free(str);
    e->map.map = (int **)malloc(sizeof(int *) * e->map.height);
}

void    read_file(t_env *e, int fd)
{
    check_files_params(e, fd);
    check_map(e, fd);

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