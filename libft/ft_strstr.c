/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:01:39 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/23 20:03:01 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *container, char *target)
{
	int	i;
	int	j;
	int	r;

	if (!target || !container)
		return (NULL);
	i = 0;
	while (container[i])
	{
		j = 0;
		r = i;
		while (target[j] && target[j] == container[i + j])
		{
			if (!target[j + 1])
				return (&container[r]);
			j++;
		}
		i++;
	}
	return (NULL);
}
