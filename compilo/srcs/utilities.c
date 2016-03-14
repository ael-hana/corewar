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
