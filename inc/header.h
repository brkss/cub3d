#ifndef HEADER_H
#define HEADER_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "./libft.h"

typedef struct s_window
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	void	*image;
	int 	*mlx_win_image;
	
	int  bits_per_pixel;	//	pointer to where the bpp is written;
	int  size_line	;	//	pointer to where the line is written;
	int  endian;
	int	win_width;
	int	win_higth;

}t_window;

void __init_win(int heigth, int width, t_window *win);
void exit_log(char const *err);

#endif
