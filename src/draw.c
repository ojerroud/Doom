/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:27:08 by ojerroud          #+#    #+#             */
/*   Updated: 2018/09/11 13:27:09 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom-nukem.h"

void    print_map(t_map map, t_player player)
{
    int i;
    int j;

    i = -1;
    printf("%d %d \n", map.width, map.height, player.width, player.height);
    while (++i < map.params[1])
    {
        j = -1;
        while (++j < map.params[0])
            printf("%d ", map.map[i][j]);
        printf("\n");
    }
}