/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:23:48 by haykharu          #+#    #+#             */
/*   Updated: 2025/01/25 18:36:05 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	while ((*s1 != '\0' || *s2 != '\0') && n)
	{
		c1 = (unsigned char) *s1;
		c2 = (unsigned char) *s2;
		if (c1 > c2)
			return (1);
		else if (c1 < c2)
			return (-1);
		++s1;
		++s2;
		--n;
	}
	return (0);
}
