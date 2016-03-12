/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:10:38 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/12 17:47:06 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	init_data(t_env *data)
{
	data->i = 1;
}

int		main(int ac, char **av)
{
//	t_env		data;

//	init_data(&data);
//	parse_flags(ac, av, &data);
	ft_parssing(av[1]);
	return (0);
}
