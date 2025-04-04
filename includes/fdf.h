/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:16:20 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/04 12:54:46 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include "fdf_types.h"
# include "mlx_int.h"
# include <stdio.h>
# include <math.h>
# ifndef WIN_W
#  define WIN_W 1920
# endif
# ifndef WIN_H
#  define WIN_H 1080
# endif


t_wdata	*ft_initmlx(void);
void	*ft_free_mlx(t_wdata *mlx);
void	ft_draw_map(t_wdata *mlx);
void	ft_draw_pixel(t_idata *img, int x, int y, int color);
void	ft_draw_line(t_idata *img, t_pix *p1, t_pix *p2, int color);
#endif
