#include "fdf.h"

void	ft_put_instructions(t_wdata *mlx)
{
	if (!mlx || !mlx->mlx_win)
		return ;
	mlx_string_put(mlx->mlx, mlx->mlx_win, 20, WIN_M_H, 0xFFFFFF, "Keycodes:");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 30, WIN_M_H + 15, 0xFFFFFF, "<- / -> : Move Left and Right");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 30, WIN_M_H + 30, 0xFFFFFF, "Scrool + / - : Zoom In / out");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 30, WIN_M_H + 45, 0xFFFFFF, "U / J : Rotate around X-axis");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 30, WIN_M_H + 60, 0xFFFFFF, "I / K : Rotate around Y-axis");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 30, WIN_M_H + 75, 0xFFFFFF, "O / L : Rotate around Z-axis");
	mlx_string_put(mlx->mlx, mlx->mlx_win, 30, WIN_M_H + 90, 0xFFFFFF, "ESC : Exit the window");
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
	if (key == LEFT_ARROW)
		ft_move_x(mlx, 1);
	else if (key == RIGHT_ARROW)
		ft_move_x(mlx, -1);
	else if (key == UP_ARROW)
		ft_move_y(mlx, 1);
	else if (key == DOWN_ARROW)
		ft_move_y(mlx, -1);
	else if (key == U_ARROW)
		ft_rotate_axis(mlx, 0.1, 0);
	else if (key == I_ARROW)
		ft_rotate_axis(mlx, 0.1, 1);
	else if (key == O_ARROW)
		ft_rotate_axis(mlx, 0.1, 2);
	else if (key == J_ARROW)
		ft_rotate_axis(mlx, -0.1, 0);
	else if (key == K_ARROW)
		ft_rotate_axis(mlx, -0.1, 1);
	else if (key == L_ARROW)
		ft_rotate_axis(mlx, -0.1, 2);
	else if (key == ESC)
		ft_free_mlx(mlx);
	return (0);
}
