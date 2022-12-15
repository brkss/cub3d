#include "../inc/header.h"

// doc https://harm-smits.github.io/42docs/libs/minilibx/colors.html#encoding-and-decoding-colors
int	create_trgb(int t, int r, int g, int b)
{
		return (t << 24 | r << 16 | g << 8 | b);
}

double abs_(double x)
{
	return (x < 0 ? -x : x) ;
}

int main(int ac, char **av)
{

		t_window	win;
		t_param		p;

		int map_fd;
		t_list *scene;
		t_mapdata *data;

		// START CHECKING SCENE 👀
		map_fd = check_args(ac, av);
		if(map_fd == -1 || !check_extension(av[1]))
				exit_log("Error: Invalid Map");
		scene = read_map(av[1]);
		if(!scene)
				exit_log("Error: Invalid Map file");
		data = scan_scene(scene);
		if(!data)
				exit_log("Missing data");
		if(!data->west_tx || !data->north_tx
						|| !data->east_tx || !data->south_tx)
				exit_log("Invalid Textures !");
		if(!check_map(data))
				exit_log("Invalid map");
		// END CHECKING SCENE 

		p.data = data;
		__inits(&win, &p);
		__init_textures(&p, data);
		ray_caster(&p);
		mlx_hook(win.mlx_win_ptr, 17, 0, (int (*)(void))exit , NULL);
		mlx_hook(win.mlx_win_ptr, 2, 0L, move, &p);
		mlx_loop(win.mlx_ptr);

		//draw_ceil_floor(win.mlx_win_image);
		//mlx_put_image_to_window(win.mlx_ptr, win.mlx_win_ptr, win.image, 0, 0);
		//mlx_key_hook(win.mlx_win_ptr, move, &p);
		//mlx_loop_hook(win.mlx_ptr, draw_walls, &p);
		//mlx_do_key_autorepeaton(win.mlx_ptr);
}

