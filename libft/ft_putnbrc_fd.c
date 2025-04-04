/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrc_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:35:03 by haykharu          #+#    #+#             */
/*   Updated: 2025/03/26 14:12:01 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_int(int nbr, int fd)
{
	if (nbr == -2147483648)
	{
		ft_putstrc_fd("-2", fd);
		return (147483648);
	}
	if (nbr < 0)
	{
		ft_countc_fd('-', fd, 0);
		return (nbr * -1);
	}
	return (nbr);
}

static void	ft_putnbrp_fd(int nb, int fd)
{
	int	i;
	int	f;

	nb = handle_int(nb, fd);
	i = 1;
	f = nb;
	while (f >= 10)
	{
		f = f / 10;
		++i;
	}
	while (i > 1)
	{
		ft_countc_fd(nb / (ft_raise(10, i - 1)) + '0', fd, 0);
		nb = nb % ft_raise(10, i - 1);
		--i;
	}
	ft_countc_fd(nb + '0', fd, 0);
}

static size_t	ft_uraise(int nbr, int power)
{
	size_t	res;

	res = 1;
	while (power >= 1)
	{
		res *= nbr;
		--power;
	}
	return (res);
}

static void	ft_putunbr_fd(size_t nb, int fd)
{
	int		i;
	size_t	tmp;

	i = 1;
	tmp = (size_t) nb;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		++i;
	}
	while (i > 1)
	{
		ft_countc_fd(nb / (ft_uraise(10, i - 1)) + '0', fd, 0);
		nb = nb % ft_uraise(10, i - 1);
		--i;
	}
	ft_countc_fd(nb + '0', fd, 0);
}

void	ft_putnbrc_fd(int in, size_t un, int mode, int fd)
{
	if (mode == 0)
		ft_putnbrp_fd(in, fd);
	else if (mode == 1)
		ft_putunbr_fd(un, fd);
}
