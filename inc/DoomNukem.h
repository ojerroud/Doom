/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoomNukem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:55:20 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/01 11:55:22 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOMNUKEN_H
# define DOOMNUKEN_H

# include "libft.h"
# include <mlx.h>

# define HEIGH 800
# define WEIGH 800
# define ESC 53
# define W 13
# define D 2
# define A 0
# define S 1
# define SPACE 49


typedef struct  s_mlx
{
    void        *mlx;
    void        *win;
}               t_mlx;

typedef struct  s_env
{
    t_mlx       mlx;
}               t_env;

/*
**  error.c
*/

int     ft_error(char *str);

/*
**  init.c
*/

int     init_mlx(t_env *e);

/*
**  keybord.c
*/

int     keyhooked(int keycode, t_env *e);
void    key_esc(t_env *e);

#endif
