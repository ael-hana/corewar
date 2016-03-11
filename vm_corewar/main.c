/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:10:38 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/11 17:30:57 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	init_data(t_env *data)
{
	data->i = 1;
}

int		main(int ac, char **av)
{
	t_env		data;

	init_data(&data);
	parse_flags(ac, av, &data);
}
