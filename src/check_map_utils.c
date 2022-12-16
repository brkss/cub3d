/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:21:56 by bberkass          #+#    #+#             */
/*   Updated: 2022/12/16 19:25:24 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"
#include "../inc/map.h"

int	ft_arrlen(char **map)
{
	int	len;

	if (!map)
		return (0);
	len = 0;
	while (map[len])
		len++;
	return (len);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

int	is_tile(char c)
{
	if (c == '1' || is_player(c) || c == '0'
		|| c == ' ' || c == '\n' || c == '\0')
		return (1);
	return (0);
}
