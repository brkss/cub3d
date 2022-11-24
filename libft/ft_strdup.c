/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:55:18 by adriouic          #+#    #+#             */
/*   Updated: 2022/04/09 22:28:06 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		s1len;
	int		index;
	char	*cpy;

	if (!s1)
		return (0);
	index = 0;
	s1len = ft_strlen(s1);
	cpy = (char *)malloc(s1len * sizeof(char) + 1);
	if (!cpy)
		return (0);
	while (s1[index])
	{
		cpy[index] = s1[index];
		index++;
	}
	cpy[index] = '\0';
	return (cpy);
}
