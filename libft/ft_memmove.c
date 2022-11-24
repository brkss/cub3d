/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:08:22 by adriouic          #+#    #+#             */
/*   Updated: 2022/04/06 16:24:05 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*t_dst;
	char	*t_src;
	int		leader;

	t_dst = (char *)dst;
	t_src = (char *)src;
	if (!dst && !src)
		return (dst);
	leader = 1;
	if (t_dst > t_src)
	{
		t_src = t_src + len - 1;
		t_dst = t_dst + len - 1;
		leader = -1;
	}
	while (len--)
	{
		*t_dst = *t_src;
		t_src += leader;
		t_dst += leader;
	}
	return (dst);
}
