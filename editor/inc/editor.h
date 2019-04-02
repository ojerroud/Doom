/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:55:20 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/02 17:56:44 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# define WIDTH	1000
# define HEIGHT	1000

/*
**	a mettre dans un typedef /!\
*/

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
# define BUTTON_W			(WIDTH / 6)
# define BUTTON_H			(HEIGHT / 8)

# define SPACING			1
# define GRID_SIZE			((WIDTH + HEIGHT) / 2 / 50)
# define DOTS_COLOR			0xFF0000

# define WHITE				0xFFFFFF
# define BLACK				0x000000
# define RED				0xFF0000
# define GREEN				0x00FF00
# define BLUE				0x0000FF
# define GREY				0x666666
# define GREY2				0x222222
# define BALL1				"texture/1.xpm"
# define BALL2				"texture/2.xpm"

#define FILENAME_SIZE		200
#define FILENAME_SIZE_W		200
#define FILENAME_SIZE_H		20

typedef enum		e_name
{
	CENTRAL,
	WRITE,
	SAV,
	BUTTON1,
	BUTTON2,
	BUTTON3,
	BUTTON4,
	END,
	BUTTON5,
	BUTTON6,
	BUTTON7,
	BUTTON8,
	BUTTON9,
	BUTTON10,
	BUTTON11,
	BUTTON12,
	BUTTON13,
	BUTTON14,
}					t_name;

// typedef enum		e_keycode
// {
// 	A = 0,
// 	B = 11,
// 	C = 8,
// 	D = 2,
// 	E = 14,
// 	F = 3,
// 	G = 5,
// 	H = 4,
// 	I = 34,
// 	J = 38,
// 	K = 40,
// 	L = 37,
// 	M = 46,
// 	N = 45,
// 	O = 31,
// 	P = 35,
// 	Q = 12,
// 	R = 15,
// 	S = 1,
// 	T = 17,
// 	U = 32,
// 	V = 9,
// 	W = 13,
// 	X = 7,
// 	Y = 16,
// 	Z = 6,
// 	DEL = 51,
// 	PREMIER = A,
// 	DERNIER = DEL,
// }					t_keycode;

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
	int				color;
	int				is_sector;
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
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	t_img			*img;
}					t_mlx;

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

typedef struct		s_sector
{
	t_ixy			*dots;
	int				index;
	struct s_sector	*next;
}					t_sector;

typedef struct 		s_file
{
	char			file_name[FILENAME_SIZE_W + 1];
	char			validate[FILENAME_SIZE_W + 1];
	t_ixy			pos;
}					t_file;


/*
**	t_map			map;
**	int				ac;
**	char			**av;
*/

typedef struct		s_env
{
	t_mlx			mlx;
	int				ac;
	char			**av;
	char			*file_name;
	int				silent;
	int				grid_size;
	char			*title;
	int				index;
	t_var			var;
	t_ixy			*dots;
	t_sector		*sector;
	t_img			*select;
	t_file			sav_button;
	t_file			write_zone;
	// t_img			*curr;
	t_img			*central;
	t_text			text[LAST];
}					t_env;

/*
**	draw.c
*/

void				sav_area(t_img *central, t_env *e);
void				put_grid(t_env *e);
void				draw_point(t_img *img, int x, int y);
void				draw_shape(t_img *img);
void				select_dots(t_img *img, t_env *e, int x, int y);

/*
**	error.c
*/

int					ft_error(char *str);

/*
**	keyboard.c
*/

void				key_esc(t_env *e);
void				sizegrid_change(t_env *e);
int					keyhooked(int keycode, t_env *e);
void				print_sector(t_env *e);

/*
**	list_utils.c
*/

t_ixy				*lstnew2(int x, int y);
void				add_img2(t_ixy *new, t_ixy **list);
void				sav_dots(t_ixy **list, int x, int y);
t_sector			*lstnew_sector(int index);
void				add_sector(t_sector **list, t_sector *new);
void				sav_sector(t_sector **list, int index);

/*
**	texture.c
*/

void				scale_texture_to_buttons(t_img *img, t_env *e);
// void				scale_texture_to_img(t_img *img, t_env *e);
void				appli_buttons_text(t_img *list, t_env *e);

/*
**	mouse.c
*/

void				left_click(t_env *e, int x, int y);
void				right_click(t_env *e);
int					mousehooked(int button, int x, int y, t_env *e);

/*
**	utils.c
*/

void				print_click(int button, int x, int y);
void				draw_ligne(t_ixy *dots1, t_ixy *dots2, t_env *e);
void				ligne2(t_ixy *dots1, t_ixy *dots2, t_env *e);
void				points(t_env *e, char **av);
void				print_list(t_img *list);

/*
**	init_img.c
*/

void				load_buttons_texture(t_env *e);
void				setup_img_data(t_env *e, t_img *img);
void				create_mlx_img(t_env *e, t_img *img);
void				sav_img_pos(t_env *e);

/*
**	init.c
*/

void				img_param(t_img *img, int x, int y, int color);
void				init_xy(t_img *list, t_env *e);
void				init_vars(t_env *e);
void				init_mlx(t_env *e, char *title);

/*
**	imgs.c
*/

void				paint_if_img(t_img *img, int x, int y, t_env *e);
t_img				*lstnew(int name, int width, int height);
void				create_list_img(t_img **list, int name
, int width, int height);
void				create_imgs(t_env *e);

/*
**	tabdraw.c
*/

void				istab_draw(t_img *img, t_env *e);

/*
**	portal.c
*/

void				is_portal(t_env *e, t_ixy *to_check);
void				compare_with_others(t_env *e, t_ixy *to_check
, t_sector *sector);
void				check_portals(t_env *e);

/*
**	central.c
*/

void    			delete_all_sectors(t_env *e);

/*
**	sav_map.c
*/

// void        		put_sav_values(t_env *e);

#endif
