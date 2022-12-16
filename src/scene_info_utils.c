#include "../inc/header.h"
#include "../inc/map.h"

void	__init_mapdata(t_mapdata *data)
{
	data->ceilling_color = NULL;
	data->floor_color = NULL;
	data->north_tx = NULL;
	data->west_tx = NULL;
	data->south_tx = NULL;
	data->east_tx = NULL;
	data->map = NULL;
}

void	free_doubles(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_color_range(int color)
{
	if (color >= 0 && color <= 255)
		return (1);
	return (0);
}

int	arr_len(char **arr)
{
	int	len;

	if (!arr)
		return (0);
	len = 0;
	while (arr[len])
		len++;
	return (len);
}

int	check_color_format(char *color)
{
	int	i;
	int	count;

	if (!color)
		return (0);
	i = 0;
	count = 0;
	while (color[i])
	{
		if (color[i] == ',')
			count++;
		else if ((color[i] != ' ' && color[i] != '\t')
			&& (color[i] < '0' || color[i] > '9'))
			return (0);
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}
