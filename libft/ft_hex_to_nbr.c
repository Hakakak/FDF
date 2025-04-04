/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:14:54 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/02 14:55:41 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_geti(char c)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = "0123456789abcdef";
	s2 = "0123456789ABCDEF";
	i = 0;
	if (ft_strchr(s1, c))
	{
		while (s1[i] && s1[i] != c)
			++i;
	}
	else if (ft_strchr(s2, c))
	{
		while (s2[i] && s2[i] != c)
			++i;
	}
	else
		return (-1);
	return (i);
}

static int	ft_convert_16(char *s)
{
	int	nbr;
	int	len;
	int	i;

	nbr = 0;
	len = 0;
	i = 0;
	while (s[i] && ft_geti(s[i++]) != -1)
		++len;
	while (len > 0)
	{
		--len;
		nbr += ft_geti(*s) * ft_raise(16, len);
		++s;
	}
	return (nbr);
}

int	ft_hex_to_nbr(char *s)
{
	if (!s)
		return (0);
	if (!ft_strncmp(s, "0x", 2) || !ft_strncmp(s, "0X", 2))
		s += 2;
	return (ft_convert_16(s));
}
