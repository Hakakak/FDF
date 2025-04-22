/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:31:40 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/22 18:36:35 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_free_mlx(t_wdata *mlx)
{
	if (!mlx)
		return (NULL);
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
	return (exit(0), NULL);
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
		return (ft_free_mlx(mlx));
	img->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->linel, &img->end);
	mlx->img = img;
	return (img);
}

int	ft_mouse_keys(int key, int x, int y, void *mlx_t)
{
	t_wdata	*mlx;

	mlx = (t_wdata *) mlx_t;
	if (!mlx)
		return (0);
	x = 0;
	y = 0;
	printf("Scroolll!!!!!!! key: %d\n", key);
	if (key == 4)
		ft_scale_map(mlx, -1);
	else if (key == 5)
		ft_scale_map(mlx, 1);
	return (0);
}

int	ft_hook_keys(int key, void *mlx_t)
{
	t_wdata	*mlx;

	mlx = (t_wdata *) mlx_t;
	if (!mlx || key == 144)
		return (0);
	printf("Keyboard!!!!!!!! key: %d\n", key);
	if (key == L_ARROW)
		ft_move_x(mlx, 1);
	else if (key == R_ARROW)
		ft_move_x(mlx, -1);
	else if (key == U_ARROW)
		ft_move_y(mlx, 1);
	else if (key == D_ARROW)
		ft_move_y(mlx, -1);
	else if (key == ESC)
		ft_free_mlx(mlx);
	return (0);
}

t_wdata	*ft_initmlx(void)
{
	t_wdata	*mlx;
	t_idata	*img;

	mlx = (t_wdata *) malloc(sizeof(t_wdata));
	if (!mlx)
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "Test!");
	img = (t_idata *) malloc(sizeof(t_idata));
	if (!img)
		return (ft_free_mlx(mlx));
	img->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits, &img->linel, &img->end);
	mlx->img = img;
	mlx->pix = (t_plist **) malloc(sizeof(t_plist *));
	if (!mlx->pix)
		return (ft_free_mlx(mlx));
	*(mlx->pix) = NULL;
	mlx->xlen = 0;
	mlx->ylen = 0;
	mlx_hook(mlx->mlx_win, 2, 1L << 0, ft_hook_keys, (void *) mlx);
	mlx_hook(mlx->mlx_win, 4, 1L << 2, ft_mouse_keys, (void *) mlx);
	mlx_loop_hook(mlx->mlx, ft_hook_keys, (void *) mlx);
	return (mlx);
}
