#include "../inc/header.h"

void draw_ceil_floor(int *image, t_mapdata *data, t_param *p)
{
		//printf("access colors !\n");
		int ceil_color;
		int half_win_size;
		int floor_color;
		int image_size;

		image_size = p->win->win_width * p->win->win_height;
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

double get_wall_x(t_param *p, int side, double perp_dist)
{
	double wall_x;
	
	if (!side) // wall hit N or S
		wall_x = (double ) p->x + (double )perp_dist * (double)p->ray->x;
	else 
		wall_x = (double ) p->y + (double )perp_dist * (double)p->ray->y;
	wall_x = wall_x - (int)wall_x; // flooring value (since 0 <= wall_x <= 1)
	return (wall_x);
}

int get_color_from_texture(t_param *p, int tex_id, int x, int y)
{
	int pixel_size;
	int img_line_length;

	img_line_length = p->textures[tex_id]->line_length;
	pixel_size = p->textures[tex_id]->bits_per_pixel / 8; // 8 is size of one byte
	char *color = (char *)p->textures[tex_id]->addr + (y * img_line_length + x * pixel_size);
	return (*(int *)color);

}

int get_texture_id(int side, t_param *p)
{
	if (side == 0 && p->ray->y > 0) //South
		return (3);
	if (side == 0 && p->ray->y < 0) //North
		return (2); 
	if (side == 1 && p->ray->x < 0) // East 
			return (1);
	if (side == 1 && p->ray->x > 0) // West
		return (0);// west
	else
	{
		write(2, "NEWS error", 10);
		exit(1);
		return (-1);
	}
}

void paint(int window_x, int side, double perp_dist, t_param *p)
{
		double	dist;
		int	start;
		int	color;
		int i;
		double wall_y;
		int line_hight;
		int textutre_id = get_texture_id(side, p);
		
		double wall_x = get_wall_x(p, side, perp_dist);
		wall_x = wall_x * (double)p->textures[textutre_id]->tx_width;
		dist = p->win->win_width / perp_dist;
		dist = dist > p->win->win_width ? p->win->win_width : dist;
		start = (double )(p->win->win_width - dist) / 2;
		start = start < 0 ? 0 : start;
		line_hight = start + dist;
		i = start;
		int j = 0;
		while (i < line_hight)
		{
			wall_y = ((double )j / (double)dist) * (double)p->textures[textutre_id]->tx_height;
			color = get_color_from_texture(p, textutre_id, wall_x, wall_y);
			p->win->mlx_win_image[i * p->win->win_width + window_x] = color;
			i++;
			j++;
		}
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
		draw_ceil_floor(p->win->mlx_win_image, p->data, p);
		cast_rays(p);
		mlx_put_image_to_window(p->win->mlx_ptr, p->win->mlx_win_ptr, p->win->image, 0, 0);
}
