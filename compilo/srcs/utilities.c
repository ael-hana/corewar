/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:14:49 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/10 20:36:21 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compilo.h"

char	*jump_whitespaces(char *s)
{
	while (*s && *s == ' ' && *s == '\t')
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
