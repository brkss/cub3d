/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:38:16 by bberkass          #+#    #+#             */
/*   Updated: 2022/04/23 20:00:03 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skiptarget(char *container, char *target)
{
	while (*container && *target && *target == *container)
	{
		target++;
		container++;
	}
	return (container);
}

static void	ft_cpy(char *container, char *target, char *replacement, char *res)
{
	int		i;
	char	*occ;

	occ = ft_strstr(container, target);
	i = 0;
	while (*container && container != occ)
	{
		res[i] = *container;
		i++;
		container++;
	}
	container = ft_skiptarget(container, target);
	while (*replacement)
	{
		res[i] = *replacement;
		replacement++;
		i++;
	}
	while (*container)
	{
		res[i] = *container;
		i++;
		container++;
	}
	res[i] = '\0';
}

char	*ft_strreplace(char *container, char *target, char *replacement)
{
	char	*res;
	char	*occ;
	int		size;

	if (!target || !replacement || !container)
		return (NULL);
	occ = ft_strstr(container, target);
	if (!occ)
		return (NULL);
	size = (ft_strlen(container) - ft_strlen(target)) + ft_strlen(replacement);
	res = (char *)malloc(sizeof(char) * size + 1);
	ft_cpy(container, target, replacement, res);
	return (res);
}
