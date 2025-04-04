/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:19:17 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/04 13:04:01 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear_pline(t_plist **lst)
{
	t_plist	*tmp;
	int	y;

	if (!lst || !*lst)
		return ;
	y = (*lst)->pix->y;
	while (*lst != NULL)
	{
		if (y != (*lst)->pix->y)
			break ;
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	printf("Deleting %d line\n", y);
}

void	ft_draw_map(t_wdata *mlx)
{
	t_plist	*tmp;
	t_plist	*nxt;
	t_plist	*lst;
	int	y;

	lst = *mlx->pix;
	if (!lst || !lst->next)
		return ;
	nxt = lst->next;
	y = lst->pix->y;
	while (nxt)
	{
		printf("x: %d, y: %d, z: %d ", lst->pix->x, lst->pix->y, lst->pix->z);
		printf(" dx: %d, dy: %d, dz: %d ", lst->pix->x - nxt->pix->x, lst->pix->y - nxt->pix->y, lst->pix->z - nxt->pix->z);
		if (lst->pix->y != y)
			break ;
		if (nxt->pix->y == lst->pix->y)		
			ft_draw_line(mlx->img, lst->pix, nxt->pix, lst->pix->color);
		tmp = ft_findlst(lst, lst->pix->x, lst->pix->y + 50);
		printf("Here is the tmp %p\n", (void *) tmp);
		if (tmp)
			ft_draw_line(mlx->img, lst->pix, tmp->pix, lst->pix->color);
		lst = lst->next;
		nxt = lst->next;
	}
	ft_clear_pline(mlx->pix);
	printf("End of line........................\n");
}
