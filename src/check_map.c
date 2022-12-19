/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:39:42 by bberkass          #+#    #+#             */
/*   Updated: 2022/12/20 00:14:20 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"
#include "../inc/map.h"

char	**convert_map(t_list *map_chain)
{
	char	**map;
	int		len;
	t_list	*curr;
	int		i;

	len = ft_lstsize(map_chain);
	map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	curr = map_chain;
	i = 0;
	while (curr)
	{
		map[i] = curr->content;
		i++;
		curr = curr->next;
	}
	map[i] = NULL;
	return (map);
}

int	check_vertical_walls(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			exit_log("vertical lines check failed !");
		i++;
	}
	return (1);
}

int	check_tile_env(char *line, char *up, char *down)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_tile(line[i]))
			return (0);
		if (line[i] == '0' || is_player(line[i]))
		{
			if (up[i] == ' ' || up[i] == '\n'
				|| up[i] == '\0' || down[i] == '\n'
				|| down[i] == ' ' || down[i] == '\0')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_player(t_mapdata *data, char *line, int y)
{
	int	i;
	int	player_exist;

	if (!data)
		return (0);
	i = 0;
	player_exist = 0;
	while (line[i])
	{
		if (is_player(line[i]))
		{
			if (player_exist == 1)
				return (-1);
			data->player_x = i;
			data->player_y = y;
			player_exist = 1;
		}
		i++;
	}
	return (player_exist);
}

int	check_map(t_mapdata *data)
{
	int		i;
	int		player_exist;
	char	**map;

	i = 0;
	player_exist = 0;
	map = data->map;
	while (map[i])
	{
		if ((i == 0 || i == arr_len(map) - 1) && !check_vertical_walls(map[i]))
			return (0);
		else if (!check_tile_env(map[i], map[i + 1],
				map[i - 1]) || player_exist == -1)
			return (0);
		else if (!player_exist)
			player_exist = check_player(data, map[i], i);
		i++;
	}
	return (player_exist);
}
