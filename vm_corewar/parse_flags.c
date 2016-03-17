/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:20:38 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/17 19:01:31 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		get_dump(int ac, char **av, t_env *data)
{
	if (data->i + 1 < ac && str_is_digit(av[data->i + 1]) &&
		(data->dump = ft_atoi(av[data->i + 1]) > 0))
	{
		data->i++;
		return (1);
	}
	else
		print_error(ERR_PARAM);
	return (-1);
}

int		parse_flags(int ac, char **av, t_env *data)
{
	while (data->i < ac)
	{
		if (ft_strcmp(av[data->i], "-dump") == 0)
			get_dump(ac, av, data);
		else if (ft_strcmp("-n", av[data->i]) == 0)
			break;
		else if (av[data->i][0] == '-')
			print_error(ERR_PARAM);
		data->i++;
	}
	return (1);
}
