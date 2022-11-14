/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:21:32 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/10 21:56:49 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	index;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	index = d_len;
	if (size == 0)
		return (s_len);
	while (index < size - 1 && src[index - d_len] != '\0')
	{
		dest[index] = src[index - d_len];
		index++;
	}
	if (size < index)
	{
		return (size + s_len);
	}
	dest[index] = '\0';
	return (d_len + s_len);
}
