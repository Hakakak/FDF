/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plstut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:27:34 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/04 12:11:50 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_lfind_ylen(t_plist *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (-1);
	while (lst)
	{
		i = lst->pix->y;
		lst = lst->next;
	}
	return (i);
}

int	ft_lfind_xlen(t_plist *lst)
{
	int	i;
	int	y;

	i = 0;
	if (!lst)
		return (-1);
	y = lst->pix->y;
	while (y == lst->pix->y)
	{
		++i;
		lst = lst->next;
	}
	return (i);
}

t_plist	*ft_findlst(t_plist *lst, int x, int y)
{
	if (!lst || x < 0 || y < 0)
		return (NULL);
	while (lst != NULL)
	{
		if (x == lst->pix->x && y == lst->pix->y)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
