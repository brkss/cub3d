/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:34:30 by bberkass          #+#    #+#             */
/*   Updated: 2021/12/14 21:02:47 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/gnl.h"

int	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strdup(const char *s1)
{
	char			*dup;
	unsigned int	i;
	unsigned int	sl;

	i = 0;
	sl = ft_strlen(s1);
	dup = (char *)malloc(sl + 1 * sizeof(char));
	if (!dup)
		return (0);
	while (s1[i] && i < sl)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strcat(char *dest, const char *s1, const char *s2)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s1[i])
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		dest[j] = s2[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*joined;
	int		s1_length;
	int		s2_length;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	joined = (char *)malloc((s1_length + s2_length + 1) * sizeof(char));
	if (!joined)
		return (0);
	joined = ft_strcat(joined, s1, s2);
	free(s1);
	return (joined);
}
