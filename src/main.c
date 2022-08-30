#include "../inc/map.h"
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../inc/header.h"

#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

#include <math.h>

#define PI 3.14159

typedef struct s_vector
{
	double x;
	double y;

}t_vector;

typedef struct param
{
	double x;
	double y;

	t_vector dir;
	t_vector plane;
	t_vector *ray;
	t_window *win;
	t_window *win3d;
	t_map  *map;
}t_param;

void draw_ceil_floor(int *image)
{
	int ceil_color = 0xABD7EB;
	int floor_color = 0x808080;
	int image_size = 720 * 720;
	for (int i = 0; i < image_size; i++)
	{
		image[i] = (i < image_size /2 ) ? ceil_color : floor_color;
	}
}

double abs_(double x)
{
	return (x < 0 ? -x : x) ;
}

void	dda(int x1, int y1, int x2, int y2, t_window *img, int color)
{
	float	xsacle;
	float	ysacle;
	int	slop;
	float x, y;

	x= (float) x1;
	y= (float) y1;

	slop = abs_(x2 - x1);
	if (slop < abs_(y2 - y1))
		slop = abs_(y2 - y1);
	xsacle = (float) (x2 - x1) / slop;
	ysacle = (float)(y2 - y1) / slop;
	int array_x;
	while (slop--)
	{
		//mlx_pixel_put(img->mlx_ptr, img->mlx_win_ptr, x, y, color);
		array_x = img->win_width * (int)y + (int)x; 
		//printf("array_x : %d\n", array_x);
		if (slop % 2 && 0)
			img->mlx_win_image[array_x] = 0xFFFFFF;
		else
			img->mlx_win_image[array_x] = color;
		x+= xsacle;
		y+= ysacle;
	}
}

void __init_plane_dir(t_vector *plane,  t_vector *dir)
{
	dir->x = 0;
	dir->y = -1;
	plane->x = 1; 
	plane->y = 0;
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
	int	start;
	int	color;
	double	dist;

	color =  0x8c3f03;
	// Dark wall on Y ray collision 
	if (side)
		color = 0x572803;
	dist = p->win->win_higth / perp_dist;
	dist = dist > p->win->win_higth ? p->win->win_higth : dist;
	start = p->win->win_higth / 2 - dist / 2;
	start = start < 0 ? 0 : start;
	dda(pixel, start, pixel, start + dist, p->win, color);
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
		if (p->map->grid[gridy][gridx] == 1)
			break;
	}
	dist_ = (side == 1) ? (dist_x - delta->x) : (dist_y - delta->y);
	paint(pixel, side,  dist_, p);
}		

void cast_rays(t_param *p)
{
	t_vector	ray;
	t_vector	delta;
	int		pixel;
	double		magnitude;

	pixel = 0;
	p->ray = &ray;
	while (pixel <= p->win->win_width)
	{
		magnitude = 2 * (double)pixel / p->win->win_width -1;	
		ray.x = p->dir.x + p->plane.x * magnitude;
		ray.y = p->dir.y + p->plane.y * magnitude;
		delta.x = (ray.x == 0) ? 10e30 : abs_(1 / ray.x);
		delta.y = (ray.y == 0) ? 10e30 : abs_(1 / ray.y);
		find_wall(&delta, p, pixel);
		pixel++;
	}

}

int draw_walls(t_param *p)
{
	draw_ceil_floor(p->win->mlx_win_image);
	cast_rays(p);
	mlx_put_image_to_window(p->win->mlx_ptr, p->win->mlx_win_ptr, p->win->image, 0, 0);
	return (1);
}

