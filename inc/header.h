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
		int	win_height;

}t_window;

typedef struct s_texture
{
		int tx_height;
		int tx_width;
		void *image;
		void *addr;
		int bits_per_pixel;
		int line_length;
		int endian;

} t_texture;

#ifndef MAP_H
#include "../inc/map.h"
#endif

typedef struct param
{
		t_texture **textures;

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
void __inits(t_window *win, t_param *p);
void __init_textures(t_param *p, t_mapdata *data);
void __init_win(t_window *win);
void	__init_player_dir(t_param *p);

/*------------------- CasterUtils -------------------------*/

void ray_caster(t_param *p);
void cast_rays(t_param *p);
void draw_ceil_floor(int *image, t_mapdata *data, t_param *p);
void find_wall(t_vector *delta, t_param *p, int pixel);
//void get_dist_x_y(double *dist_x, double *dist_y, t_param *p, t_vector *delta, t_vector *step);
void	get_dist_x_y(double *dist_x_y, t_param *p, t_vector *delta, t_vector *step);
double	get_wall_x(t_param *p, int side, double perp_dist);

void exit_log(char const *err);


/*------------------- Main -------------------------*/
double abs_(double x);

/*------------------- Other-------------------------*/
int	create_trgb(int t, int r, int g, int b);


/*------------------- Image-------------------------*/
t_texture *set_texture(void *mlx_ptr, char *path);
int	get_color_from_texture(t_param *p, int tex_id, int x, int y);
int	get_texture_id(int side, t_param *p);

/*------------------- Draw-------------------------*/
void	paint(int window_x, int side, double perp_dist, t_param *p);
void	draw_ceil_floor(int *image, t_mapdata *data, t_param *p);

/*------------------- DDA-------------------------*/
double	dda_(int gridx, int gridy, t_param *p, t_vector *delta);



#endif
