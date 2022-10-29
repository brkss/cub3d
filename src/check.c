


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
