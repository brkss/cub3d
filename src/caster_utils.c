#include "../inc/header.h"

void draw_ceil_floor(int *image, t_mapdata *data)
{
		//printf("access colors !\n");
		int ceil_color;
		int half_win_size;
		int floor_color;
		int image_size;

		image_size = 720 * 720;
		half_win_size = image_size / 2;
		ceil_color = create_trgb(1, data->ceilling_color[0], data->ceilling_color[1], data->ceilling_color[2]);
		floor_color = create_trgb(1, data->floor_color[0], data->floor_color[1], data->floor_color[2]);
		for (int i = 0; i < image_size; i++)
		{
			if (i  < half_win_size)
				image[i] = ceil_color;
			else 
				image[i] = floor_color;
		}
}

void get_dist_x_y(double *dist_x, double *dist_y, t_param *p, t_vector *delta, t_vector *step)
{
		int gridx;
		int gridy;

		gridx = (int)p->x;
		gridy = (int)p->y;
		if (p->ray->x < 0)
		{
				*dist_x = (p->x - gridx) * delta->x;
				step->x = -1;
		}
		else
		{
				*dist_x = (gridx + 1.0 - p->x) * delta->x;
				step->x = 1;
		}
		if (p->ray->y < 0)
		{
				*dist_y = (p->y - gridy) * delta->y;
				step->y = -1;
		}
		else
		{
				*dist_y = (gridy + 1.0 - p->y) * delta->y;
				step->y = 1;
		}
}

void paint(int pixel, int side, double perp_dist, t_param *p)
{
		double	dist;
		int	start;
		int	color;
		int i;

		color =  0x8c3f03;
		// Dark wall on Y ray collision 
		if (side)
				color = 0x572803;
		dist = p->win->win_higth / perp_dist;
		dist = dist > p->win->win_higth ? p->win->win_higth : dist;
		start = (double )(p->win->win_higth - dist) / 2;
		start = start < 0 ? 0 : start;
		i = start + dist;
		while (i >= start)
			p->win->mlx_win_image[i-- * p->win->win_width + pixel] = color;
}

void find_wall(t_vector *delta, t_param *p, int pixel)
{
		t_vector	step;
		int		gridx;
		int		gridy;
		int		side;
		double		dist_x;
		double		dist_y;
		double		dist_;

		gridx = (int)(p->x);
		gridy = (int)(p->y);

		get_dist_x_y(&dist_x, &dist_y, p, delta, &step);
		while (42)
		{
				if (dist_x < dist_y)
				{
						dist_x += delta->x;
						gridx += (int)step.x;
						side = 1;
				}
				else
				{
						dist_y += delta->y;
						gridy += (int)step.y;
						side = 0;
				}
				if (p->map[gridy][gridx] == '1')
						break;
		}
		dist_ = (side == 1) ? (dist_x - delta->x) : (dist_y - delta->y); // correct fish eye effect
		paint(pixel, side,  dist_, p);
}		

void cast_rays(t_param *p)
{
		t_vector	ray;
		t_vector	delta;
		double		magnitude;
		int			pixel;

		pixel = 0;
		p->ray = &ray;
		//For every vertical stripe on screen
		while (pixel <= p->win->win_width)
		{
				magnitude = (double) pixel * 2 / p->win->win_width -1;	
				ray.x = p->dir.x + p->plane.x * magnitude;
				ray.y = p->dir.y + p->plane.y * magnitude;
				delta.x = (ray.x == 0) ? 10e30 : abs_(1 / ray.x);
				delta.y = (ray.y == 0) ? 10e30 : abs_(1 / ray.y);
				find_wall(&delta, p, pixel);
				pixel++;
		}
}

void ray_caster(t_param *p)
{
		draw_ceil_floor(p->win->mlx_win_image, p->data);
		cast_rays(p);
		mlx_put_image_to_window(p->win->mlx_ptr, p->win->mlx_win_ptr, p->win->image, 0, 0);
}
