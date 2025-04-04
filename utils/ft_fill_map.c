/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:49:31 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/04 13:10:03 by haykharu         ###   ########.fr       */
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
			tmp = 0;
		tmp += 0xFF000000;
	}
	return (tmp);
}

static t_plist	*ft_newplist(int x, int y, int z, int color)
{
	t_plist	*tmp;
	t_pix	*tmp_p;

	tmp_p = (t_pix *) malloc(sizeof(t_pix));
	if (!tmp_p)
		return (NULL);
	tmp_p->x = x;
	tmp_p->y = y;
	tmp_p->z = z;
	tmp_p->color = color;
	printf("Init: x: %d, y: %d , z: %d, color: %d\n", x, y, z, color);
	tmp = ft_plstnew(tmp_p);
	if (!tmp)
	{
		free(tmp_p);
		return (NULL);
	}
	return (tmp);
}

static void	ft_get_map(char *str, t_plist **arr, size_t y)
{
	size_t	x;
	t_plist	*tmp;

	x = 0;
	while (str && *str != '\0')
	{
		if ((*str >= '0' && *str <= '9') || *str == '-')
		{
			tmp = ft_newplist(x, y, ft_atoi(str), ft_get_num(str));
			if (!tmp)
				return ;
			while (*str && *str != '\n' && *str != ' ')
				++str;
			ft_plstadd_b(arr, tmp);
			++x;
		}
		++str;
	}
}

int	ft_fill_map(char *f_name, t_wdata *mlx)
{
	int		fd;
	char	*tmp;
	size_t	y;

	fd = open(f_name, O_RDONLY);
	if (!fd)
		return (0);
	tmp = get_next_line(fd);
	if (!tmp)
		return (-1);
	y = 0;
	while (tmp)
	{
		ft_get_map(tmp, mlx->pix, y);
		free(tmp);
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (y)
			ft_draw_map(mlx);
		++y;
	}
	printf("The last time!!!\n");
	ft_draw_map(mlx);
	return (1);
}
