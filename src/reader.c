// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   reader.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/02/04 14:20:37 by ojerroud          #+#    #+#             */
// /*   Updated: 2019/02/13 11:17:22 by ojerroud         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "DoomNukem.h"
// #include <stdio.h>

// void	print_list(t_parse *list)
// {
// 	while (list)
// 	{
// 		printf("|%s| %d %d\n", list->title, list->begin_line, list->end_line);
// 		list = list->next;
// 	}
// }

// void	add_end(t_parse *list, int line_nb)
// {
// 	t_parse		*tmp;

// 	tmp = list;
// 	line_nb += 4;
// 	while (tmp)
// 	{
// 		tmp->end_line = line_nb - 4;
// 		line_nb = tmp->begin_line;
// 		tmp = tmp->next;
// 	}
// }

// void	add(t_parse **alst, t_parse *new)
// {
// 	new->next = *alst;
// 	*alst = new;
// }

// t_parse	*create(char *content, int begin, int end)
// {
// 	t_parse	*tmp;

// 	if (!(tmp = (t_parse *)malloc(sizeof(t_parse)))
// 			|| !(tmp->title = (char *)malloc(sizeof(char))))
// 		return (NULL);
// 	if (content)
// 		ft_strcpy(tmp->title, content);
// 	tmp->begin_line = begin;
// 	tmp->end_line = end;
// 	return (tmp);
// }

// void	create_and_add(t_parse **list, char *content, int begin)
// {
// 	t_parse		*new;

// 	new = create(content, begin, 0);
// 	add(list, new);
// 	ft_strclr(content);
// }

// void	check_section(char *line, int line_nb, t_env *e)
// {
// 	int			diff;
// 	char		*to_find;

// 	to_find = DASHES;
// 	diff = ft_strcmp(line, to_find);
// 	if (e->is_title == 2)
// 	{
// 		e->is_title = 0;
// 		if (!diff)
// 			create_and_add(&(e->list), e->title, line_nb + 1);
// 		return ;
// 	}
// 	if (e->is_title == 1)
// 	{
// 		e->is_title++;
// 		ft_strdel(&(e->title));
// 		e->title = ft_strnew(ft_strlen(line));
// 		ft_strcpy(e->title, line);
// 	}
// 	if (!diff && !(e->is_title))
// 		e->is_title++;
// 	line_nb += 0;
// }

// void	save_maps(char *line, int line_nb, t_env *e)
// {
// 	char		*to_find;

// 	to_find = MAP;
// 	if (ft_strstr(line, to_find))
// 	{
// 		printf("|%s| %d\n", ft_strstr(line, to_find), line_nb);
// 	}
// 	e->silent += 0;
// }

// void	read_file(t_env *e, char *map)
// {
// 	int		fd;
// 	int		line_nb;
// 	char	*line;

// 	e->list = NULL;
// 	e->title = ft_strnew(0);
// 	e->is_title = 0;
// 	line_nb = 1;
// 	fd = open(map, O_RDONLY);
// 	while (get_next_line(fd, &line))
// 	{
// 		check_section(line, line_nb, e);
// 		save_maps(line, line_nb, e);
// 		ft_strdel(&line);
// 		line_nb++;
// 	}
// 	add_end(e->list, line_nb);
// }

// void	read_map(void)
// {
// }
