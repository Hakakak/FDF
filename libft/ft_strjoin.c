/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:15:38 by haykharu          #+#    #+#             */
/*   Updated: 2025/01/22 18:22:19 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*str;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	str = (char *) malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		++i;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[len1 + i] = s2[i];
		++i;
	}
	str[len1 + i] = '\0';
	return (str);
}
