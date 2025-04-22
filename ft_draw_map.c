/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:19:17 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/22 18:36:57 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_adda_pix(t_plist **plst)
{
	t_plist	*tmp;
	double	x;
	double	y;

	if (!plst || !*plst)
		return ;
	tmp = *plst;
	while (tmp)
	{
		x = tmp->pix->x;
		y = tmp->pix->y;
		tmp->pix->x = (x - y) * cos(0.5235);
		tmp->pix->y = (x + y) * sin(0.5235) - tmp->pix->z * sqrt(SCALE);
		printf("(x: %f, y: %f) ", tmp->pix->x, tmp->pix->y);
		tmp = tmp->next;
	}
	printf("\n");
}

void	ft_addm_pix(t_plist **plst, int xlen, int ylen)
{
	t_plist	*tmp;
	int		real_w;
	int		real_h;

	if (!plst || !*plst)
		return ;
	if (xlen <= 0 || ylen <= 0)
		return ;
	tmp = *plst;
	real_w = WIN_W - WIN_M_W * 2;
	real_h = WIN_H - WIN_M_H * 2;
	while (tmp)
	{
		tmp->pix->x *= real_w / (xlen + 2);
		tmp->pix->y *= real_h / (ylen + 2);
		tmp = tmp->next;
	}
	ft_adda_pix(plst);
	tmp = *plst;
	while (tmp)
	{
		tmp->pix->x += (real_w - real_w / (xlen + 2) * xlen) / 2;
		tmp->pix->y += (real_h - real_h / (ylen + 2) * ylen) / 2;
		tmp = tmp->next;
	}
}

void	ft_draw_map(t_wdata *mlx)
{
	t_plist	*nxt;
	t_plist	*lst;
	t_plist	*tmp;
	int		count;

	lst = *mlx->pix;
	if (!lst || !lst->next)
		return ;
	mlx->img = ft_create_image(mlx);
	nxt = lst->next;
	count = 1;
	while (nxt)
	{
		tmp = ft_lstfind_nxty(lst, mlx->xlen);
		if (tmp)
			ft_draw_line(mlx, lst->pix, tmp->pix);
		if (count < mlx->xlen)
			ft_draw_line(mlx, lst->pix, nxt->pix);
		else
			count = 0;
		lst = lst->next;
		nxt = lst->next;
		++count;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img, 0, 0);
}
