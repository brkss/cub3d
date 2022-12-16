#include "../inc/header.h"
#include "../inc/map.h"

t_texture	*set_texture(void *mlx_ptr, char *path)
{
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->image = mlx_xpm_file_to_image(mlx_ptr, path,
			&texture->tx_width, &texture->tx_height);
	if (!texture->image)
	{
		free(texture);
		return (NULL);
	}
	texture->addr = mlx_get_data_addr(texture->image,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	return (texture);
}
