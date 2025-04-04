/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:58:18 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/02 14:42:48 by haykharu         ###   ########.fr       */
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

static int	ft_numlenf(size_t a)
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

static int	ft_gethex(int i)
{
	char	*s;

	s = "0123456789abcdef";
	return (s[i]);
}

void	ft_putptr_fd(void *ptr, int fd)
{
	int		c;
	int		nbr;
	size_t	frac;
	size_t	nb;

	ft_putstrc_fd("0x", fd);
	nb = (size_t) ptr;
	if (!nb && !ft_countc_fd('0', fd, 0))
		return ;
	c = ft_numlenf(nb);
	if (c == 17)
		--c;
	nbr = 1;
	while (c >= 1)
	{
		frac = ((nb / ft_uraise(16, c - 1))) % 16;
		if (ft_gethex(frac) != '0')
			nbr = 0;
		if (ft_gethex(frac) != '0')
			ft_countc_fd(ft_gethex(frac), fd, 0);
		else if (!nbr && ft_gethex(frac) == '0')
			ft_countc_fd(ft_gethex(frac), fd, 0);
		--c;
	}
}
