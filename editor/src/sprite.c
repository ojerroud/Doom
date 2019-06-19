/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:59:09 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/19 17:58:25 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	get_texture(t_env *e, t_text *texture, char *path)
{
	texture->img_ptr = mlx_xpm_file_to_image(e->mlx.mlx, path, &texture->width, &texture->height);
	if (!(texture->img_ptr))
		ft_error("wrong texture");
	texture->data = (int *)mlx_get_data_addr(texture->img_ptr, &texture->bpp, &texture->size_l, &texture->endian);
}

void	init_txy(t_sprite *sprite)
{
	sprite->pos->x = 0;
	sprite->pos->y = 0;

}

t_dxy	*lstnew_xy(int x, int y)
{
	t_dxy	*new;

	if (!(new = (t_dxy *)malloc(sizeof(t_dxy))))
		ft_error("malloc fail");
	new->x = x;
	new->y = y;
	return (new);
}

void	add_sprite_pos(t_dxy **list, int x ,int y)
{
	t_dxy	*new;

	new = lstnew_xy(x ,y);
	new->next = *list;
	*list = new;
}

t_sprite	*lstnew_sprite(t_env *e, char *name, char *path)
{
	t_sprite	*sprite;

	if (!(sprite = (t_sprite *)malloc(sizeof(t_sprite))))
		ft_error("malloc fail");
	sprite->name = ft_strnew(ft_strlen(name));
	sprite->name = ft_strcpy(sprite->name, name);
	sprite->click = 0;
	sprite->islist = (!ft_strcmp(sprite->name, "sasha") || !ft_strcmp(sprite->name, "finish") || !ft_strcmp(sprite->name, "tim")) ? 0 : 1;
	sprite->pos = NULL;
	add_sprite_pos(&sprite->pos, -1, -1);
	get_texture(e, &sprite->texture, path);
	return (sprite);
}

void	create_sprites_img(t_env *e, t_sprite **list, char *name, char *path)
{
	t_sprite	*new;

	new = lstnew_sprite(e, name, path);
	new->next = *list;
	*list = new;
}

void    get_sprites(t_env *e)
{
	create_sprites_img(e, &e->sprite, "finish", PATH_FINISH);
	create_sprites_img(e, &e->sprite, "misty", PATH_MISTY);
    create_sprites_img(e, &e->sprite, "sasha", PATH_SASHA);
    create_sprites_img(e, &e->sprite, "tim", PATH_TIM);
}