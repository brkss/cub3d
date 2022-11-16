

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
