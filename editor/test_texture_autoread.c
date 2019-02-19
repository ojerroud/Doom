/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:46:23 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/19 17:52:59 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>

int		main(int ac, char **av)
{
	DIR				*rep;
	struct dirent	*ent;
	int				i;

	rep = opendir(av[1]);
	i = 0;
	if (rep)
	{
		while ((ent = readdir(rep)))
		{
			if (i >= 2)
				printf("|%s|\n", ent->d_name);
			i++;
		}
		closedir(rep);
	}
	return (0);
}
