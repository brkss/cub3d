/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:47:10 by adriouic          #+#    #+#             */
/*   Updated: 2022/04/06 17:14:58 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*ts1;	
	unsigned char	*ts2;

	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	index = 0;
	if (n == 0)
		return (0);
	while (ts1[index] != '\0' && ts2[index] != '\0' && index < n - 1)
	{
		if (ts1[index] == ts2[index])
			index++;
		else
			return (ts1[index] - ts2[index]);
	}
	return (ts1[index] - ts2[index]);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			index;
	unsigned char	*ts1;
	unsigned char	*ts2;

	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	index = 0;
	while (ts1[index] != '\0' && ts2[index] != '\0')
	{
		if (ts1[index] == ts2[index])
			index++;
		else
			return (ts1[index] - ts2[index]);
	}
	return (ts1[index] - ts2[index]);
}
