/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:13:55 by haykharu          #+#    #+#             */
/*   Updated: 2025/05/01 19:32:00 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_grad(int c1, int c2, float ratio)
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

static int	ft_draw_pixel(t_wdata *mlx, int x, int y, int color)
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

static void	ft_line_high(t_wdata *mlx, t_pix *p1, t_pix *p2)
{
	double	x;
	double	y;
	double	d[3];
	int		xi;
	int		color;

	d[1] = p2->x - p1->x;
	d[2] = p2->y - p1->y;
	xi = 1;
	if (d[1] < 0)
	{
		xi = -1;
		d[1] *= -1;
	}
	d[0] = (2 * d[1]) - d[2];
	x = p1->x;
	y = p1->y;
	while (y <= p2->y)
	{
		color = ft_get_grad(p2->color, p1->color, (float)(p2->y - y) / d[2]);
		ft_draw_pixel(mlx, x, y++, color);
		if (d[0] > 0)
			x += xi;
		ft_set_steps(&d[0], d[1], d[2]);
	}
}

static void	ft_line_low(t_wdata *mlx, t_pix *p1, t_pix *p2)
{
	double	x;
	double	y;
	double	d[3];
	int		yi;
	int		color;

	d[1] = p2->x - p1->x;
	d[2] = p2->y - p1->y;
	yi = 1;
	if (d[2] < 0)
	{
		yi = -1;
		d[2] *= -1;
	}
	x = p1->x;
	y = p1->y;
	d[0] = (2 * d[2]) - d[1];
	while (x <= p2->x)
	{
		color = ft_get_grad(p2->color, p1->color, (float)(p2->x - x) / d[1]);
		ft_draw_pixel(mlx, x++, y, color);
		if (d[0] > 0)
			y += yi;
		ft_set_steps(&d[0], d[2], d[1]);
	}
}

void	ft_draw_line(t_wdata *mlx, t_pix *p1, t_pix *p2)
{
	if (fabs(p2->y - p1->y) < fabs(p2->x - p1->x))
	{
		if (p1->x > p2->x)
			ft_line_low(mlx, p2, p1);
		else
			ft_line_low(mlx, p1, p2);
	}
	else
	{
		if (p1->y > p2->y)
			ft_line_high(mlx, p2, p1);
		else
			ft_line_high(mlx, p1, p2);
	}
}
