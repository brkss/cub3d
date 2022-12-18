#include "../inc/header.h"

void	draw_ceil_floor(int *image, t_mapdata *data, t_param *p)
{
	int	ceil_color;
	int	half_win_size;
	int	floor_color;
	int	image_size;
	int	i;

	image_size = p->win->win_width * p->win->win_height;
	half_win_size = image_size / 2;
	ceil_color = create_trgb(1, data->ceilling_color[0],
			data->ceilling_color[1], data->ceilling_color[2]);
	floor_color = create_trgb(1, data->floor_color[0],
			data->floor_color[1], data->floor_color[2]);
	i = 0;
	while (i < image_size)
	{
		if (i < half_win_size)
			image[i] = ceil_color;
		else
			image[i] = floor_color;
		i++;
	}
}

void	paint(int window_x, int side, double perp_dist, t_param *p)
{
	double	wall_y;
	double	wall_x;
	int		start;
	int		i;
	int		textutre_id;

	textutre_id = get_texture_id(side, p);
	wall_x = get_wall_x(p, side, perp_dist);
	wall_x = wall_x * (double)p->textures[textutre_id]->tx_width;
	perp_dist = p->win->win_width / perp_dist;
	if (perp_dist > p->win->win_width)
		perp_dist = p->win->win_width;
	start = (double)(p->win->win_width - perp_dist) / 2;
	if (start < 0)
		start = 0;
	i = start;
	while (i < (start + perp_dist))
	{
		//printf("%f %f\n", wall_x, wall_y)
		wall_y = ((double)(i - start) / perp_dist)
			* (double)p->textures[textutre_id]->tx_height;
		p->win->mlx_win_image[i * p->win->win_width + window_x]
			= get_color_from_texture(p, textutre_id, wall_x, wall_y);
		i++;
	}
}
