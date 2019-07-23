/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:42:05 by ojerroud          #+#    #+#             */
/*   Updated: 2019/07/01 13:21:03 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	write_params(t_env *e)
{
	t_sector	*sector;
	t_ixy		*dots;

	ft_putstr_fd("Walls (", e->fd);
	ft_putnbr_fd(e->sector->index, e->fd);
	ft_putstr_fd(" entries) : \n==========\n", e->fd);
	sector = e->sector->next;
	while (sector)
	{
		dots = sector->dots;
		ft_putstr_fd("sector : ", e->fd);
		ft_putnbr_fd(sector->index, e->fd);
		ft_putstr_fd("\n", e->fd);
		while (dots && dots->next)
		{
			ft_putstr_fd("[(", e->fd);
			ft_putnbr_fd(dots->x, e->fd);
			ft_putstr_fd(",", e->fd);
			ft_putnbr_fd(dots->y, e->fd);
			ft_putstr_fd(");(", e->fd);
			ft_putnbr_fd(dots->next->x, e->fd);
			ft_putstr_fd(",", e->fd);
			ft_putnbr_fd(dots->next->y, e->fd);
			ft_putstr_fd(")], nextsector = ", e->fd);
			ft_putnbr_fd(dots->next_sector, e->fd);
			ft_putchar_fd('\n', e->fd);
			dots = dots->next;
		}
		dots = sector->dots;
		sector = sector->next;
	}
	// ft_putstr_fd("==========\nPORTAILS\n==========\n", e->fd);
	// sector = e->sector->next;
	// while (sector)
	// {
	// 	dots = sector->dots;
	// 	while (dots && dots->next)
	// 	{
	// 		if (dots->next_sector == 1)
	// 		{
	// 			ft_putstr_fd("[(", e->fd);
	// 			ft_putnbr_fd(dots->x, e->fd);
	// 			ft_putstr_fd(",", e->fd);
	// 			ft_putnbr_fd(dots->y, e->fd);
	// 			ft_putstr_fd(");(", e->fd);
	// 			ft_putnbr_fd(dots->next->x, e->fd);
	// 			ft_putstr_fd(",", e->fd);
	// 			ft_putnbr_fd(dots->next->y, e->fd);
	// 			ft_putstr_fd(")]\n", e->fd);
	// 		}
	// 		dots = dots->next;
	// 	}
	// 	dots = sector->dots;
	// 	sector = sector->next;
	// }
	sector = e->sector;
}

void	create_file(t_env *e)
{
	char	str[31];

	ft_bzero(str, 31);
	ft_strcpy(str, "maps/");
	ft_strcat(str, e->write_zone.str);
	ft_strcat(str,".doom");
	e->fd = open(str, O_CREAT | O_WRONLY | O_TRUNC, S_IWUSR | S_IRUSR);

}

// static void	t(t_env *e)
// {
// 	t_sector	*sector;
// 	t_ixy		*dots;

// 	sector = e->sector;
// 	while (sector)
// 	{
// 		dots = sector->dots;
// 		while (dots)
// 		{
// 			printf("(%d %d) : %d\n", dots->x, dots->y, dots->next_sector);
// 			dots = dots->next;
// 		}
// 		dots = e->sector->dots;
// 		sector = sector->next;
// 	}
// 	sector = e->sector;
// }

void	put_data_on_file(t_env *e)
{
	// t(e);
	create_file(e);
	// print_sector(e);
	write_params(e);
	ft_bzero(e->write_zone.str, ft_strlen(e->write_zone.str));
	// close(e->fd);
}

void	sprite_build(t_env *e, t_sprite *sprite, int x, int y)
{
	e->index +=0;
	if (!sprite->islist || (sprite->pos->x == -1 && sprite->pos->y == -1))
	{
		sprite->pos->x = x;
		sprite->pos->y = y;
	}
	else
		add_sprite_pos(&sprite->pos, x, y);
	if (sprite->pos->x != -1 && sprite->pos->y != -1)
	{
		put_texture_transparency(e, e->central, sprite);
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->central->img_ptr, e->central->pos.x, e->central->pos.y);
	}
}

/*
**	check if click is on the img, then draw
*/

void	paint_if_img(t_img *img, int x, int y, t_env *e)
{
	t_sprite	*sprite;
	char		*str;
	

	if (img->pos.x <= x && (img->pos.x + img->width) >= x
	&& img->pos.y <= y && (img->pos.y + img->height) >= y)
	{
		str = ft_strnew(5);
		if (img->name == SASHA)
			str = ft_strcpy(str, "sasha");
		if (img->name == MISTY)
			str = ft_strcpy(str, "misty");
		if (img->name == FINISH)
			str = ft_strcpy(str, "finish");
		// if (img->name == TIM)
		// 	str = ft_strcpy(str, "tim");
		sprite = e->sprite;
		while (e->sprite)
		{
			if (e->sprite->click == 1 && img->name == CENTRAL && e->select->name == END - 1)
			{
				sprite_build(e, e->sprite, x - e->central->pos.x, y - e->central->pos.y);
				e->sprite = sprite;
				ft_strdel(&str);
				return ;
			}
			e->sprite->click = (img->name > SPRITES && img->name < BUTTON1 
			&& e->select->name == END -1 && !ft_strcmp(e->sprite->name, str))
			? 1 : 0;
			e->sprite = e->sprite->next;
		}
		ft_strdel(&str);
		e->sprite = sprite;
		if (e->sector->next && ft_strlen(e->write_zone.str) && img->name == SAV)
			put_data_on_file(e);
		if (img->name == WRITE || img->name == SAV)
			e->sav_zone_bool = 1;
		if (img->name >= BUTTON1 && img->name < END)
		{
			e->select = img;
			scale_texture_to_buttons(img, e);
			istab_draw(img, e);
		}
		if (img->name == CENTRAL && e->select->name == END - 1
		&& img->texture_swap && !e->sav_zone_bool)
			select_dots(img, e, x, y);
		// mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, img->img_ptr
		// , img->pos.x, img->pos.y);
	}
}

t_img	*lstnew(int name, int width, int height)
{
	t_img	*tmp;

	if (!(tmp = (t_img *)malloc(sizeof(t_img))))
		ft_error("malloc fail");
	tmp->name = name;
	tmp->width = width;
	tmp->height = height;
	return (tmp);
}

void	create_list_img(t_img **list, int name, int width, int height)
{
	t_img	*new;

	new = lstnew(name, width, height);
	new->next = *list;
	*list = new;
}

void	create_imgs(t_env *e)
{
	int		i;

	create_list_img(&e->mlx.lst_img, CENTRAL, WIDTH - 2 * BUTTON_W, HEIGHT);
	i = SPRITES;
	while (++i < BUTTON1)
	{
		create_list_img(&e->mlx.lst_sprite, i, 64, 64);
	}
	create_list_img(&e->mlx.lst_img, WRITE, FILENAME_SIZE_W, FILENAME_SIZE_H);
	create_list_img(&e->mlx.lst_img, SAV, FILENAME_SIZE_W, FILENAME_SIZE_H);
	i = BUTTON1 - 1;
	while (++i < END)
	{
		create_list_img(&e->mlx.lst_img, i, BUTTON_W - SPACING, BUTTON_H - SPACING);
	}
	init_xy(e->mlx.lst_img, e);
	init_xy(e->mlx.lst_sprite, e);
	sav_img_pos(e, e->mlx.lst_img);
	sav_img_pos(e, e->mlx.lst_sprite);
	e->select = e->mlx.lst_img;
}
