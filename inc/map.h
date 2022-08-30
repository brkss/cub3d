#ifndef MAP_H
#define MAP_H

typedef struct s_map
{
	int mapHigth;
	int mapWidth;
	int grid[24][24];

}t_map;

void __init_map(t_map *map);
void draw_grid(t_map *map, int *image);

#endif
