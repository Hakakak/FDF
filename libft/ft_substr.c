/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:01:07 by haykharu          #+#    #+#             */
/*   Updated: 2025/01/29 18:07:09 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	sub_len;

	sub_len = ft_strlen((char *)s);
	if (start >= sub_len)
	{
		str = (char *) malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	s += start;
	sub_len = ft_strlen((char *)s);
	if (sub_len > len)
		sub_len = len;
	str = (char *) malloc(sub_len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, sub_len + 1);
	return (str);
}
