/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:10:38 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/12 21:32:25 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	init_data(t_env *data)
{
	data->i = 1;
	data->nb_players = 0;
	data->player_list = NULL;
}

int		main(int ac, char **av)
{
	t_env		data;

	init_data(&data);
	parse_flags(ac, av, &data);
	parse_players(ac, av, &data);
	create_arena(&data);
	place_players(&data);
	print_arena(data.arena);
	return (0);
}
