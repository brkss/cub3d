

#include "../inc/map.h"
#include "../inc/header.h"

// take src and dest copy src to dest and terminate dest with \0
// note that must be allocated before !
static void ft_strcpy(char *src, char *dest)
{
  int i;
  
  if(!src || !dest)
    return ;
  i = 0;
  while(src[i] && src[i] != ' '){
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';  
}

// return allocated string containing texture path 
// or NULL in case of error or texture not found 
char *get_texture(char **map, char *texture_id)
{
  int i;
  int j;
  char *path;
  int len;

  if(!map)
    return (NULL);

  i = 0;
  j = 0;
  while(map[i]){
    if(map[i][0] && map[i][1] && map[i][0] == texture_id[0] && texture_id[1] == map[i][1]){
      j = 2;
      while(map[i] && map[i][j] == ' ')
        j++;
      len = ft_strlen(&map[i][j]);
      path = (char *)malloc(sizeof(char) * len + 1);
      if(!path){
        return (NULL);
      }
      ft_strcpy(&map[i][j], path);
      return (path);
    }
    i++;
  }
  return (NULL);
}

char *get_color(char **map, char id){
  int len;
  int i;
  int j;
  char *color;
  
  if(!map)
    return (NULL);
  i = 0;
  j = 0;
  while(map[i]){
    if(map[i] && map[i][0] == id){
      j = 1;
      while(map[i][j] && map[i][j] == ' ')
        j++;
      len = ft_strlen(&map[i][j]);
      color = (char *)malloc(sizeof(char) * len);
      if(!color)
        return (NULL);
      ft_strcpy(&map[i][j], color);
      return (color);
    } 
    i++;
  }
  return (NULL);
}

char **get_map(char **scene)
{
  int i;

  i = 0;
  while(scene[i])
  {
    printf("len : %zu\n", ft_strlen(scene[i]));
    i++;
  }
  return (NULL);
}
