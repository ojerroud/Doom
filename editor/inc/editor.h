/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:55:20 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/26 17:10:39 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# define WIDTH	1800
# define HEIGHT	1000

# define ESC				53
# define W					13
# define D					2
# define A					0
# define S					1
# define C					8
# define R					15
# define G					5
# define LEFT				123
# define RIGHT				124
# define DOWN				125
# define UP					126
# define SPACE				49

# define MOUSE_LEFT			1
# define MOUSE_RIGHT		2
# define MOUSE_MID			3
# define MOUSE_SCROLLUP		4
# define MOUSE_SCROLLDOWN	5
# define BUTTON_W		WIDTH / 6
# define BUTTON_H		HEIGHT / 8

# define SPACING		1
# define GRID_SIZE		32
# define DOTS_COLOR		0xFF0000

# define WHITE			0xFFFFFF
# define BLACK			0x000000
# define RED			0xFF0000
# define GREEN			0x00FF00
# define BLUE			0x0000FF
# define GREY			0x666666
# define BALL1			"texture/1.xpm"
# define BALL2			"texture/2.xpm"

typedef enum		e_name
{
	MAIN,
	BUTTON1,
	BUTTON2,
	BUTTON3,
	BUTTON4,
	BUTTON5,
	BUTTON6,
	END,
	BUTTON7,
	BUTTON8,
	BUTTON9,
	BUTTON10,
	BUTTON11,
	BUTTON12,
	BUTTON13,
	BUTTON14,
	SQUARRE,
	SQUARRE2,
}					t_name;

typedef enum		e_texture
{
	POKEBALL1,
	POKEBALL2,
	LAST,
}					t_texture;

typedef struct		s_ixy
{
	int				x;
	int				y;
	struct s_ixy	*next;
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
	int				name;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				height;
	int				color;
	int				texture_swap;
	int				color_swap;
	t_ixy			pos;
	struct s_img	*next;
}					t_img;

typedef struct		s_text
{
	void			*img_ptr;
	char			*name;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				width;
	int				height;
}					t_text;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;
}					t_mlx;

typedef struct		s_env
{
	t_mlx			mlx;
	int				grid_size;
	t_ixy			*dots;
	char			*title;
	t_map			map;
	int				ac;
	char			**av;
	t_img			*select;
	t_img			*main;
	t_text			text[LAST];
	int				test;
}					t_env;

/*
**  error.c
*/

int					ft_error(char *str);

/*
**  init.c
*/

void 				init_mlx(t_env *e, char *title);
void				init_xy(t_img *list, t_env *e);
void				init_vars(t_env *e);

/*
**  keyboard.c
*/

int					keyhooked(int keycode, t_env *e);
void				key_esc(t_env *e);

/*
**  reader.c
*/

void				read_file(t_env *e, char *file);
void				print_list(t_img *list);

/*
**	mouse.c
*/

int					mousehooked(int button, int x, int y, t_env *e);

/*
**	draw.c
*/

void				points(t_env *e, char **av);
void				create_imgs(t_env *e);
void				put_img_pos(t_env *e);
void				img_paint(t_env *e, t_img *img);

/*
**	texure.c
*/

void				init_texture(t_env *e);
void				scale_texture_to_img(t_img *img, t_env *e);

/*
**	map.c
*/

void				put_grid(t_env *e);

/*
**	list_utils.c
*/

void				create_list_img(t_img **list, int name, int w, int h);
void				create_list_dots(t_ixy **list, int x, int y);

/*
**	dots.c
*/

void				sav_dots(t_env *e, int x, int y);

#endif
