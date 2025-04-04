/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:35:12 by haykharu          #+#    #+#             */
/*   Updated: 2025/01/29 16:58:09 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_d;
	size_t	size_s;

	size_d = ft_strlen(dst);
	size_s = ft_strlen((char *) src);
	if (size_d > dstsize || dstsize == 0)
		return (dstsize + size_s);
	i = 0;
	while (src[i] != '\0' && size_d + i < dstsize - 1)
	{
		dst[size_d + i] = src[i];
		++i;
	}
	dst[size_d + i] = '\0';
	return (size_d + size_s);
}
