/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:49:31 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/18 15:24:08 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_get_num(char *str)
{
	int	tmp;

	if (!str)
		return (0);
	tmp = 0xFFFFFFFF;
	while (*str >= '0' && *str <= '9')
		++str;
	if (*str == ',')
	{
		tmp = ft_hex_to_nbr(++str);
		if (tmp < 0)
			tmp = 0x00FFFFFF;
		tmp += 0xFF000000;
	}
	return (tmp);
}

static t_plist	*ft_newplist(size_t x, size_t y, int z, int color)
{
	t_plist	*tmp;
	t_pix	*tmp_p;

	tmp_p = (t_pix *) malloc(sizeof(t_pix));
	if (!tmp_p)
		return (NULL);
	tmp_p->x = x;
	tmp_p->y = y;
	tmp_p->z = z * 4;
	tmp_p->color = color;
	tmp = ft_plstnew(tmp_p);
	if (!tmp)
	{
		free(tmp_p);
		return (NULL);
	}
	return (tmp);
}

static int	ft_get_map(char *str, t_plist **arr, size_t y)
{
	int		x;
	t_plist	*tmp;

	if (!str)
		return (0);
	x = 0;
	while (*str != '\0')
	{
		if ((*str >= '0' && *str <= '9') || *str == '-')
		{
			tmp = ft_newplist(x, y, ft_atoi(str), ft_get_num(str));
			if (!tmp)
				return (-1);
			while (*str != '\0' && *str != '\n' && *str != ' ')
				++str;
			ft_plstadd_b(arr, tmp);
			++x;
		}
		if (*str != '\0')
			++str;
	}
	return (x);
}

int	ft_check_fd(char *f_name)
{
	int	fd;

	fd = open(f_name, O_RDONLY);
	if (fd <= 0)
		return (-1);
	return (fd);
}

int	ft_fill_map(char *f_name, t_wdata *mlx)
{
	int		fd;
	int		x;
	char	*tmp;
	size_t	y;

	fd = ft_check_fd(f_name);
	tmp = get_next_line(fd);
	if (!tmp)
		return (-1);
	y = 0;
	while (tmp)
	{
		x = ft_get_map(tmp, mlx->pix, y);
		if (!mlx->xlen)
			mlx->xlen = x;
		free(tmp);
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		++y;
	}
	mlx->ylen = y;
	ft_addm_pix(mlx->pix, mlx->xlen, mlx->ylen);
	ft_draw_map(mlx);
	return (1);
}
