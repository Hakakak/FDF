/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:31:40 by haykharu          #+#    #+#             */
/*   Updated: 2025/05/01 19:37:43 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_free_mlx(t_wdata *mlx)
{
	if (!mlx)
		return (0);
	if (mlx->img)
	{
		mlx_destroy_image(mlx->mlx, mlx->img->img);
		free(mlx->img);
	}
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	if (mlx->pix)
	{
		ft_plstclear(mlx->pix);
		free(mlx->pix);
	}
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	free(mlx);
	return (exit(0), 0);
}

t_idata	*ft_create_image(t_wdata *mlx)
{
	t_idata	*img;

	if (!mlx)
		return (NULL);
	if (mlx->img)
	{
		mlx_destroy_image(mlx->mlx, mlx->img->img);
		free(mlx->img);
	}
	img = (t_idata *) malloc(sizeof(t_idata));
	if (!img)
		return (ft_put_error("Can't Init", 1, mlx), NULL);
	img->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->linel, &img->end);
	mlx->img = img;
	return (img);
}

t_wdata	*ft_initmlx(void)
{
	t_wdata	*mlx;
	t_idata	*img;

	mlx = (t_wdata *) malloc(sizeof(t_wdata));
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "FDF!");
	img = (t_idata *) malloc(sizeof(t_idata));
	if (!img)
		return (ft_put_error("Can't Init", 1, mlx), NULL);
	img->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->linel, &img->end);
	mlx->img = img;
	mlx->pix = (t_plist **) malloc(sizeof(t_plist *));
	if (!mlx->pix)
		return (ft_put_error("Can't Init", 1, mlx), NULL);
	*(mlx->pix) = NULL;
	mlx->xlen = 0;
	mlx->ylen = 0;
	mlx_hook(mlx->mlx_win, 2, 1L << 0, ft_hook_keys, (void *) mlx);
	mlx_hook(mlx->mlx_win, 4, 1L << 2, ft_mouse_keys, (void *) mlx);
	mlx_hook(mlx->mlx_win, 17, 0, ft_free_mlx, (void *) mlx);
	mlx_loop_hook(mlx->mlx, ft_hook_keys, (void *) mlx);
	return (mlx);
}
