/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plstut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:27:34 by haykharu          #+#    #+#             */
/*   Updated: 2025/05/01 19:13:58 by haykharu         ###   ########.fr       */
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

t_plist	*ft_lstfind_nxty(t_plist *lst, int xlen)
{
	if (!lst || xlen <= 0)
		return (NULL);
	while (lst != NULL && xlen)
	{
		--xlen;
		lst = lst->next;
	}
	return (lst);
}
