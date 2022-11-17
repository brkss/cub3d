#ifndef MAP_H
#define MAP_H

#include "./libft.h"

# define WEST_TEXTURE 1
# define EAST_TEXTURE 2
# define SOUTH_TEXTURE 3
# define NORTH_TEXTURE 4
# define FLOOR_COLOR 5
# define CEILLING_COLOR 6
# define EMPTY_LINE -1

typedef struct s_map
{
	int mapHigth;
	int mapWidth;
	int grid[24][24];
}t_map;

typedef struct s_mapdata
{
  int *ceilling_color;
  int *floor_color;
  char *north_tx;
  char *west_tx;
  char *east_tx;
  char *south_tx;
  int mapH;
  int mapW;
  char **map;
}t_mapdata;

void __init_map(t_map *map);
void draw_grid(t_map *map, int *image);

int check_args(int ac, char **av);
char *get_next_line(int fd);
t_list *read_map(char *filename);
//char **read_map(char *filename);
//char *get_texture(char **map, char *texture_id);
//char *get_color(char **map, char id);
int check_extension(char *filename);
t_mapdata *scan_scene(t_list *head);
char **convert_map(t_list *map_chain); 
int check_map(char **map);
#endif
