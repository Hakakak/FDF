/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:14:24 by haykharu          #+#    #+#             */
/*   Updated: 2025/03/26 17:16:37 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_stash(char *str)
{
	int		i;
	int		c;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tmp = (char *) malloc(ft_strlen(str) - i + 1);
	if (!tmp)
	{
		free(str);
		return (NULL);
	}
	i++;
	c = 0;
	while (str[i])
		tmp[c++] = str[i++];
	tmp[c] = '\0';
	free(str);
	return (tmp);
}

static char	*get_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *) malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_rd_f(int fd, char *dest)
{
	ssize_t	rd_byte;
	char	*buf;

	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	rd_byte = 1;
	while (!ft_strchrg(dest, '\n') && rd_byte)
	{
		rd_byte = read(fd, buf, BUFFER_SIZE);
		if (rd_byte == -1)
		{
			free(buf);
			if (dest)
				free(dest);
			return (NULL);
		}
		buf[rd_byte] = '\0';
		dest = ft_strjoing(dest, buf);
	}
	free(buf);
	return (dest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*strs[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	strs[fd] = ft_rd_f(fd, strs[fd]);
	if (!strs[fd])
		return (NULL);
	line = get_line(strs[fd]);
	if (!line)
	{
		if (strs[fd])
			free(strs[fd]);
		strs[fd] = NULL;
		return (NULL);
	}
	strs[fd] = ft_stash(strs[fd]);
	return (line);
}
