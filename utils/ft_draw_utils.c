/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:01:25 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/22 18:45:17 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check_bound(t_plist *lst, int less, int chkx, int chky)
{
	int	x;
	int	y;

	while (lst)
	{
		x = lst->pix->x;
		y = lst->pix->y;
		if (less && chkx && x < -5)
			return (0);
		if (!less && chkx && x > WIN_W + 5)
			return (0);
		if (less && chky && y < -5)
			return (0);
		if (!less && chky && y > WIN_H + 5)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_scale_map(t_wdata *mlx, int dir)
{
	t_plist	*tmp;

	if (!mlx || !mlx->pix)
		return ;
	if (dir == 1)
	{
		tmp = *mlx->pix;
		while (tmp)
		{
			tmp->pix->x *= 0.9f;
			tmp->pix->y *= 0.9f;
			tmp = tmp->next;
		}
	}
	else if (dir == -1)
	{
		tmp = *mlx->pix;
		while (tmp)
		{
			tmp->pix->x *= 1.1f;
			tmp->pix->y *= 1.1f;
			tmp = tmp->next;
		}
	}
	ft_draw_map(mlx);
}

void	ft_move_y(t_wdata *mlx, int dir)
{
	t_plist	*tmp;

	if (!mlx || !mlx->pix)
		return ;
	tmp = *mlx->pix;
	if (dir == 1)
	{
		if (!ft_check_bound(tmp, 1, 0, 1))
			return ;
	}
	else if (dir == -1)
	{
		if (!ft_check_bound(tmp, 0, 0, 1))
			return ;
	}
	while (tmp)
	{
		tmp->pix->y -= dir;
		tmp = tmp->next;
	}
	ft_draw_map(mlx);
}

void	ft_move_x(t_wdata *mlx, int dir)
{
	t_plist	*tmp;

	if (!mlx || !mlx->pix)
		return ;
	tmp = *mlx->pix;
	if (dir == 1)
	{
		if (!ft_check_bound(tmp, 1, 1, 0))
			return ;
	}
	else if (dir == -1)
	{
		if (!ft_check_bound(tmp, 0, 1, 0))
			return ;
	}
	while (tmp)
	{
		tmp->pix->x -= dir;
		tmp = tmp->next;
	}
	ft_draw_map(mlx);
}

void	ft_rotate_axis(t_wdata *mlx, float angle, int axis)
{
	t_plist	*tmp;
	t_pix	tpix;

	if (!mlx || !mlx->pix)
		return ;
	tmp = *mlx->pix;
	if (axis == 0)
	{
		while (tmp)
		{
			tpix.y = tmp->pix->y;
			tmp->pix->y = tmp->pix->y * cos(angle) - tmp->pix->z * sin(angle);
			tmp->pix->z = tpix.y * sin(angle) + tmp->pix->z * cos(angle);
			tmp = tmp->next;
		}
	}
	else if (axis == 1)
	{
		while (tmp)
		{
			tpix.x = tmp->pix->x;
			tmp->pix->x = tmp->pix->x * cos(angle) + tmp->pix->z * sin(angle);
			tmp->pix->z = -tpix.x * sin(angle) + tmp->pix->z * cos(angle);
			tmp = tmp->next;
		}
	}
	else if (axis == 2)
	{
		while (tmp)
		{
			tpix.x = tmp->pix->x;
			tmp->pix->x = tmp->pix->x * cos(angle) - tmp->pix->y * sin(angle);
			tmp->pix->y = tpix.x * sin(angle) + tmp->pix->y * cos(angle);
			tmp = tmp->next;
		}
	}
	ft_draw_map(mlx);
}
