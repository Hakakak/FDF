/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:31:40 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/03 12:04:10 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_free_mlx(t_wdata *mlx)
{
	t_plist	*tmp;

	if (mlx->mlx)
		free(mlx->mlx);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img->img);
	tmp = *mlx->pix;
	while (tmp)
	{
		free((*mlx->pix)->pix);
		free(*mlx->pix);
		*mlx->pix = tmp->next;
	}
	return (NULL);
}

t_wdata	*ft_initmlx()
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
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, 0, 0);
	mlx->pix = (t_plist **) malloc(sizeof(t_plist *));
	if (!mlx->pix)
		return (ft_free_mlx(mlx));
	*(mlx->pix) = NULL;
	return (mlx);
}
