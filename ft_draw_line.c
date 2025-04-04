/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:13:55 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/04 12:59:38 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_pixel(t_idata *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->linel + x * (img->bits / 8));
	*(unsigned int *) dst = color;
}

void	ft_draw_line(t_idata *img, t_pix *p1, t_pix *p2, int color)
{
	int		dx;
	int		dy;
	int	xinc;
	int	yinc;
	int		steps;

	//printf("p1->x: %d, p1->y: %d\n", p1->x, p1->y);
	//printf("p2->x: %d, p2->y: %d\n", p2->x, p2->y);
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	xinc = dx / steps;
	yinc = dy / steps;
	int x = p1->x;
	int y = p1->y;
	//printf("Bruh: xinc: %f, yinc: %f\n", xinc, yinc);
	for (int i = 0; i <= steps; i++) {
		//	printf("%d ; %d\n", x, y);
		ft_draw_pixel(img, x, y, color);
		x += xinc;
		y += yinc;
	}
}
