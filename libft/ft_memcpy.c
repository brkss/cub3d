/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:59:37 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/08 10:10:44 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*t_dest;
	char	*t_src;

	t_dest = (char *) dest;
	t_src = (char *) src;
	if (!src && !dest)
		return (dest);
	i = 0;
	while (n > 0)
	{
		t_dest[i] = t_src[i];
		i++;
		n--;
	}
	return (dest);
}
