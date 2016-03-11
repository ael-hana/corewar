/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:20:38 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/11 19:58:06 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		str_is_digit(char *str)
{
	while (*str)
		if (ft_isdigit(*str) == 0)
			return (0);
	return (1);
}
int		get_dump(int ac, char **av, t_env *data)
{
	if (data->i + 1 < ac && str_is_digit(av[data->i]) && (data->dump = ft_atoi(av[data->i]) > 0))
	return (1);
}

int		parse_flags(int ac, char **av, t_env *data)
{
	while (data->i < ac)
	{
		if (ft_strcmp(av[data->i], "-n") == 0)
			break;
		else if (ft_strcmp(av[data->i], "-dump") == 0)
			get_dump(ac, av, data);
		data->i++;
	}
	return (1);
}
