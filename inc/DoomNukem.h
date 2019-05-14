/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoomNukem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:55:20 by ojerroud          #+#    #+#             */
/*   Updated: 2019/05/14 17:36:32 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOMNUKEN_H
# define DOOMNUKEN_H

# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

# define HEIGHT 600
# define WIDTH 800

# define DASHES "--------------------"
# define MAP "map"
# define DESIGN_LEVEL "Design level"
# define TEXTURE "textures"
# define GAMEPLAY "gameplay"


# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define ESC 53
# define ESC 53
# define ESC 53
# define W 13
# define D 2
# define A 0
# define S 1
# define SPACE 49

typedef enum	e_texture
{
	floors = 0,
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

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	char			*name;
	int				width;
	int				height;
	// struct s_img	*next;
}					t_img;

typedef struct		s_var
{
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
	int				swap;
}					t_var;

typedef struct		s_mlx
{
    void			*mlx;
    void			*win;
	t_img			img;
}					t_mlx;

// typedef struct		s_parse
// {
// 	char			*title;
// 	int				begin_line;
// 	int				end_line;
// 	struct s_parse	*next;
// }					t_parse;

typedef struct		s_env
{
    t_mlx			mlx;
	int				is_title;
	char			*title;
	t_var			var;
	t_ixy			map[5];
	t_ixy			character;
	t_ixy			ray;
	int				dir;
}					t_env;

/*
**  error.c
*/

int     ft_error(char *str);

/*
**  init.c
*/

void	color_img(t_env *e);
void	map(t_env *e);
int     init_mlx(t_env *e, char *title);

/*
**  keyboard.c
*/

int     keyhooked(int keycode, t_env *e);
int     mouvment(int keycode, t_env *e);
void    key_esc(t_env *e);

/*
**  reader.c
*/

void    read_file(t_env *e, char *file);
// void	print_list(t_parse *list);

/*
**	mouse.c
*/

int		mousehooked(int button, int x, int y, t_env *e);

/*
**	draw.c
*/

void    points(t_env *e, char **av);
void	draw_imgs(t_env *e);

#endif
