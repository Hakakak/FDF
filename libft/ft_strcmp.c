/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:21:56 by haykharu          #+#    #+#             */
/*   Updated: 2025/04/18 15:25:27 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	c1;
	unsigned char	c2;

	while (*s1 != '\0' || *s2 != '\0')
	{
		c1 = (unsigned char) *s1;
		c2 = (unsigned char) *s2;
		if (c1 > c2)
			return (1);
		else if (c1 < c2)
			return (-1);
		++s1;
		++s2;
	}
	return (0);
}
