#include "../inc/header.h"

void __init_param(t_window *win, t_param *p)
{
		p->win = win;
		p->map = p->data->map;
		p->dir.x = 0;
		p->dir.y = -1;
		p->plane.x = 0.66; 
		p->plane.y = 0;

		// this need to be generic
		p->x = 22;
		p->y = 11;
}

void __init_win(int heigth, int width, t_window *win)
{
		win->mlx_ptr = mlx_init();
		win->mlx_win_ptr = mlx_new_window(win->mlx_ptr, heigth, width, "BasicRayCaster");
		win->image = mlx_new_image(win->mlx_ptr, heigth , width );
		win->mlx_win_image = 
				(int *)mlx_get_data_addr(win->image, &win->bits_per_pixel, &win->size_line, &win->endian);
		win->win_width = width;
		win->win_higth = heigth;
}

void __inits(t_window *win, t_param *p)
{
		__init_win(720, 720, win);
		__init_param(win, p);
}

void __init_plane_dir(t_vector *plane,  t_vector *dir)
{
		dir->x = 0;
		dir->y = -1;
		plane->x = 1; 
		plane->y = 0;
}

