/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countc_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haykharu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 12:10:14 by haykharu          #+#    #+#             */
/*   Updated: 2025/03/26 14:11:25 by haykharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countc_fd(char c, int fd, int mode)
{
	static int	i;

	if (mode == 0)
	{
		write(fd, &c, 1);
		++i;
	}
	else if (mode == 1)
		return (i);
	else if (mode == 2)
		i = 0;
	return (0);
}
