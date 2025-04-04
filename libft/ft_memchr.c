/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:37:11 by haykharu          #+#    #+#             */
/*   Updated: 2025/01/25 18:35:04 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;

	ch = (unsigned char) c;
	str = (unsigned char *) s;
	while (n)
	{
		if (*str == ch)
			return (str);
		++str;
		--n;
	}
	return (NULL);
}
