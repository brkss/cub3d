

#include "../inc/header.h"
#include "../inc/map.h"


// mlx functions manual : https://qst0.github.io/ft_libgfx/man_mlx_new_image.html
t_texture *set_texture(void *mlx_ptr, char *path){
  t_texture *texture;

  (void)mlx_ptr;
  (void)path;
  texture = (t_texture *)malloc(sizeof(t_texture));
  if(!texture)
    return (NULL);

  texture->image = mlx_xpm_file_to_image(mlx_ptr, path, &texture->height, &texture->width);
  if (!texture->image){
    free(texture);
    return (NULL);
  }
  texture->addr = mlx_get_data_addr(texture->image, &texture->bits_per_pixel, &texture->line_length, &texture->endien);
  return (texture);

}
