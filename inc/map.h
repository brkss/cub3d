#ifndef MAP_H
#define MAP_H

typedef struct s_map
{
	int mapHigth;
	int mapWidth;
	int grid[24][24];
}t_map;

typedef struct s_mapdata
{
  int ceilling_color[3];
  int floor_color[3];
  char *north_tx;
  char *west_tx;
  char *east_tx;
  char *south_tx;
  int mapH;
  int mapW;
}t_mapdata;

void __init_map(t_map *map);
void draw_grid(t_map *map, int *image);

int check_args(int ac, char **av);
char *get_next_line(int fd);
char **read_map(char *filename);
char *get_texture(char **map, char *texture_id);
#endif
