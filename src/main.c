/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:54:23 by adriouic          #+#    #+#             */
/*   Updated: 2022/12/20 00:24:29 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	abs_(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

t_mapdata	*check_(int ac, char **av)
{
	int			map_fd;
	t_list		*scene;
	t_mapdata	*data;

	map_fd = check_args(ac, av);
	if (map_fd == -1 || !check_extension(av[1]))
		exit_log("Error: Invalid Map");
	scene = read_map(av[1]);
	if (!scene)
		exit_log("Error: Invalid Map file");
	data = scan_scene(scene);
	if (!data)
		exit_log("Missing data");
	if (!data->west_tx || !data->north_tx
		|| !data->east_tx || !data->south_tx)
		exit_log("Invalid Textures !");
	if (!check_map(data))
		exit_log("Invalid map");
	return (data);
}

int	main(int ac, char **av)
{
	t_window	win;
	t_param		p;
	t_mapdata	*data;	

	data = check_(ac, av);
	p.data = data;
	__inits(&win, &p);
	__init_textures(&p, data);
	ray_caster(&p);
	mlx_hook(win.mlx_win_ptr, 17, 0, (int (*)(void))exit, NULL);
	mlx_hook(win.mlx_win_ptr, 2, 0L, move, &p);
	mlx_loop(win.mlx_ptr);
}
