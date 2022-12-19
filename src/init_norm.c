/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:34:59 by adriouic          #+#    #+#             */
/*   Updated: 2022/12/20 00:24:16 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/header.h"

int	__init_north_south(t_param *p, char face)
{
	if (face == 'N')
	{
		p->dir.x = 0;
		p->dir.y = -1;
		p->plane.y = 0;
		p->plane.x = -0.66;
	}
	else if (face == 'S')
	{
		p->dir.x = 0;
		p->dir.y = 1;
		p->plane.y = 0;
		p->plane.x = 0.66;
	}
	else
		return (0);
	return (1);
}

void	__init_west_east(t_param *p, char face)
{
	if (face == 'E')
	{
		p->dir.x = 1;
		p->dir.y = 0;
		p->plane.x = 0;
		p->plane.y = -0.66;
	}
	else if (face == 'W')
	{
		p->dir.x = -1;
		p->dir.y = 0;
		p->plane.x = 0;
		p->plane.y = 0.66;
	}
}

void	__init_player_dir(t_param *p)
{
	char	face;

	face = p->map[p->data->player_y][p->data->player_x];
	if (!__init_north_south(p, face))
		__init_west_east(p, face);
}
