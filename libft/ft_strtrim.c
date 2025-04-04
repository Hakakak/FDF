/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:25:33 by haykharu          #+#    #+#             */
/*   Updated: 2025/03/26 13:52:26 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_clean_len(const char *s1, const char *s2)
{
	size_t	i;
	ssize_t	j;

	i = 0;
	while (s1[i] != '\0' && ft_strchr((char *)s2, s1[i]))
		++i;
	j = ft_strlen((char *)s1);
	while (j >= 0 && ft_strrchr((char *)s2, s1[j]))
		--j;
	return (j - i + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char		*str;
	long long	len;
	size_t		i;
	size_t		j;

	len = ft_clean_len(s1, set);
	if (len < 0)
		len = 0;
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	len = 0;
	j = ft_strlen((char *)s1);
	while (j > 0 && ft_strrchr((char *)set, s1[j]))
		--j;
	while (s1[i] != '\0' && ft_strchr((char *)set, s1[i]))
		++i;
	while (s1[i] != '\0' && i <= j)
	{
		str[len++] = s1[i];
		++i;
	}
	str[len] = '\0';
	return (str);
}
