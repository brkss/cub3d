/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:39:57 by bberkass          #+#    #+#             */
/*   Updated: 2022/12/16 17:40:21 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"
#include "../inc/map.h"

t_texture	*set_texture(void *mlx_ptr, char *path)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->image = mlx_xpm_file_to_image(mlx_ptr, path,
			&texture->tx_width, &texture->tx_height);
	if (!texture->image)
	{
		free(texture);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->image,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	return (texture);
}

int	get_color_from_texture(t_param *p, int tex_id, int x, int y)
{
	int		pixel_size;
	int		img_line_length;
	char	*color;

	img_line_length = p->textures[tex_id]->line_length;
	pixel_size = p->textures[tex_id]->bits_per_pixel / 8;
	color = (char *)p->textures[tex_id]->addr
		+ (y * img_line_length + x * pixel_size);
	return (*(int *)color);
}

int	get_texture_id(int side, t_param *p)
{
	if (side == 0 && p->ray->y > 0)
		return (3);
	if (side == 0 && p->ray->y < 0)
		return (2);
	if (side == 1 && p->ray->x < 0)
		return (1);
	if (side == 1 && p->ray->x > 0)
		return (0);
	return (-1);
}
