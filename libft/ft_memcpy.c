/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:02:05 by haykharu          #+#    #+#             */
/*   Updated: 2025/01/26 13:23:46 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*sourc;

	if (!dst && !src)
		return (NULL);
	dest = (char *) dst;
	sourc = (char *) src;
	i = 0;
	while (n)
	{
		dest[i] = sourc[i];
		++i;
		--n;
	}
	dst = dest;
	return (dst);
}
