/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:13:47 by haykharu          #+#    #+#             */
/*   Updated: 2025/02/01 12:58:42 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_n;
	t_list	*lst_p;
	void	*cont_n;

	lst_p = NULL;
	while (lst != NULL)
	{
		cont_n = (*f)(lst->content);
		lst_n = ft_lstnew(cont_n);
		if (!lst_n)
		{
			ft_lstclear(&lst_p, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_p, lst_n);
		lst = lst->next;
	}
	return (lst_p);
}
