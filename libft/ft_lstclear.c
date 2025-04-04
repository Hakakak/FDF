/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:37:10 by haykharu          #+#    #+#             */
/*   Updated: 2025/01/25 19:22:39 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*s;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		(*del)((*lst)->content);
		s = *lst;
		*lst = (*lst)->next;
		free(s);
	}
	*lst = NULL;
}
