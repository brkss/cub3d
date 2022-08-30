#include "../inc/map.h"
#include "../inc/header.h"
#include <stdio.h>

void __init_win(int heigth, int width, t_window *win)
{
	win->mlx_ptr = mlx_init();
	win->mlx_win_ptr = mlx_new_window(win->mlx_ptr, heigth, width, "HELLO");
	win->image = mlx_new_image(win->mlx_ptr, heigth , width );
	win->mlx_win_image = 
		(int *)mlx_get_data_addr(win->image, &win->bits_per_pixel, &win->size_line, &win->endian);
	win->win_width = width;
	win->win_higth = heigth;
}

void draw_grid(t_map *map, int *image)
{
	return ;
	//int tile_width = 30;
	int tile_width = 12;
	//int image_size = 720 * 720 ;
	int image_size = 288 * 288 ;
	int map_x;
	int map_y;
	int color =  0x00808080;

	(void)map;
	int c = 0;
	for (int row_pixel = 0; row_pixel < image_size; row_pixel++)
	{
		c = 0;
		if (row_pixel % tile_width == 0)
		{
			map_y = row_pixel / (tile_width * tile_width * (map->mapWidth ));
			map_x = (row_pixel / tile_width) % (map->mapWidth );
			map->grid[map_y][map_x] ? (color = 0x00FFFFFF): (color = 0x00808080);
			c = 1;
		}
		if (row_pixel % (tile_width * tile_width *(map->mapWidth ) ) == 0)
		{
			row_pixel += tile_width *(map->mapWidth) ;
			c= 1;
		}
		if (!c)
			image[row_pixel] = color;
	}
}
