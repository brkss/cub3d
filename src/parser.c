

#include "../inc/header.h"
#include "../inc/map.h"

int count_map_lines(char *filename){
  int fd;
  char *line;
  int line_count;

  line_count = 0;
  fd = open(filename, O_RDONLY);
  line = get_next_line(fd);
  while(line){
    printf("->%s \n",line);
    line = get_next_line(fd);
    line_count++;
  }
  close(fd);
  return (line_count);
}

char **read_map(char *filename)
{
  int line_count;
  char **map;
  int fd;
  int i;
  char *line;

  i = 0;
  line_count = count_map_lines(filename);
  map = (char **)malloc(sizeof(char *) * line_count + 1);
  fd = open(filename, O_RDONLY);
  line = get_next_line(fd);
  while(line){
    map[i] = line;
    line = get_next_line(fd);
    i++;
  }
  map[i] = NULL;
  return (map);
}
