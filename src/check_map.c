
#include "../inc/header.h"
#include "../inc/map.h"

char **convert_map(t_list *map_chain)
{
  char **map;
  int len;
  t_list *curr;
  int i;

  len = ft_lstsize(map_chain);
  map = (char **)malloc(sizeof(char *) * len + 1);
  if(!map)
    return (NULL);
  curr = map_chain;
  i = 0;
  while(curr)
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

  if(!map)
    return (0);
  len = 0;
  while(map[len])
    len++;
  return (len);
}

int check_vertical_walls(char *line)
{
  int i;
  
  if(!line)
    return (0);
  i = 0;
  while(line[i])
  {
    if(line[i] != '1')
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

  if(!line)
    return(0);
  len = ft_strlen(line);
  if(line[0] != '1' || line[len - 1] != '1')
    return (0);
  return (1);
}

int check_walls_by_index(char *line, int start, int end)
{
  int i;

  i = end - start;
  while(i < end)
  {
    if(line[i] != '1')
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
  if(next_len == curr_len)
    return (1);
  if(curr_len > next_len
      && !check_walls_by_index(curr_line, curr_len - next_len, curr_len))
    return (0);
  else if(curr_len < next_len
      && !check_walls_by_index(next_line, next_len - curr_len, next_len))
      return (0);
  return (1);
}

int check_map_walls(char **map)
{
  int i;
  int map_len;

  if(!map)
    return (0);
  i = 0;
  map_len = ft_arrlen(map);
  while(map[i])
  {
    if((i == 0 || i == map_len - 1) && !check_vertical_walls(map[i]))
      return (0); 
    else if(!check_horizontal_walls(map[i]))
      return (0);  
    if(i < map_len - 1 && !check_shaped_lines(map[i], map[i + 1]))
      return (0);
    i++;
  }
  return (1);
}

int check_player(char **map)
{
  int i;
  int j;
  int player_exist;

  if(!map)
    return (0);
  i = 0;
  player_exist = 0;
  while(map[i])
  {
    j = 0;
    while(map[i][j] && map[i][j] != ' ')
        j++;
    while(map[i][j])
    {
      if(map[i][j] == 'N' || map[i][j] == 'W'
          || map[i][j] == 'E' || map[i][j] == 'S')
      {
        if(player_exist == 1)
          return (0);
        player_exist = 1;
      }
      else if (map[i][j] == '0' &&  map[i][j + 1] && map[i][j] == ' ')
            return (0);
      else if(map[i][j] != '1' && map[i][j] != '0' && j > 0 && map[i][j - 1] != '1')
      {
        return (0);
      }
      j++;
    }
    i++;
  }
  return (player_exist);
}

int check_map(char **map)
{
  if(!check_player(map) || !check_map_walls(map))
    return (0);
  return (1);
}
