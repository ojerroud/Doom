/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:42:05 by ojerroud          #+#    #+#             */
/*   Updated: 2019/04/03 17:28:34 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	write_params(t_env *e)
{
	t_sector	*sector;
	// t_ixy		*dots;

	sector = e->sector->next;
	// printf("%d\n", e->fd);
	// ft_putstr_fd("sectors : ", e->fd);
	// ft_putnbr_fd(e->sector->index, e->fd);
	// ft_putchar_fd('\n', e->fd);
	// e->sector = e->sector->next;
	while (sector)
	{
		// while (sector->dots && sector->dots->next)
		// {
			printf("%d\n", sector->index);
		// 	sector->dots = sector->dots->next;
		// }
		sector = sector->next;
	}
	e->sector = sector;
}

void	create_file(t_env *e)
{
	char	str[FILENAME_SIZE_W + 1 + 5];

	ft_bzero(str, ft_strlen(str));
	ft_strcpy(str, "maps/");
	ft_strcat(str, e->write_zone.str);
	ft_strcat(str,".doom");
	e->fd = open(str, O_CREAT | O_WRONLY | O_APPEND, S_IWUSR | S_IRUSR);
	// printf("%d\n", e->fd);
	if (e->fd == -1)
		printf("error!\n");
}

void	put_data_on_file(t_env *e)
{
	// ft_putstr("file ");
	// ft_putstr(e->write_zone.str);
	// ft_putendl(" done!!");
	create_file(e);
	write_params(e);
	// ft_bzero(e->write_zone.str, ft_strlen(e->write_zone.str));
	// close(e->fd);
}

/*
**	check if click is on the img, then draw
*/

void	paint_if_img(t_img *img, int x, int y, t_env *e)
{
	if (img->pos.x <= x && (img->pos.x + img->width) >= x
	&& img->pos.y <= y && (img->pos.y + img->height) >= y)
	{
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
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, img->img_ptr
		, img->pos.x, img->pos.y);
	}
	
}

t_img	*lstnew(int name, int width, int height)
{
	t_img	*tmp;

	if (!(tmp = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
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

	create_list_img(&e->mlx.img, CENTRAL, 2 * WIDTH
	/ 3, HEIGHT);
	create_list_img(&e->mlx.img, WRITE, FILENAME_SIZE_W, FILENAME_SIZE_H);
	create_list_img(&e->mlx.img, SAV, FILENAME_SIZE_W, FILENAME_SIZE_H);
	i = BUTTON1 - 1;
	while (++i < END)
	{
		create_list_img(&e->mlx.img, i, BUTTON_W - SPACING, BUTTON_H - SPACING);
	}
	init_xy(e->mlx.img, e);
	sav_img_pos(e);
	e->select = e->mlx.img;
}
