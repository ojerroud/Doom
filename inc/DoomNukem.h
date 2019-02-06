/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoomNukem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:55:20 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/06 15:13:11 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOMNUKEN_H
# define DOOMNUKEN_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>

# define HEIGH 800
# define WEIGH 800

# define DASHES "--------------------"
# define MAP "map"
# define DESIGN_LEVEL "Design level"
# define TEXTURE "textures"
# define GAMEPLAY "gameplay"


# define ESC 53
# define W 13
# define D 2
# define A 0
# define S 1
# define SPACE 49

typedef enum	e_texture
{
	floor = 0,
	wall = 1,
	water = 2,
	house = 3,
	signboard = 4,
	barrier = 5,
	door = 6,
	bookcase = 7,
	tv = 8,
	tp = 9,
	chair = 10,
	table = 11,
	computer = 12,
	console = 13,
	bed = 14,
	plant = 15,
}				t_texture;

typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;


typedef struct		s_map
{
	char			*name;
	t_ixy			dimention;
	int				**map;
}					t_map;


typedef struct		s_mlx
{
    void			*mlx;
    void			*win;
}					t_mlx;

typedef struct		s_parse
{
	char			*title;
	int				begin_line;
	int				end_line;
	struct s_parse	*next;
}					t_parse;

typedef struct		s_env
{
    t_mlx			mlx;
	t_parse			*list;
    int				silent;
	int				is_title;
	char			*title;
	t_map			map;
}					t_env;

/*
**  error.c
*/

int     ft_error(char *str);

/*
**  init.c
*/

int     init_mlx(t_env *e);

/*
**  keyboard.c
*/

int     keyhooked(int keycode, t_env *e);
void    key_esc(t_env *e);

/*
**  reader.c
*/

void    read_file(t_env *e, char *file);
void	print_list(t_parse *list);

#endif
