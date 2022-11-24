/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:57:21 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/09 14:14:46 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	index;
	unsigned int	s_len;

	if (!s)
		return (0);
	index = 0;
	s_len = ft_strlen(s);
	if (s_len < len)
		len = s_len;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	while (index < len && start < s_len && s[index])
	{
		substr[index] = s[start];
		start++;
		index++;
	}
	substr[index] = '\0';
	return (substr);
}
