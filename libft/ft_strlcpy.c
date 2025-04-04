/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:45:45 by haykharu          #+#    #+#             */
/*   Updated: 2025/01/29 16:15:56 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen((char *) src);
	if (dstsize == 0)
	{
		while (*src != '\0')
			++src;
		return (src_len);
	}
	while (dstsize > 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		++i;
		--dstsize;
	}
	dst[i] = '\0';
	return (src_len);
}
