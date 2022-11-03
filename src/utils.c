
#include "../inc/header.h"
#include "../inc/map.h"


static int map_rows_count(char **map)
{
  int len;

  if(!map)
    return (0);
  len = 0;
  while(map[len])
    len++;
  return (len);
}

char **remove_row_map(char **map, int row_index)
{
  int map_len;
  char **new_map;
  int i;
  int j;

  map_len = map_rows_count(map);
  new_map = (char **)malloc(sizeof(char) * map_len);
  i = 0;
  j = 0;
  while(map[i])
  {
    if(i == row_index)
    {
      i++;
      continue;
    }
    new_map[j] = map[i];  
    i++;
    j++;
  }
  new_map[i] = NULL;
  free(map);
}
