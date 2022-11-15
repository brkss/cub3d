
#include "../inc/header.h"
#include "../inc/map.h"

void get_texture(char *line, t_mapdata *data, int res)
{
  char *val;
  int len;
  int i;

  if(!line)
    return;
  len = ft_strlen(line);
  i = 2;
  while(line && len > 2 && line[i] == ' ')
    i++;
  val = ft_strdup(&line[i]);
  if(!val)
    return ;
  if(res == WEST_TEXTURE)
    data->west_tx = val;
  else if(res == NORTH_TEXTURE)
    data->north_tx = val;
  else if(res == SOUTH_TEXTURE)
    data->south_tx = val;
  else if(res == EAST_TEXTURE)
    data->east_tx = val;
  return ;
}

static int arr_len(char **arr)
{
  int len;

  if(!arr)
    return (0);
  len = 0;
  while(arr[len])
    len++;
  return (len);
}

int *convert_color(char *color)
{
  int *res;
  int len;
  char *trimmed;
  char **colors;

  len = ft_strlen(color);
  if(!color || len == 0)
    exit_log(NULL);
  trimmed = ft_strtrim(color, " ");
  if(!trimmed)
    exit_log("Invalid scene");
  free(color);
  colors = ft_split(trimmed, ',');
  if(!colors)
    exit_log("Invalid scene");
  free(trimmed);
  if(arr_len(colors) < 3)
    exit_log("Invalid colors");
  res = (int *)malloc(sizeof(int) * 3);
  if(!res)
    exit_log(NULL);
  res[0] = ft_atoi(colors[0]);
  res[1] = ft_atoi(colors[1]);
  res[2] = ft_atoi(colors[2]);
  return (res);
}

void get_color(char *line, t_mapdata *data, int res)
{
  char *val;
  int len;
  int i;

  if(!line)
    return;
  len = ft_strlen(line);
  i = 1;
  while(line && len > 2 && line[i] == ' ')
    i++;
  val = ft_strdup(&line[i]);
  if(!val)
    return ;
  if(res == CEILLING_COLOR)
    data->ceilling_color = convert_color(val);
  else if(res == FLOOR_COLOR)
    data->floor_color = convert_color(val);
  return ;
}

int is_testure(char *line)
{
  if(line && ft_strlen(line) >= 2 && line[0] == 'N' && line[1] == 'O')
    return NORTH_TEXTURE;
  else if(line && ft_strlen(line) >= 2 && line[0] == 'S' && line[1] == 'O')
    return  SOUTH_TEXTURE;
  else if(line && ft_strlen(line) >= 2 && line[0] == 'W' && line[1] == 'E')
    return WEST_TEXTURE;
  else if(line && ft_strlen(line) >= 2 && line[0] == 'E' && line[1] == 'A')
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
  t_list *curr;
  //t_list *prv;
  int res;

  if(!head)
    return (NULL);
  data = (t_mapdata *)malloc(sizeof(t_mapdata));
  if(!data)
    return (NULL);
  __init_mapdata(data);
    
  curr = head;
  //prv = NULL;
  while(curr)
  {
    res = is_testure(curr->content); 
    if(res == WEST_TEXTURE || res == EAST_TEXTURE
        || res == SOUTH_TEXTURE || res == NORTH_TEXTURE)
      get_texture(curr->content, data, res);
    if (res == FLOOR_COLOR || res == CEILLING_COLOR)
      get_color(curr->content, data, res);
    //prv = curr;
    curr = curr->next;
  }
  printf("map data west : %s\n", data->west_tx);
  printf("map data east : %s\n", data->east_tx);
  printf("map data north : %s\n", data->north_tx);
  printf("map data south : %s\n", data->south_tx);
  printf("map floor color : %d, %d, %d\n", data->floor_color[0], data->floor_color[1], data->floor_color[2]);
  printf("map ceilling color : %d, %d, %d\n", data->ceilling_color[0], data->ceilling_color[1], data->ceilling_color[2]);
  return (NULL);
}
