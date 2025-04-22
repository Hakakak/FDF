/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:39:22 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/18 13:08:04 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TYPES_H
# define FDF_TYPES_H

typedef struct s_pix
{
	double	x;
	double	y;
	int		z;
	int		color;
}				t_pix;

typedef struct s_plist
{
	t_pix			*pix;
	struct s_plist	*next;
}				t_plist;

typedef struct s_idata
{
	void	*img;
	char	*addr;
	int		bits;
	int		linel;
	int		end;
}				t_idata;

typedef struct s_wdata
{
	void	*mlx;
	void	*mlx_win;
	int		xlen;
	int		ylen;
	t_idata	*img;
	t_plist	**pix;
}				t_wdata;

void	ft_rotate(t_pix **pix, float angle, int dir);
void	ft_scale_map(t_wdata *mlx, int dir);
void	ft_move_x(t_wdata *mlx, int dir);
void	ft_move_y(t_wdata *mlx, int dir);
int		ft_fill_map(char *t_name, t_wdata *mlx);
t_plist	*ft_lstfind_nxty(t_plist *lst, int xlen);
t_plist	*ft_plstlast(t_plist *lst);
t_plist	*ft_plstnew(t_pix *pix);
void	ft_plstclear(t_plist **lst);
size_t	ft_plstsize(t_plist *lst);
void	ft_plstadd_f(t_plist **lst, t_plist *new);
void	ft_plstadd_b(t_plist **lst, t_plist *new);
#endif
