
#include <mlx.h>
#include <stdio.h>

typedef struct s_texture {

  int height;
  int width;
  void *image;
  void *addr;
  int bits_per_pixel;
  int line_length;
  int endien;
} t_texture;

int main(){

  char *path = "./tx/wall.xpm";
  void *mlx = NULL;
  t_texture t;
  char *dst;

  mlx = mlx_init();
  t.image = mlx_xpm_file_to_image(mlx, path, &t.width, &t.height);
  t.addr = mlx_get_data_addr(t.image, &t.bits_per_pixel, &t.line_length, &t.endien);

  //dst = t.addr + wall.tex_y * texture->line_length + wall.tex_x * (texture->bits_per_pixel / 8);
  dst = t.addr + 20 * t.line_length + 20 * (t.bits_per_pixel / 8);

  printf("height : %d\n", t.height);
  printf("width: %d\n", t.width);
  printf("color[0] : %d\n", *(unsigned int *)dst);


}
