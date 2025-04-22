/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:13:55 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/22 19:01:22 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_gradient(int c1, int c2, float ratio)
{
	int	rgb1[3];
	int	rgb2[3];
	int	res[3];

	rgb1[0] = (c1 >> 16) & 0xFF;
	rgb1[1] = (c1 >> 8) & 0xFF;
	rgb1[2] = c1 & 0xFF;
	rgb2[0] = (c2 >> 16) & 0xFF;
	rgb2[1] = (c2 >> 8) & 0xFF;
	rgb2[2] = c2 & 0xFF;
	res[0] = rgb1[0] + (int)((rgb2[0] - rgb1[0]) * ratio);
	res[1] = rgb1[1] + (int)((rgb2[1] - rgb1[1]) * ratio);
	res[2] = rgb1[2] + (int)((rgb2[2] - rgb1[2]) * ratio);
	return ((res[0] << 16) | (res[1] << 8) | res[2]);
}

int	ft_draw_pixel(t_wdata *mlx, int x, int y, int color)
{
	int	i;

	if (x >= 0 && y >= 0 && x < WIN_W && y < WIN_H)
	{
		i = (y * mlx->img->linel + x * (mlx->img->bits / 8));
		mlx->img->addr[i] = color;
		mlx->img->addr[++i] = color >> 8;
		mlx->img->addr[++i] = color >> 16;
	}
	return (0);
}

void	ft_line_high(t_wdata *mlx, t_pix *p1, t_pix *p2, double x, double y)
{
	double	dx;
	double	dy;
	double	d;
	int		xi;
	int		color;

	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx *= -1;
	}
	d = (2 * dx) - dy;
	y = p1->y;
	x = p1->x;
	while (y <= p2->y)
	{
		color = ft_get_gradient(p2->color, p1->color, (float)(p2->y - y) / dy);
		ft_draw_pixel(mlx, x, y, color);
		if (d > 0)
		{
			x = x + xi;
			d += (2 * (dx - dy));
		}
		else
			d += 2 * dx;
		++y;
	}
}

void	ft_line_low(t_wdata *mlx, t_pix *p1, t_pix *p2, double x, double y)
{
	double	dx;
	double	dy;
	double	d;
	int		yi;
	int		color;

	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy *= -1;
	}
	d = (2 * dy) - dx;
	y = p1->y;
	x = p1->x;
	while (x <= p2->x)
	{
		color = ft_get_gradient(p2->color, p1->color, (float)(p2->x - x) / dx);
		ft_draw_pixel(mlx, x, y, color);
		if (d > 0)
		{
			y = y + yi;
			d += (2 * (dy - dx));
		}
		else
			d += 2 * dy;
		++x;
	}
}

void	ft_draw_line(t_wdata *mlx, t_pix *p1, t_pix *p2)
{
	if (fabs(p2->y - p1->y) < fabs(p2->x - p1->x))
	{
		if (p1->x > p2->x)
			ft_line_low(mlx, p2, p1, 0, 0);
		else
			ft_line_low(mlx, p1, p2, 0, 0);
	}
	else
	{
		if (p1->y > p2->y)
			ft_line_high(mlx, p2, p1, 0, 0);
		else
			ft_line_high(mlx, p1, p2, 0, 0);
	}
}
