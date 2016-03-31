/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:12:25 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/31 14:59:55 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "function.h"

int		str_is_digit(char *str)
{
	while (*str)
		if (ft_isdigit(*str++) == 0)
			return (0);
	return (1);
}
