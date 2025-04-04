/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:37:17 by haykharu          #+#    #+#             */
/*   Updated: 2025/01/26 14:48:27 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	if (!dst && !src)
		return (NULL);
	dest = (char *) dst;
	source = (char *) src;
	if (dest > source)
	{
		dest += len - 1;
		source += len - 1;
		while (len--)
			*dest-- = *source--;
	}
	else
	{
		while (len--)
			*dest++ = *source++;
	}
	return (dst);
}
