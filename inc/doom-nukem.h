/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom-nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 12:02:22 by ojerroud          #+#    #+#             */
/*   Updated: 2018/09/10 12:02:53 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

# include <stdlib.h>
# include "../libft/inc/libft.h"
# include "mlx.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct	s_ixy
{
	int	        y;
	int	        x;
}				t_ixy;

typedef struct	s_dxy
{
	float		x;
	float		y;
}				t_dxy;

typedef struct	s_map
{
	int         params[4];
    int         **map;
}				t_map;

typedef struct  s_mlx
{
    void        *mlx;
    void        *win;
    void        *img;
}               t_mlx;

typedef struct  s_env
{
    t_mlx       mlx;
    t_map       map;
    char        *input;
    int         a;
}               t_env;

int     key_hook(int keycode, int a);
void    read_param(t_env *e, char *input_map);
void    error(char *message);

#endif
