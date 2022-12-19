#include "../inc/header.h"

void	get_dist_x_y(double *dist_x_y, t_param *p,
					t_vector *delta, t_vector *step)
{
	int	gridx;
	int	gridy;

	gridx = (int)p->x;
	gridy = (int)p->y;
	if (p->ray->x < 0)
	{
		dist_x_y[0] = (p->x - gridx) * delta->x;
		step->x = -1;
	}
	else
	{
		dist_x_y[0] = (gridx + 1.0 - p->x) * delta->x;
		step->x = 1;
	}
	if (p->ray->y < 0)
	{
		dist_x_y[1] = (p->y - gridy) * delta->y;
		step->y = -1;
	}
	else
	{
		dist_x_y[1] = (gridy + 1.0 - p->y) * delta->y;
		step->y = 1;
	}
}

double	get_wall_x(t_param *p, int side, double perp_dist)
{
	double	wall_x;

	if (!side)
		wall_x = (double) p->x + perp_dist * (double)p->ray->x;
	else
		wall_x = (double) p->y + perp_dist * (double)p->ray->y;
	wall_x = wall_x - (int)wall_x;
	return (wall_x);
}
void	find_wall(t_vector *delta, t_param *p, int pixel) { int			side;
	double		dist_;

	side = 0;
	dist_ = dda_((int)p->x, (int)p->y, p, delta);
	if (dist_ < 0)
	{
		side = 1;
		dist_ = dist_ * -1;
	}
	//if (dist_ == 0)
	//	dist_ = 1.1;
	paint(pixel, side, dist_, p);
}

void	cast_rays(t_param *p)
{
	t_vector	ray;
	t_vector	delta;
	double		magnitude;
	int			pixel;

	pixel = 0;
	p->ray = &ray;
	while (pixel <= p->win->win_width)
	{
		magnitude = (double) pixel * 2 / p->win->win_width -1;
		ray.x = p->dir.x + p->plane.x * magnitude;
		ray.y = p->dir.y + p->plane.y * magnitude;
		if (ray.x == 0)
			delta.x = 10e30;
		else
			delta.x = abs_(1 / ray.x);
		if (ray.y == 0)
			delta.y = 10e30;
		else
			delta.y = abs_(1 / ray.y);
		find_wall(&delta, p, pixel);
		pixel++;
	}
}

void	ray_caster(t_param *p)
{
	draw_ceil_floor(p->win->mlx_win_image, p->data, p);
	cast_rays(p);
	mlx_put_image_to_window(p->win->mlx_ptr,
		p->win->mlx_win_ptr, p->win->image, 0, 0);
}
