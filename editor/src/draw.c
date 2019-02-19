/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:00:35 by ojerroud          #+#    #+#             */
/*   Updated: 2019/02/19 12:05:19 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void    ligne(int xi,int yi,int xf,int yf, t_env *e)
{
	int dx,dy,i,xinc,yinc,cumul,x,y;
	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y , 0xFFFFFF);
	if (dx > dy)
	{
		cumul = dx / 2;
		i = 0;
		while (++i <= dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y , 0xFFFFFF);
		}
	}
	else
	{
		cumul = dy / 2;
		i = 0;
		while (++i <= dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y , 0xFFFFFF);
		}
	}
}

void    points(t_env *e, char **av)
{
	ligne(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), e);
}

void	change_color(t_img *img)
{
	int	h;
	int	w;

	h = -1;
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
		{
			if (img->name == MAIN)
				img->data[h * img->width + w] = img->color;
			if (img->name == SQUARRE)
				img->data[h * img->width + w] = img->color;
			if (img->name >= BUTTON1)
				img->data[h * img->width + w] = img->color;
		}
	}
}

void	draw_shape(t_img	*img)
{
	int	h;
	int	w;

	h = -1;
	while (++h < img->height)
	{
		w = -1;
		while (++w < img->width)
		{
			if (!h || h == img->height - 1 || !w || w == img->width - 1)
			img->data[h * img->width + w] = 0x000000;
		}
	}
}

void	create_mlx_img(t_env *e, t_img *img)
{
	img->img_ptr = mlx_new_image(e->mlx.mlx, img->width, img->height);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->size_l), &(img->endian));
	change_color(img);
	// draw_shape(img);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, img->img_ptr, img->pos.x, img->pos.y);
} 

void	put_img_pos(t_env	*e)
{
	t_img	*tmp;

	tmp = e->mlx.img;
	mlx_clear_window(e->mlx.mlx, e->mlx.win);
	while (tmp)
	{
		if (tmp->name == MAIN || tmp->name == SQUARRE || (tmp->name >= BUTTON1 && tmp->name < END))
			create_mlx_img(e, tmp);
		tmp = tmp->next;
	}
}

void	print_list(t_img *list)
{
	t_img	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("|%d| %d %d\n", tmp->name, tmp->width, tmp->height);
		tmp = tmp->next;
	}
}

void	add_(t_img **alst, t_img *new)
{
	new->next = *alst;
	*alst = new;
}

t_img	*create_(int name, int width, int height)
{
	t_img   *tmp;

	if(!(tmp = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	tmp->name = name;
	tmp->width = width;
	tmp->height = height;
	return (tmp);
}

void	create_list_img(t_img **list, int name, int width, int height)
{
	t_img	*new;

	new = create_(name, width, height);
	add_(list, new);
}

void	init_xy(t_img	*list)
{
	t_img	*tmp;
	int		cpt_w;
	int		cpt_h;

	tmp = list;
	cpt_w = 0;
	cpt_h = 0;
	while (tmp)
	{
		if (tmp->name == MAIN)
		{
			tmp->pos.x = WIDTH - tmp->width;
			tmp->pos.y = HEIGHT - tmp->height;
			tmp->color = 0x222222;
		}
		if (tmp->name == SQUARRE)
		{
			tmp->pos.x = 10;
			tmp->pos.y = 10;
			tmp->color = 0x666666;
		}
		if (tmp->name >= BUTTON1)
		{
			tmp->pos.x = 0 + (BUTTON_W * cpt_w);
			tmp->pos.y = 0 + (BUTTON_H * cpt_h);
			tmp->color = 0xFFFFFF;
			if (cpt_w)
				cpt_h ++;
			cpt_w = !cpt_w;
		}
		tmp->color_swap = 1;
		printf("%d %d %d || %d %d\n", tmp->name, tmp->pos.x, tmp->pos.y, tmp->width, tmp->height);
		tmp = tmp->next;
	}
}

void	create_imgs(t_env *e)
{
	e->mlx.img = NULL;
	create_list_img(&e->mlx.img, MAIN, 2 * WIDTH / 3 - 1, HEIGHT - 1);
	create_list_img(&e->mlx.img, BUTTON1, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON2, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON3, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON4, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON5, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON6, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON7, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON8, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON9, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, BUTTON10, BUTTON_W - 1, BUTTON_H - 1);
	create_list_img(&e->mlx.img, SQUARRE, 64, 64);
	init_xy(e->mlx.img);
	put_img_pos(e);
	// print_list(e->mlx.img);
}