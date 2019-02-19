/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:55:20 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/19 12:04:44 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# define WIDTH	1500
# define HEIGHT	1000

# define ESC		53
# define W			13
# define D			2
# define A			0
# define S			1
# define C			8
# define LEFT		123
# define RIGHT		124
# define DOWN		125
# define UP			126
# define SPACE		49
# define BUTTON_W	WIDTH / 6 
# define BUTTON_H	HEIGHT / 5

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

typedef enum		e_name
{
	MAIN,
	SQUARRE,
	BUTTON1,
	BUTTON2,
	BUTTON3,
	BUTTON4,
	BUTTON5,
	BUTTON6,
	BUTTON7,
	BUTTON8,
	BUTTON9,
	BUTTON10,
	END,
}					t_name;

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
	int				color_swap;
	t_ixy			pos;
	struct s_img	*next;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;
}					t_mlx;

typedef struct		s_env
{
	t_mlx			mlx;
	int				silent;
	int				is_title;
	char			*title;
	t_map			map;
	char			**av;
	int				ac;
	t_img			*select;
}					t_env;

/*
**  error.c
*/

int					ft_error(char *str);

/*
**  init.c
*/

int					init_mlx(t_env *e, char *title);

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

#endif
