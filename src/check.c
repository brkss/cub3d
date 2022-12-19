/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:39:50 by bberkass          #+#    #+#             */
/*   Updated: 2022/12/16 17:40:25 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	check_args(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	return (fd);
}

int	check_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename) - 1;
	if (len < 4)
		return (0);
	if (filename[len] == 'b' && filename[len - 1] == 'u'
		&& filename[len - 2] == 'c' && filename[len - 3] == '.')
		return (1);
	return (0);
}
