/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_info_validators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:14:12 by bberkass          #+#    #+#             */
/*   Updated: 2022/12/16 19:18:48 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"
#include "../inc/map.h"

int	is_color(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && line[i] == 'F')
		return (FLOOR_COLOR);
	else if (line[i] && line[i] == 'C')
		return (CEILLING_COLOR);
	return (0);
}

int	is_texture(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && line[i + 1] && line[i] == 'N' && line[i + 1] == 'O')
		return (NORTH_TEXTURE);
	else if (line[i] && line[i + 1] && line[i] == 'S' && line[i + 1] == 'O')
		return (SOUTH_TEXTURE);
	else if (line[i] && line[i + 1] && line[i] == 'W' && line[i + 1] == 'E')
		return (WEST_TEXTURE);
	else if (line[i] && line[i + 1] && line[i] == 'E' && line[i + 1] == 'A')
		return (EAST_TEXTURE);
	return (0);
}

int	is_map_info(char *line)
{
	if (line && ft_strlen(line) == 0)
		return (EMPTY_LINE);
	if (line && is_texture(line))
		return (is_texture(line));
	if (line && is_color(line))
		return (is_color(line));
	return (0);
}

int	got_all_data(t_mapdata *data)
{
	if (data->ceilling_color && data->floor_color && data->north_tx
		&& data->west_tx && data->east_tx && data->south_tx)
		return (1);
	return (0);
}

void	assign_colors(int *res, char **colors)
{
	res[0] = ft_atoi(colors[0]);
	res[1] = ft_atoi(colors[1]);
	res[2] = ft_atoi(colors[2]);
	if (!check_color_range(res[0]) || !check_color_range(res[1])
		|| !check_color_range(res[2]))
		exit_log("Invalid color");
}
