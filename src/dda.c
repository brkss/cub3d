#include "../inc/header.h"

double	dda_(int gridx, int gridy, t_param *p, t_vector *delta)
{
	t_vector	step;
	double		dist_x_y[2];
	int			side;

	get_dist_x_y(dist_x_y, p, delta, &step);
	while (42)
	{
		if (dist_x_y[0] < dist_x_y[1])
		{
			dist_x_y[0] += delta->x;
			gridx += (int)step.x;
			side = 1;
		}
		else
		{
			dist_x_y[1] += delta->y;
			gridy += (int)step.y;
			side = 0;
		}
		if (p->map[gridy][gridx] == '1')
			break ;
	}
	if (side == 1)
		return ((dist_x_y[0] - delta->x) * -1);
	return (dist_x_y[1] - delta->y);
}
