/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:56:26 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/03 11:03:43 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_plist	*ft_plstlast(t_plist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_plstadd_b(t_plist **lst, t_plist *new)
{
	t_plist	*ls;

	ls = ft_plstlast(*lst);
	if (ls)
		ls->next = new;
	else
		*lst = new;
}

void	ft_plstadd_f(t_plist **lst, t_plist *new)
{
	if (!lst || !*lst)
	{
		*lst = new;
		(*lst)->next = new->next;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_plstclear(t_plist **lst)
{
	t_plist	*s;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		if ((*lst)->pix)
			free((*lst)->pix);
		s = *lst;
		*lst = (*lst)->next;
		free(s);
	}
	*lst = NULL;
}

t_plist	*ft_plstnew(t_pix *pix)
{
	t_plist	*list;

	list = (t_plist *) malloc(sizeof(t_plist));
	if (!list)
		return (NULL);
	list->pix = pix;
	list->next = NULL;
	return (list);
}
