/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:17:54 by haykharu          #+#    #+#             */
/*   Updated: 2025/01/29 18:01:04 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && n)
	{
		j = ft_strlen((char *) needle);
		if (!ft_strncmp(&haystack[i], needle, j) && (n >= j))
			return ((char *)&haystack[i]);
		--n;
		++i;
	}
	return (NULL);
}
