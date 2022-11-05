


#include "../inc/header.h"

// return file descriptor to map file 
// or -1 in case of error !

int check_args(int ac, char **av)
{
  int fd;

  if(ac != 2)
    return (-1);
  
  fd = open(av[1], O_RDONLY);
  return (fd);
}

static int ft_strlen(char *s)
{
  int l;

  if(!s)
    return (0);
  l = 0;
  while(s[l])
    l++;
  return (l);
}

int check_extension(char *filename)
{
  int len;
  
  if(!filename)
    return (0);
  len = ft_strlen(filename) - 1;
  if(filename[len] == 'b' && filename[len - 1] == 'u' && filename[len - 2] == 'c' && filename[len - 3] == '.')
    return (1);
  return (0);
}
