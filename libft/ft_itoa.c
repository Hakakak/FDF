/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:20:37 by haykharu          #+#    #+#             */
/*   Updated: 2025/01/25 18:15:35 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_abs(int c)
{
	if (c < 0)
		return ((size_t) c * (-1));
	else
		return ((size_t) c);
}

static int	ft_power(int base, int power)
{
	int	res;

	res = 1;
	while (power > 0)
	{
		res *= base;
		--power;
	}
	return (res);
}

static int	ft_nblen(int nbr)
{
	int	i;

	i = 1;
	while (nbr >= 10 || nbr <= -10)
	{
		nbr /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int c)
{
	size_t	len;
	size_t	nb;
	size_t	i;
	char	*str;

	len = ft_nblen(c);
	if (c < 0)
		++len;
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	nb = ft_abs(c);
	if (c < 0)
		str[i++] = '-';
	while (i < len)
	{
		str[i] = nb / ft_power(10, len - i - 1) + 48;
		nb = nb % ft_power(10, len - i - 1);
		++i;
	}
	str[i] = '\0';
	return (str);
}
