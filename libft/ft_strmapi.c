/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:31:47 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/09 13:58:18 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		s_length;
	int		i;
	char	*result;

	if (!s)
		return (0);
	s_length = ft_strlen(s);
	result = (char *)malloc(1 + s_length * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (i < s_length)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
