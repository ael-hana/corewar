/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:14:49 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/11 19:19:25 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "compilo.h"

char	*jump_word(char *s, char *ref)
{
	while (*s && *ref && *s == *ref)
	{
		s++;
		ref++;
	}
	s = jump_whitespaces(s);
	return (s);
}

char	*jump_whitespaces(char *s)
{
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	return (s);
}

int		is_in_buf(char c, char *buf)
{
	while (*buf)
		if (*(buf++) == c)
			return (1);
	return (0);
}

void	write_big_endian(long nb, int size, int fd, int nbr)
{
	unsigned int	tmp;

	tmp = 0;
	if (size == 4)
	{
		tmp = nb >> 24;
		(nbr) ? ft_printf("%-4d", tmp) : write(fd, &tmp, 1);
		tmp = (nb - (tmp << 24)) >> 16;
		(nbr) ? ft_printf("%-4d", tmp) : write(fd, &tmp, 1);
	}
	if (size >= 2)
	{
		tmp = (nb - (tmp << 16)) >> 8;
		(nbr) ? ft_printf("%-4d", tmp) : write(fd, &tmp, 1);
	}
	tmp = nb - (tmp << 8);
	(nbr) ? ft_printf("%-*d", 4 * ((size == 2) ? 3 : 1), tmp)
	: write(fd, &tmp, 1);
}
