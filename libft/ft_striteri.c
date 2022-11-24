/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stiteri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:42:21 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/08 10:16:42 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	index;

	if (!s)
		return ;
	index = 0;
	while (s[index])
	{
		if (s[index])
			f(index, &s[index]);
		index++;
	}
}
