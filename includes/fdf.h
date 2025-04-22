/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:16:20 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/18 12:29:06 by haykharu         ###   ########.fr       */
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
# ifndef WIN_M_W
#  define WIN_M_W 100
# endif
# ifndef WIN_M_H
#  define WIN_M_H 20
# endif
# ifndef SCALE
#  define SCALE 10
# endif
# ifndef L_ARROW
#  define L_ARROW 65361
# endif
# ifndef U_ARROW
#  define U_ARROW 65362
# endif
# ifndef R_ARROW
#  define R_ARROW 65363
# endif
# ifndef D_ARROW
#  define D_ARROW 65364
# endif
# ifndef ESC
#  define ESC 65307
# endif

t_wdata	*ft_initmlx(void);
t_idata	*ft_create_image(t_wdata *mlx);
void	ft_addm_pix(t_plist **plst, int xlen, int ylen);
void	*ft_free_mlx(t_wdata *mlx);
void	ft_draw_map(t_wdata *mlx);
void	ft_draw_line(t_wdata *mlx, t_pix *p1, t_pix *p2);
int		ft_draw_pixel(t_wdata *mlx, int x, int y, int color);
#endif
