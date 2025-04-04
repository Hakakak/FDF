/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:26:06 by haykharu          #+#    #+#             */
/*   Updated: 2025/03/26 14:10:55 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printnbr_sign_fd(int nbr, char sign, int fd)
{
	if (nbr >= 0 && (sign == '+' || sign == ' '))
		ft_countc_fd(sign, fd, 0);
	ft_putnbrc_fd(nbr, 0, 0, fd);
}

static void	ft_type(char *s, va_list arg, int hex, char sign)
{
	if (*s == 'c')
		ft_countc_fd((int) va_arg(arg, int), 1, 0);
	else if (*s == 's')
		ft_putstrc_fd((char *) va_arg(arg, char *), 1);
	else if (*s == 'd' || *s == 'i')
		ft_printnbr_sign_fd((int) va_arg(arg, int), sign, 1);
	else if (*s == 'u')
		ft_putnbrc_fd(0, (unsigned int) va_arg(arg, unsigned int), 1, 1);
	else if (*s == 'x')
		ft_putnbr_hex_fd((int) va_arg(arg, int), 0, hex, 1);
	else if (*s == 'X')
		ft_putnbr_hex_fd((int) va_arg(arg, int), 1, hex, 1);
	else if (*s == 'p')
		ft_putptr_fd((void *) va_arg(arg, void *), 1);
	else if (*s == '%')
		ft_countc_fd('%', 1, 0);
}

static char	*ft_type_flags(char *s, va_list arg)
{
	char	*flags;
	int		hex;
	char	sign;

	flags = "# +";
	hex = 0;
	sign = '\0';
	while (*s == flags[0] || *s == flags[1] || *s == flags[2])
	{
		if (*s == '#')
			hex = 1;
		if (*s == ' ' && sign != '+')
			sign = ' ';
		else if (*s == '+')
			sign = '+';
		++s;
	}
	ft_type(s, arg, hex, sign);
	return (s);
}

int	ft_identify(va_list args, char *s)
{
	while (*s != '\0')
	{
		if (*s == '%')
			s = ft_type_flags(++s, args);
		else
			ft_countc_fd(*s, 1, 0);
		++s;
	}
	return (ft_countc_fd('\0', 1, 1));
}
