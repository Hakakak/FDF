/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:03:11 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/02 14:42:06 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	ft_numlenf(unsigned int a)
{
	int	i;

	i = 1;
	while (a >= 10)
	{
		a = a / 16;
		++i;
	}
	return (i);
}

static void	ft_convert_16(unsigned int nbr, int is_upper, int fd)
{
	char			*s;
	int				c;
	size_t			frac;
	unsigned int	nb;

	if (is_upper)
		s = "0123456789ABCDEF";
	else
		s = "0123456789abcdef";
	nb = (unsigned int) nbr;
	c = ft_numlenf(nb);
	nbr = 1;
	while (c >= 1)
	{
		frac = ((nb / ft_uraise(16, c - 1))) % 16;
		if (s[frac] != '0')
			nbr = 0;
		if (s[frac] != '0')
			ft_countc_fd(s[frac], fd, 0);
		else if (!nbr && s[frac] == '0')
			ft_countc_fd(s[frac], fd, 0);
		--c;
	}
}

void	ft_putnbr_hex_fd(int nbr, int is_upper, int hex, int fd)
{
	if (fd < 0)
		return ;
	if (nbr == 0 && !ft_countc_fd('0', fd, 0))
		return ;
	if (hex && nbr != 0 && !is_upper)
		ft_putstrc_fd("0x", fd);
	else if (hex && nbr != 0 && is_upper)
		ft_putstrc_fd("0X", fd);
	ft_convert_16(nbr, is_upper, fd);
}
