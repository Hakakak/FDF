/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:15:17 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/18 15:28:59 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check_fname(char **av)
{
	char	*tmp;

	if (!av || !av[1])
		return (0);
	tmp = ft_strrchr(av[1], '.');
	if (tmp && !ft_strcmp(tmp, ".fdf"))
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_wdata	*mlx;

	if (ac != 2 || !ft_check_fname(av))
	{
		ft_printf("Usage: ./fdf <filename.fdf>\n");
		return (0);
	}
	printf("Initializing.....................\n");
	mlx = ft_initmlx();
	if (!mlx)
		return (0);
	printf("mlx: %s, mlx->img: %s\n", mlx ? "OK!" : "KO!", mlx->img ? "OK!" : "KO!");
	printf("Filling.....................\n");
	ft_fill_map(av[1], mlx);
	printf("Filled......................\n");
	printf("mlx->pix: %s\n", mlx->pix ? "OK!" : "KO!");
	printf("*mlx->pix: %s\n", *(mlx->pix) ? "OK!" : "KO!");
	mlx_loop(mlx->mlx);
	return (0);
}
