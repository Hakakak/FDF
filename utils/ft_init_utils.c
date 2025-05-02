/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 09:56:29 by haykharu          #+#    #+#             */
/*   Updated: 2025/05/01 19:28:57 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_error(char *msg, int type, t_wdata *mlx)
{
	char	*tmp;

	if (type == 2)
	{
		ft_printf("%s\n", msg);
		tmp = strerror(errno);
		ft_putstr_fd(tmp, 2);
		ft_putstr_fd("\n", 2);
	}
	else
		ft_printf("%s\n", msg);
	ft_free_mlx(mlx);
}

void	ft_put_instructions(t_wdata *mlx)
{
	void	*mlxp;
	void	*win;
	int		color;

	if (!mlx || !mlx->mlx_win)
		return ;
	mlxp = mlx->mlx;
	win = mlx->mlx_win;
	color = 0xFFFFFF;
	mlx_string_put(mlxp, win, 20, 20, color, "Keycodes:");
	mlx_string_put(mlxp, win, 30, 35, color, "<- / -> : Move Left or Right");
	mlx_string_put(mlxp, win, 30, 50, color, "Scroll + / - : Zoom In / out");
	mlx_string_put(mlxp, win, 30, 65, color, "U / J : Rotate around X-axis");
	mlx_string_put(mlxp, win, 30, 80, color, "I / K : Rotate around Y-axis");
	mlx_string_put(mlxp, win, 30, 95, color, "O / L : Rotate around Z-axis");
	mlx_string_put(mlxp, win, 30, 110, color, "R : For Rainbow color change");
	mlx_string_put(mlxp, win, 30, 125, color, "ESC : Exit the window");
}

int	ft_mouse_keys(int key, int x, int y, void *mlx_t)
{
	t_wdata	*mlx;

	mlx = (t_wdata *) mlx_t;
	if (!mlx)
		return (0);
	x = 0;
	y = 0;
	if (key == 4)
		ft_scale_map(mlx, -1);
	else if (key == 5)
		ft_scale_map(mlx, 1);
	return (0);
}

int	ft_hook_keys2(int key, void *mlx_t)
{
	t_wdata	*mlx;

	mlx = (t_wdata *) mlx_t;
	if (!mlx)
		return (0);
	if (key == U_KEY)
		ft_rotate_axis(mlx, 0.1, 0);
	else if (key == I_KEY)
		ft_rotate_axis(mlx, 0.05, 1);
	else if (key == O_KEY)
		ft_rotate_axis(mlx, 0.05, 2);
	else if (key == J_KEY)
		ft_rotate_axis(mlx, -0.1, 0);
	else if (key == K_KEY)
		ft_rotate_axis(mlx, -0.05, 1);
	else if (key == L_KEY)
		ft_rotate_axis(mlx, -0.05, 2);
	else if (key == R_KEY)
		ft_add_rgb(mlx);
	return (0);
}

int	ft_hook_keys(int key, void *mlx_t)
{
	t_wdata	*mlx;

	mlx = (t_wdata *) mlx_t;
	if (!mlx)
		return (0);
	if (key == LEFT_ARROW)
		ft_move_x(mlx, 1);
	else if (key == RIGHT_ARROW)
		ft_move_x(mlx, -1);
	else if (key == UP_ARROW)
		ft_move_y(mlx, 1);
	else if (key == DOWN_ARROW)
		ft_move_y(mlx, -1);
	else if (key == ESC)
		ft_free_mlx(mlx);
	return (ft_hook_keys2(key, mlx_t));
}
