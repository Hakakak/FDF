/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:19:17 by haykharu          #+#    #+#             */
/*   Updated: 2025/05/01 19:30:50 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_add_rotation(t_wdata *mlx)
{
	t_plist	*tmp;

	ft_rotate_axis(mlx, 1.18, 0);
	ft_rotate_axis(mlx, 0.88, 1);
	ft_rotate_axis(mlx, -0.2, 2);
	tmp = *mlx->pix;
	while (tmp)
	{
		tmp->pix->y += (WIN_H - WIN_M_H * 2) / 2;
		tmp = tmp->next;
	}
}

void	ft_addm_pix(t_wdata *mlx, int xlen, int ylen)
{
	t_plist	*tmp;
	int		real_w;
	int		real_h;

	if (!mlx || !mlx->pix)
		return ;
	if (xlen <= 0 || ylen <= 0)
		return ;
	tmp = *mlx->pix;
	real_w = WIN_W - WIN_M_W * 2;
	real_h = WIN_H - WIN_M_H * 2;
	while (tmp)
	{
		tmp->pix->x *= real_w / (xlen + 2);
		tmp->pix->y *= real_h / (ylen + 2);
		tmp->pix->z *= (real_h / (xlen + xlen));
		tmp = tmp->next;
	}
	ft_add_rotation(mlx);
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
		if (count++ < mlx->xlen)
			ft_draw_line(mlx, lst->pix, nxt->pix);
		else
			count = 1;
		lst = lst->next;
		nxt = lst->next;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img->img, 0, 0);
	ft_put_instructions(mlx);
}
