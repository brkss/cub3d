#include "../inc/header.h"
#include "../inc/map.h"


void get_texture(char *line, t_mapdata *data, int res)
{
  char *val;
  int i;

  if(!line)
    return;
  i = 0;
  while(line[i]  && line[i] == ' ')
    i++;
  i += 2;
  val = ft_strtrim(&line[i], " ");  
  if(!val)
    return ;
  if(res == WEST_TEXTURE && !data->west_tx)
    data->west_tx = val;
  else if(res == NORTH_TEXTURE && !data->north_tx)
    data->north_tx = val;
  else if(res == SOUTH_TEXTURE && !data->south_tx)
    data->south_tx = val;
  else if(res == EAST_TEXTURE && !data->east_tx)
    data->east_tx = val;
  else
    exit_log("Invalid Data !");
  return ;
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
  if(!check_color_format(trimmed))
    exit_log("Invalid colors format !");
  colors = ft_split(trimmed, ',');
  if(!colors)
    exit_log("Invalid colors");
  if(arr_len(colors) < 3)
    exit_log("Invalid colors");
  res = (int *)malloc(sizeof(int) * 3);
  if(!res)
    exit_log(NULL);
  res[0] = ft_atoi(colors[0]);
  res[1] = ft_atoi(colors[1]);
  res[2] = ft_atoi(colors[2]);
  if(!check_color_range(res[0]) || !check_color_range(res[1])
      || !check_color_range(res[2]))
    exit_log("Invalid color");
  free_doubles(colors);
  free(trimmed);
  return (res);
}

void get_color(char *line, t_mapdata *data, int res)
{
  char *val;

  if(!line)
    return;
  val = ft_strtrim(line, " ");
  if(!val)
    return ;
  if(res == CEILLING_COLOR && !data->ceilling_color)
    data->ceilling_color = convert_color(val + 1);
  else if(res == FLOOR_COLOR && !data->floor_color)
    data->floor_color = convert_color(val + 1);
  else
    exit_log("Bad scene file !");
  free(val);
  return ;
}

int is_color(char *line){
  int i;
  if(!line)
    return (0);
  
  i = 0;
  while(line[i] && line[i] == ' ')
    i++;
  if(line[i] && line[i] == 'F')
    return (FLOOR_COLOR);
  else if(line[i] && line[i] == 'C')
    return (CEILLING_COLOR);
  return (0);
}

int is_texture(char *line){
  int i;
  if(!line)
    return (0);
  
  i = 0;
  while(line[i] && line[i] == ' ')
    i++;
  if(line[i] && line[i + 1] && line[i] == 'N' && line[i + 1] == 'O')
    return NORTH_TEXTURE;
  else if(line[i] && line[i + 1] && line[i] == 'S' && line[i + 1] == 'O')
    return  SOUTH_TEXTURE;
  else if(line[i] && line[i + 1] && line[i] == 'W' && line[i + 1] == 'E')
    return WEST_TEXTURE;
  else if(line[i] && line[i + 1] && line[i] == 'E' && line[i + 1] == 'A')
    return EAST_TEXTURE;
  return (0);
}

int is_map_info(char *line)
{
  if(line && ft_strlen(line) == 0)
    return EMPTY_LINE;
  if(line && is_texture(line))
    return is_texture(line);
  if(line && is_color(line))
    return  is_color(line);
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
  data->map = NULL;
}

void get_map(t_mapdata *data, t_list *scene)
{
  t_list *curr;

  if(!data || !scene)
    return;
  curr = scene;
  while(curr && ft_strlen(curr->content) == 0){
    curr = curr->next;
  } 
  data->map = convert_map(curr);
}

int got_all_data(t_mapdata *data)
{
  if(data->ceilling_color && data->floor_color && data->north_tx
      && data->west_tx && data->east_tx && data->south_tx)
    return (1);
  return (0);
}

t_mapdata *scan_scene(t_list *head)
{
  t_mapdata *data;
  t_list *curr;
  int res;

  if(!head)
    return (NULL);
  data = (t_mapdata *)malloc(sizeof(t_mapdata));
  if(!data)
    return (NULL);
  __init_mapdata(data);
  curr = head;
  while(curr)
  {
    res = is_map_info(curr->content); 
    if(res == WEST_TEXTURE || res == EAST_TEXTURE
        || res == SOUTH_TEXTURE || res == NORTH_TEXTURE)
      get_texture(curr->content, data, res);
    else if (res == FLOOR_COLOR || res == CEILLING_COLOR)
      get_color(curr->content, data, res);
    else if(!res)
      exit_log("Invalid Data !");
    else if(got_all_data(data))
    {
      get_map(data, curr);
      return data;
    }
    curr = curr->next;
  }
  return (NULL);
}
