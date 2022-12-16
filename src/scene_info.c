/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:40:09 by bberkass          #+#    #+#             */
/*   Updated: 2022/12/16 19:21:37 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"
#include "../inc/map.h"

void	get_texture(char *line, t_mapdata *data, int res)
{
	char	*val;
	int		i;

	if (!line)
		return ;
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	i += 2;
	val = ft_strtrim(&line[i], " ");
	if (!val)
		return ;
	if (res == WEST_TEXTURE && !data->west_tx)
		data->west_tx = val;
	else if (res == NORTH_TEXTURE && !data->north_tx)
		data->north_tx = val;
	else if (res == SOUTH_TEXTURE && !data->south_tx)
		data->south_tx = val;
	else if (res == EAST_TEXTURE && !data->east_tx)
		data->east_tx = val;
	else
		exit_log("Invalid Data !");
	return ;
}

int	*convert_color(char *color)
{
	int		*res;
	char	*trimmed;
	char	**colors;

	if (!color || ft_strlen(color) == 0)
		exit_log(NULL);
	trimmed = ft_strtrim(color, " ");
	if (!trimmed)
		exit_log("Invalid scene");
	if (!check_color_format(trimmed))
		exit_log("Invalid colors format !");
	colors = ft_split(trimmed, ',');
	if (!colors)
		exit_log("Invalid colors");
	if (arr_len(colors) < 3)
		exit_log("Invalid colors");
	res = (int *)malloc(sizeof(int) * 3);
	if (!res)
		exit_log(NULL);
	assign_colors(res, colors);
	free_doubles(colors);
	free(trimmed);
	return (res);
}

void	get_color(char *line, t_mapdata *data, int res)
{
	char	*val;

	if (!line)
		return ;
	val = ft_strtrim(line, " ");
	if (!val)
		return ;
	if (res == CEILLING_COLOR && !data->ceilling_color)
		data->ceilling_color = convert_color(val + 1);
	else if (res == FLOOR_COLOR && !data->floor_color)
		data->floor_color = convert_color(val + 1);
	else
		exit_log("Bad scene file !");
	free(val);
	return ;
}

t_mapdata	*get_map(t_mapdata *data, t_list *scene)
{
	t_list	*curr;

	if (!data || !scene)
		return (NULL);
	curr = scene;
	while (curr && ft_strlen(curr->content) == 0)
	{
		curr = curr->next;
	}
	data->map = convert_map(curr);
	return (data);
}

t_mapdata	*scan_scene(t_list *head)
{
	t_mapdata	*data;
	t_list		*curr;
	int			res;

	data = (t_mapdata *)malloc(sizeof(t_mapdata));
	if (!head || !data)
		return (NULL);
	__init_mapdata(data);
	curr = head;
	while (curr)
	{
		res = is_map_info(curr->content);
		if (res == WEST_TEXTURE || res == EAST_TEXTURE
			|| res == SOUTH_TEXTURE || res == NORTH_TEXTURE)
			get_texture(curr->content, data, res);
		else if (res == FLOOR_COLOR || res == CEILLING_COLOR)
			get_color(curr->content, data, res);
		else if (!res)
			exit_log("Invalid Data !");
		else if (got_all_data(data))
			return (get_map(data, curr));
		curr = curr->next;
	}
	return (NULL);
}
