/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:52:59 by haykharu          #+#    #+#             */
/*   Updated: 2025/05/01 19:17:05 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_add_rgb(t_wdata *mlx)
{
	t_plist	*tmp;

	if (!mlx || !mlx->pix)
		return ;
	tmp = *mlx->pix;
	while (tmp)
	{
		ft_pix_addnxt(tmp->pix);
		tmp = tmp->next;
	}
	ft_draw_map(mlx);
}

void	ft_set_steps(double *d, double dx, double dy)
{
	if (*d > 0)
		*d += (2 * (dx - dy));
	else
		*d += 2 * dx;
}

void	ft_rotate_x(t_pix *pix, float angle)
{
	double	ty;

	if (!pix)
		return ;
	ty = pix->y;
	pix->y = pix->y * cos(angle) - pix->z * sin(angle);
	pix->z = ty * sin(angle) + pix->z * cos(angle);
}

void	ft_rotate_y(t_pix *pix, float angle)
{
	double	tx;

	if (!pix)
		return ;
	tx = pix->x;
	pix->x = pix->x * cos(angle) + pix->z * sin(angle);
	pix->z = -tx * sin(angle) + pix->z * cos(angle);
}

void	ft_rotate_z(t_pix *pix, float angle)
{
	double	tx;

	if (!pix)
		return ;
	tx = pix->x;
	pix->x = pix->x * cos(angle) - pix->y * sin(angle);
	pix->y = tx * sin(angle) + pix->y * cos(angle);
}
