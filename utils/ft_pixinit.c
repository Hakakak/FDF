/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:56:26 by haykharu          #+#    #+#             */
/*   Updated: 2025/05/01 19:18:18 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pix_addnxt(t_pix *pix)
{
	int		rgb[3];

	if (!pix)
		return ;
	rgb[0] = (pix->color >> 16) & 0xFF;
	rgb[1] = (pix->color >> 8) & 0xFF;
	rgb[2] = pix->color & 0xFF;
	if (rgb[0] < 255)
		++rgb[0];
	else if (rgb[0] >= 255 && rgb[1] < 255)
		++rgb[1];
	else if (rgb[1] >= 255 && rgb[2] < 255)
	{
		rgb[0] = 40;
		rgb[1] = 40;
		rgb[2] = 255;
	}
	else
	{
		rgb[0] = 180;
		rgb[1] = 40;
		rgb[2] = 40;
	}
	pix->color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
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
