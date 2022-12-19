/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberkass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:33:03 by bberkass          #+#    #+#             */
/*   Updated: 2022/02/15 00:26:59 by bberkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*get_line(char *s);
char	*get_rest(char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *s);

#endif
