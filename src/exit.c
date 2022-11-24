
#include "../inc/header.h"


void exit_log(char const *err)
{
  if(err)
    printf("Error: %s\n", err);
  else
    printf("Error\n");
  exit(0);
}
