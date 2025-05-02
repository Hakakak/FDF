/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:16:20 by haykharu          #+#    #+#             */
/*   Updated: 2025/05/01 19:32:11 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "fdf_types.h"
# include "mlx.h"
# include "mlx_int.h"
# include <stdio.h>
# include <math.h>
# include <errno.h>
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
# define R_KEY 114
# define U_KEY 117
# define J_KEY 106
# define I_KEY 105
# define K_KEY 107
# define O_KEY 111
# define L_KEY 108
# define LEFT_ARROW 65361
# define UP_ARROW 65362
# define RIGHT_ARROW 65363
# define DOWN_ARROW 65364
# define ESC 65307

t_wdata	*ft_initmlx(void);
t_idata	*ft_create_image(t_wdata *mlx);
void	ft_addm_pix(t_wdata *mlx, int xlen, int ylen);
void	ft_draw_map(t_wdata *mlx);
void	ft_draw_line(t_wdata *mlx, t_pix *p1, t_pix *p2);
int		ft_free_mlx(t_wdata *mlx);
#endif
