/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:18:31 by haykharu          #+#    #+#             */
/*   Updated: 2025/02/10 15:41:39 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_int(int nbr, int fd)
{
	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2", fd);
		return (147483648);
	}
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		return (nbr * -1);
	}
	return (nbr);
}

void	ft_putnbr_fd(int nb, int fd)
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
		ft_putchar_fd(nb / (ft_raise(10, i - 1)) + '0', fd);
		nb = nb % ft_raise(10, i - 1);
		--i;
	}
	ft_putchar_fd(nb + '0', fd);
}
