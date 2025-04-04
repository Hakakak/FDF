/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:15:17 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/04 12:20:43 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	t_wdata	*mlx;
	int i;

	(void) ac;
	mlx = ft_initmlx();
	if (!mlx)
		return (0);
	printf("Initializing.....................\n");
	i = ft_fill_map(av[1], mlx);
	printf("Filled the map................... %d\n", i);
//	t_plist *bruh;
//	bruh = *mlx->pix;
//	printf("X: , Y:, Z:\n");
//	i = 0;
//	while (bruh)
//	{
//		++i;
//		if (bruh->next)
//		{
//			if (bruh->pix->color == 0)
//				bruh->pix->color = 0xFFFFFFFF;
//			if (bruh->next->pix->y == bruh->pix->y)
//				ft_draw_line(mlx->img, bruh->pix, bruh->next->pix, bruh->pix->color);
//			t_plist *tmp;
//			tmp = ft_findlst(bruh, bruh->pix->x, bruh->pix->y + 20);
//			if (tmp)
//				ft_draw_line(mlx->img, bruh->pix, tmp->pix, bruh->pix->color);
//		}
////		printf("x: %d, y: %d, z: %+d, color: %x\n", bruh->pix->x, bruh->pix->y, bruh->pix->z, bruh->pix->color);
//		bruh = bruh->next;
//	}
	mlx_loop(mlx->mlx);
	exit(0);
	return 0;
}
