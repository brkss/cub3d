/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:54:37 by adriouic          #+#    #+#             */
/*   Updated: 2022/12/19 22:31:05 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	__init_param(t_window *win, t_param *p)
{
	p->win = win;
	p->map = p->data->map;
	__init_player_dir(p);
	p->x = p->data->player_x + 0.5;
	p->y = p->data->player_y + 0.51;
}

void	__init_textures(t_param *p, t_mapdata *data)
{
	p->textures = malloc(sizeof(t_texture *) * 4);
	p->textures[0] = set_texture(p->win->mlx_ptr, data->north_tx);
	p->textures[1] = set_texture(p->win->mlx_ptr, data->south_tx);
	p->textures[2] = set_texture(p->win->mlx_ptr, data->east_tx);
	p->textures[3] = set_texture(p->win->mlx_ptr, data->west_tx);
	if (!(p->textures[0] && p->textures[1]
			&& p->textures[2] && p->textures[3]))
		exit_log("Textures Not Found !");
}

void	__init_win(t_window *win)
{
	win->win_width = 820;
	win->win_height = 820;
	win->mlx_ptr = mlx_init();
	win->mlx_win_ptr = mlx_new_window(win->mlx_ptr,
			win->win_width, win->win_height, "BasicRayCaster");
	win->image = mlx_new_image(win->mlx_ptr,
			win->win_width, win->win_height);
	win->mlx_win_image = (int *)mlx_get_data_addr(win->image,
			&win->bits_per_pixel, &win->size_line, &win->endian);
}

void	__inits(t_window *win, t_param *p)
{
	__init_win(win);
	__init_param(win, p);
}

void	__init_plane_dir(t_vector *plane, t_vector *dir)
{
	dir->x = 0;
	dir->y = -1;
	plane->x = 1;
	plane->y = 0;
}
