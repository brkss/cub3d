#include "../inc/header.h"
bool rotate(int key, t_param *p)
{
		double r_speed = 0.24;
		if (key == RIGHT)
		{
				double tmp = p->dir.x;

				p->dir.x = p->dir.x * cos(r_speed) - p->dir.y * sin(r_speed);
				p->dir.y = tmp * sin(r_speed) + p->dir.y * cos(r_speed);
				tmp = p->plane.x;

				p->plane.x = p->plane.x * cos(r_speed) - p->plane.y * sin(r_speed);
				p->plane.y = tmp * sin(r_speed) + p->plane.y * cos(r_speed);
		}
		else if (key == LEFT)
		{
				double tmp = p->dir.x;

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

bool side_move(int key, t_param *p)
{

		double m_speed = 0.34;
		if (key == KEY_A)
		{
				if (p->map[(int)(p->y - p->plane.y  * m_speed)][(int)p->x] == '0')
						p->y -= p->plane.y * m_speed;
				if (p->map[(int)p->y][(int)(p->x - p->plane.x * m_speed)] == '0')
						p->x -=  p->plane.x * m_speed;
		}
		else if (key == KEY_D)
		{
				if (p->map[(int)(p->y + p->plane.y * m_speed)][(int)p->x] == '0')
						p->y += p->plane.y * m_speed;
				if (p->map[(int)p->y][(int)(p->x + p->plane.x * m_speed)]== '0')
						p->x += p->plane.x * m_speed;
		}
		else
				return (0);
		return (1);


}

bool front_move(int key, t_param *p)
{
		double m_speed = 0.34;

		if (key == KEY_W)
		{
				if (p->map[(int)(p->y + p->dir.y * m_speed)][(int)p->x] == '0')
						p->y += p->dir.y * m_speed;
				if (p->map[(int)p->y][(int)(p->x + p->dir.x * m_speed)]== '0')
						p->x += p->dir.x * m_speed;
		}
		else if (key == KEY_S)
		{
				if (p->map[(int)(p->y - p->dir.y  * m_speed)][(int)p->x] == '0')
						p->y -= p->dir.y * m_speed;
				if (p->map[(int)p->y][(int)(p->x - p->dir.x * m_speed)] == '0')
						p->x -=  p->dir.x * m_speed;
		}
		else
				return (0);
		return (1);
}

int  move(int key, void *param)
{
		t_param *p = (t_param *) param;

		if (side_move(key, p) || front_move(key, p) || rotate(key, p))
				ray_caster(p);
		return (1);
}