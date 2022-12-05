#ifndef HEADER_H
#define HEADER_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

#include "../inc/header.h"
#include "../inc/map.h"
#include "../libft/libft.h"

#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2


typedef struct s_vector
{
		double x;
		double y;
}t_vector;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	void	*image;
	int 	*mlx_win_image;
	
	int  bits_per_pixel;	//	pointer to where the bpp is written;
	int  size_line	;	//	pointer to where the line is written;
	int  endian;
	int	win_width;
	int	win_higth;

}t_window;

typedef struct s_texture {

  int height;
  int width;
  void *image;
  void *addr;
  int bits_per_pixel;
  int line_length;
  int endien;

} t_texture;

#ifndef MAP_H
#include "../inc/map.h"
#endif

typedef struct param
{
		t_texture *north_tx;
    t_texture *south_tx;
    t_texture *east_tx;
    t_texture *west_tx;

    double x;
		double y;
		char   	**map;

		t_vector dir;
		t_vector plane;
		t_vector *ray;
		t_window *win;
		t_window *win3d;
		t_mapdata *data;  

}t_param;


/*------------------- moves -------------------------*/

int  move(int key, void *param);
bool front_move(int key, t_param *p);
bool side_move(int key, t_param *p);
bool rotate(int key, t_param *p);

/*------------------- initers -------------------------*/
void __init_param(t_window *win, t_param *p);
void __init_plane_dir(t_vector *plane,  t_vector *dir);
void __init_win(int heigth, int width, t_window *win);
void __inits(t_window *win, t_param *p);
void __init_textures(t_param *p, t_mapdata *data);
/*------------------- CasterUtils -------------------------*/
void ray_caster(t_param *p);
void cast_rays(t_param *p);
void draw_ceil_floor(int *image, t_mapdata *data);
void find_wall(t_vector *delta, t_param *p, int pixel);
void get_dist_x_y(double *dist_x, double *dist_y, t_param *p, t_vector *delta, t_vector *step);


void __init_win(int heigth, int width, t_window *win);
void exit_log(char const *err);

/*------------------- Main -------------------------*/
double abs_(double x);
void draw_ceil_floor(int *image, t_mapdata *data);

/*------------------- Other-------------------------*/
int	create_trgb(int t, int r, int g, int b);



t_texture *set_texture(void *mlx_ptr, char *path);

#endif
