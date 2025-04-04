/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:48:40 by haykharu          #+#    #+#             */
/*   Updated: 2025/03/26 13:51:36 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen((char *)s);
	while (i > 0)
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		--i;
	}
	if (s[i] == (char) c)
		return ((char *)&s[i]);
	return (NULL);
}
