/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:22:56 by adriouic          #+#    #+#             */
/*   Updated: 2021/11/08 18:22:33 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;
	t_list	*curr;

	if (!*lst)
		return ;
	curr = (*lst)->next;
	ft_lstdelone(*lst, del);
	*lst = NULL;
	while (curr)
	{
		next_node = curr->next;
		ft_lstdelone(curr, del);
		curr = next_node;
	}
}