bool rotate(int key, t_param *p)
{
	double r_speed = 0.24;
	if (key == RIGHT)
	{
		double tmp = p->dir.x;

		p->dir.x = p->dir.x * cos(r_speed) - p->dir.y * sin(r_speed);
		p->dir.y = tmp * sin(r_speed) + p->dir.y * cos(r_speed);
		tmp = p->plane.x;

		p->plane.x = p->plane.x * cos(r_speed) - p->plane.y * sin(r_speed);
		p->plane.y = tmp * sin(r_speed) + p->plane.y * cos(r_speed);
	}
	else if (key == LEFT)
	{
		double tmp = p->dir.x;

		p->dir.x = p->dir.x * cos(-r_speed) - p->dir.y * sin(-r_speed);
		p->dir.y = tmp * sin(-r_speed) + p->dir.y * cos(-r_speed);
		tmp = p->plane.x;

		p->plane.x = p->plane.x * cos(-r_speed) - p->plane.y * sin(-r_speed);
		p->plane.y = tmp * sin(-r_speed) + p->plane.y * cos(-r_speed);
	}
	else
		return (0);
	return (1);


}
bool side_move(int key, t_param *p)
{

	double m_speed = 0.34;
	if (key == KEY_A)
	{
		if (p->map->grid[(int)(p->y - p->plane.y  * m_speed)][(int)p->x] == 0)
			p->y -= p->plane.y * m_speed;
		if (p->map->grid[(int)p->y][(int)(p->x - p->plane.x * m_speed)] == 0)
			p->x -=  p->plane.x * m_speed;
	}
	else if (key == KEY_D)
	{
		if (p->map->grid[(int)(p->y + p->plane.y * m_speed)][(int)p->x] == 0)
			p->y += p->plane.y * m_speed;
		if (p->map->grid[(int)p->y][(int)(p->x + p->plane.x * m_speed)]== 0)
			p->x += p->plane.x * m_speed;
	}
	else
		return (0);
	return (1);


}
bool front_move(int key, t_param *p)
{
	double m_speed = 0.34;

	if (key == KEY_W)
	{
		if (p->map->grid[(int)(p->y + p->dir.y * m_speed)][(int)p->x] == 0)
			p->y += p->dir.y * m_speed;
		if (p->map->grid[(int)p->y][(int)(p->x + p->dir.x * m_speed)]== 0)
			p->x += p->dir.x * m_speed;
	}
	else if (key == KEY_S)
	{
		if (p->map->grid[(int)(p->y - p->dir.y  * m_speed)][(int)p->x] == 0)
			p->y -= p->dir.y * m_speed;
		if (p->map->grid[(int)p->y][(int)(p->x - p->dir.x * m_speed)] == 0)
			p->x -=  p->dir.x * m_speed;
	}
	else
		return (0);
	return (1);
}

int move(int key, void *param)
{
	t_param *p = (t_param *) param;

	if (side_move(key, p) || front_move(key, p) || rotate(key, p))
		draw_walls(p);
	return (1);

	//mlx_clear_window(p->win->mlx_ptr, p->win->mlx_win_ptr);
	//draw_ceil_floor(p->win->mlx_win_image);
	//mlx_put_image_to_window(p->win->mlx_ptr, p->win->mlx_win_ptr, p->win->image, 0, 0);
}

void __init_param(t_window *win, t_map *map, t_param *p)
{
	p->x = 22;
	p->y = 11;
	p->win = win;
	p->map = map;
	p->dir.x = 0;
	p->dir.y = -1;
	p->plane.x = 1; 
	p->plane.y = 0;
}


int main()
{
	t_map		map;
	t_window	win;
	t_param		p;

	__init_win(720, 720, &win);
	__init_map(&map);
	__init_param(&win, &map, &p);
	draw_walls(&p);
	mlx_hook(win.mlx_win_ptr, 2, 0L, move, &p);
	mlx_loop(win.mlx_ptr);

	//draw_ceil_floor(win.mlx_win_image);
	//mlx_put_image_to_window(win.mlx_ptr, win.mlx_win_ptr, win.image, 0, 0);
	//mlx_key_hook(win.mlx_win_ptr, move, &p);
	//mlx_loop_hook(win.mlx_ptr, draw_walls, &p);
	//mlx_do_key_autorepeaton(win.mlx_ptr);
}
