/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:32:34 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/06 16:21:11 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/gnl.h"

char	*get_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\0';
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *s)
{
	char	*rest;
	int		i;
	int		s_len;
	int		j;

	j = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	s_len = ft_strlen(&s[i]) + 1;
	rest = (char *)malloc(sizeof(char) * s_len);
	if (!rest)
		return (NULL);
	while (s[i])
		rest[j++] = s[i++];
	rest[j] = '\0';
	free(s);
	return (rest);
}

int	nl_in(char *s)
{
	int	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	proccess_file(int fd, char **rest)
{
	char		*buff;
	int			readed;

	readed = 1;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (!nl_in(*rest) && readed > 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			free(*rest);
			return (0);
		}
		else if (readed > 0)
		{
			buff[readed] = '\0';
			*rest = ft_strjoin(*rest, buff);
			if (nl_in(*rest))
				break ;
		}
	}
	free(buff);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (!proccess_file(fd, &rest))
		return (NULL);
	if (rest)
	{
		line = get_line(rest);
		rest = get_rest(rest);
		if (!rest)
			free(rest);
	}
	return (line);
}