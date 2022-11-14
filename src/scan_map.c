
#include "../inc/map.h"

char *get_texture(char *line)
{

}

int is_testure(char *line)
{
  if(line && ft_strlen(line) >= 2 && line[0] == 'N' && line[1] == 'O')
    return NORTH_TEXTURE;
  if(line && ft_strlen(line) >= 2 && line[0] == 'S' && line[1] == 'O')
    return  SOUTH_TEXTURE;
  if(line && ft_strlen(line) >= 2 && line[0] == 'W' && line[1] == 'E')
    return WEST_TEXTURE;
  if(line && ft_strlen(line) >= 2 && line[0] == 'E' && line[1] == 'A')
    return EAST_TEXTURE;
  if(line && ft_strlen(line) >= 1 && line[0] == 'F')
    return FLOOR_COLOR;
  if(line && ft_strlen(line) >= 1 && line[0] == 'C')
    return CEILLING_COLOR;
  return (0);
}

void __init_mapdata(t_mapdata *data)
{
  data->ceilling_color = NULL;
  data->floor_color = NULL;
  data->north_tx = NULL;
  data->west_tx = NULL;
  data->south_tx = NULL;
  data->east_tx = NULL;
}

t_mapdata *scan_scene(t_list *head)
{
  t_mapdata *data;
  t_list *tmp;

  if(!head)
    return (NULL);
  data = (t_mapdata *)malloc(sizeof(t_mapdata));
  if(!data)
    return (NULL);
  __init_mapdata(data);
    
}
