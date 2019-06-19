/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:38:48 by ojerroud          #+#    #+#             */
/*   Updated: 2019/06/18 14:02:36 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

// int		mouse(int keycode, int x, int y, t_env *e)
// {
// 	x += 0;
// 	y += 0;
// 	e->index +=0;
// 	keycode += 0;
// 	return (0);
// }

// int		key(int keycode, t_env *e)
// {
// 	if (keycode == ESC)
// 		exit(0);
// 	e->index +=0;
// 	return (0);
// }

// void	get_texture(t_env *e, t_text *texture, char *path)
// {
// 	texture->img_ptr = mlx_xpm_file_to_image(e->mlx.mlx, path, &texture->width, &texture->height);
// 	if (!(texture->img_ptr))
// 		ft_error("wrong texture");
// 	texture->data = (int *)mlx_get_data_addr(texture->img_ptr, &texture->bpp, &texture->size_l, &texture->endian);
// }

// t_sprite	*lstnew_sprite(t_env *e, char *name, char *path)
// {
// 	t_sprite	*sprite;

// 	if (!(sprite = (t_sprite *)malloc(sizeof(t_sprite))))
// 		ft_error("malloc fail");
// 	sprite->name = ft_strnew(ft_strlen(name));
// 	sprite->name = ft_strcpy(sprite->name, name);
// 	sprite->click = 0;
// 	sprite->pos.x = -1;
// 	sprite->pos.y = -1;
// 	get_texture(e, &sprite->texture, path);
// 	return (sprite);
// }

// void	create_sprites_img(t_env *e, t_sprite **list, char *name, char *path)
// {
// 	t_sprite	*new;

// 	new = lstnew_sprite(e, name, path);
// 	new->next = *list;
// 	*list = new;
// }

// void	get_sprites(t_env *e)
// {
// 	create_sprites_img(e, &e->sprite, "sasha", PATH_SASHA);
// 	create_sprites_img(e, &e->sprite, "misty", PATH_MISTY);
// }

// void	test(t_env *e)
// {
// 	t_sprite	*sprite;
// 	int			i;

// 	e->sprite = NULL;
// 	e->mlx.mlx = mlx_init();
// 	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "test");
// 	if (!e->mlx.win)
// 		ft_error("fail create a new window");
// 	get_sprites(e);
// 	sprite = e->sprite;
// 	i = 0;
// 	while (e->sprite)
// 	{
// 		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->sprite->texture.img_ptr, i, 0);
// 		i += e->sprite->texture.width + 1;
// 		printf("%d\n", i);
// 		e->sprite = e->sprite->next;
// 	}
// 	e->sprite = sprite;
// 	mlx_mouse_hook(e->mlx.win, mouse, e);
// 	mlx_key_hook(e->mlx.win, key, e);
// 	mlx_loop(e->mlx.mlx);
// }

int		main(int ac, char **av)
{
	t_env	e;

	e.av = av;
	e.ac = ac;
	// test(&e);
	init_vars(&e);
	init_mlx(&e, "editor");
	return (0);
}
