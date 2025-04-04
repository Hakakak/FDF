/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:45:28 by haykharu          #+#    #+#             */
/*   Updated: 2025/02/06 13:08:46 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(char *str, char c)
{
	size_t	i;
	int		is_word;

	i = 0;
	is_word = 0;
	while (*str != '\0')
	{
		if (*str != c)
			is_word = 1;
		else if (is_word)
		{
			is_word = 0;
			++i;
		}
		++str;
	}
	if (is_word)
		++i;
	return (i);
}

static size_t	ft_split_m(char **str_arr, char *s, size_t *j, char c)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c && *(s + 1) == '\0')
		{
			str_arr[i++] = ft_substr(s - *j, 0, *j + 1);
			if (!str_arr[i - 1])
				return (i - 1);
		}
		else if (*j && *s == c)
		{
			str_arr[i++] = ft_substr(s - *j, 0, *j);
			if (!str_arr[i - 1])
				return (i - 1);
			*j = 0;
		}
		if (*s != c)
			++(*j);
		++s;
	}
	str_arr[i] = NULL;
	return (i);
}

static char	**ft_split_check(char **str_arr, char *s, char c, size_t len)
{
	size_t	j;
	size_t	fin_len;

	j = 0;
	fin_len = ft_split_m(str_arr, s, &j, c);
	if (fin_len < len)
	{
		while (fin_len--)
			free(str_arr[fin_len]);
		free(str_arr);
		return (NULL);
	}
	return (str_arr);
}

char	**ft_split(const char *s, char c)
{
	char	**str_arr;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_getlen((char *)s, c);
	str_arr = (char **) malloc((len + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	ft_split_check(str_arr, (char *) s, c, len);
	return (str_arr);
}
