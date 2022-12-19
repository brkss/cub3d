/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:36:46 by adriouic          #+#    #+#             */
/*   Updated: 2022/12/19 22:36:50 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

bool	rotate(int key, t_param *p)
{
	double	r_speed;
	double	tmp;

	r_speed = 0.14;
	if (key == RIGHT)
	{
		tmp = p->dir.x;
		p->dir.x = p->dir.x * cos(r_speed) - p->dir.y * sin(r_speed);
		p->dir.y = tmp * sin(r_speed) + p->dir.y * cos(r_speed);
		tmp = p->plane.x;
		p->plane.x = p->plane.x * cos(r_speed) - p->plane.y * sin(r_speed);
		p->plane.y = tmp * sin(r_speed) + p->plane.y * cos(r_speed);
	}
	else if (key == LEFT)
	{
		tmp = p->dir.x;
		p->dir.x = p->dir.x * cos(-r_speed) - p->dir.y * sin(-r_speed);
		p->dir.y = tmp * sin(-r_speed) + p->dir.y * cos(-r_speed);
		tmp = p->plane.x;
		p->plane.x = p->plane.x * cos(-r_speed) - p->plane.y * sin(-r_speed);
		p->plane.y = tmp * sin(-r_speed) + p->plane.y * cos(-r_speed);
	}
	else
		return (0);
	return (1);
}

bool	side_move(int key, t_param *p)
{
	double	m_speed;

	m_speed = 0.21;
	if (key == KEY_A)
	{
		if (p->map[(int)(p->y - p->plane.y * m_speed)]
				[(int)(p->x - p->plane.x * m_speed)] == '0')
		{
			p->y -= p->plane.y * m_speed;
			p->x -= p->plane.x * m_speed;
		}
	}
	else if (key == KEY_D)
	{
		if (p->map[(int)(p->y + p->plane.y * m_speed)]
				[(int)(p->x + p->plane.x * m_speed)] == '0')
		{
			p->y += p->plane.y * m_speed;
			p->x += p->plane.x * m_speed;
		}
	}
	else
		return (0);
	return (1);
}

bool	front_move(int key, t_param *p)
{
	double	m_speed;

	m_speed = 0.52;
	if (key == KEY_W)
	{
		if (p->map[(int)(p->y + p->dir.y * m_speed)]
				[(int)(p->x + p->dir.x * m_speed)] == '0')
		{
			p->x += (p->dir.x * m_speed);
			p->y += (p->dir.y * m_speed);
		}
	}
	else if (key == KEY_S)
	{
		if (p->map[(int)(p->y - p->dir.y * m_speed)]
				[(int)(p->x - p->dir.x * m_speed)] == '0')
		{
			p->x -= p->dir.x * m_speed;
			p->y -= p->dir.y * m_speed;
		}
	}
	else
		return (0);
	return (1);
}

int	move(int key, void *param)
{
	t_param	*p;

	p = (t_param *) param;
	if (side_move(key, p) || front_move(key, p) || rotate(key, p))
		ray_caster(p);
	if (key == 53)
		exit(42);
	return (1);
}
