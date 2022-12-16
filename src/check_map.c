
#include "../inc/header.h"
#include "../inc/map.h"

char  **convert_map(t_list *map_chain)
{
  char    **map;
  int     len;
  t_list  *curr;
  int     i;

  len = ft_lstsize(map_chain);
  map = (char **)malloc(sizeof(char *) * (len + 1));
  if (!map)
    return (NULL);
  curr = map_chain;
  i = 0;
  while (curr)
  {
    map[i] = curr->content;
    i++;
    curr = curr->next;
  }
  return (map);
}

int ft_arrlen(char **map)
{
  int len;

  if (!map)
    return (0);
  len = 0;
  while (map[len])
    len++;
  return (len);
}

int check_vertical_walls(char *line)
{
  int i;

  if (!line)
    return (0);
  i = 0;
  while(line[i] && line[i] == ' ')
    i++;
  while (line[i])
  {
    if (line[i] != '1' && line[i] != ' ')
    {
      printf("vertical lines failed !\n");
      return (0);
    }
    i++;
  }
  return (1);
}

int check_horizontal_walls(char *line)
{
  int len;

  if (!line)
    return (0);
  len = ft_strlen(line);
  if (line[0] != '1' || line[len - 1] != '1')
    return (0);
  return (1);
}

int check_walls_by_index(char *line, int start, int end)
{
  int i;

  i = end - start;
  while (i < end)
  {
    if (line[i] != '1')
      return (0);
    i++;
  }
  return (1);
}

int check_shaped_lines(char *curr_line, char *next_line)
{
  int curr_len;
  int next_len;

  curr_len = ft_strlen(curr_line);
  next_len = ft_strlen(next_line);
  if (next_len == curr_len)
    return (1);
  if (curr_len > next_len && !check_walls_by_index(curr_line, curr_len - next_len, curr_len))
    return (0);
  else if (curr_len < next_len && !check_walls_by_index(next_line, next_len - curr_len, next_len))
    return (0);
  return (1);
}

int check_map_walls(char **map)
{
  int i;
  int map_len;

  if (!map)
    return (0);
  i = 0;
  map_len = ft_arrlen(map);
  while (map[i])
  {
    if ((i == 0 || i == map_len - 1) && !check_vertical_walls(map[i]))
      return (0);
    else if (!check_horizontal_walls(map[i]))
      return (0);
    if (i < map_len - 1 && !check_shaped_lines(map[i], map[i + 1]))
      return (0);
    i++;
  }
  return (1);
}

int check_player(t_mapdata *data)
{
  int   i;
  int   j;
  int   player_exist;
  char  **map;

  if (!data || !data->map)
    return (0);
  i = 0;
  player_exist = 0;
  map = data->map;
  while (map[i])
  {
    j = 0;
    while (map[i][j])
    {
      if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S')
      {
        if (player_exist == 1)
          return (0);
        data->player_x = j;
        data->player_y = i;
        player_exist = 1;
      }
      j++;
    }
    i++;
  }
  return (player_exist);
}


// -- new map parser !
int is_player(char c)
{
  if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
    return (1);
  return (0);
}

int is_tile(char c)
{
  if (c == '1' || is_player(c) || c == '0' || c == ' ' || c =='\n' || c == '\0')
    return (1);
  return (0);
}

int check_tile_env(char *line, char *up, char *down)
{
  int i;

  i = 0;
  while(line[i])
  {
    if(!is_tile(line[i])){
      printf("not tile %c \n", line[i]);
      return (0);
    }
    if(line[i] == '0' || is_player(line[i]))
    {
      if (up[i] == ' ' || up[i] == '\n' || up[i] == '\0'
          || down[i] == '\n' || down[i] == ' ' || down[i] == '\0')
      {
        printf("tile not surrounded by what is sould \n");
        printf("line>>>>%s<<<<< ---- index : %d \n", line, i);
        
        return (0);
      }
    }
    i++;
  }
  return (1);
}


int _check_map(char **map){
  int i;

  i = 0;
  while(map[i])
  {
    if((i == 0 || i == arr_len(map) - 1) && !check_vertical_walls(map[i]))
    {
      printf("check vertical walls got 0\n");
      return (0);
    }
       
    else if(!check_tile_env(map[i], map[i + 1], map[i - 1]))
    {
      printf("check tile env got 0\n");
      return (0);
    }
     
    i++;
  }
  return (1);
}

int check_map(t_mapdata *data)
{
  if (!check_player(data) || !_check_map(data->map))
    return (0);
  return (1);
}
