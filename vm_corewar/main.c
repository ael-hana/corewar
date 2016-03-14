/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:10:38 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/14 17:41:20 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	init_data(t_env *data)
{
	data->i = 1;
	data->cycle = 0;
	data->nb_players = 0;
	data->total_live = 0;
	data->live_last_verif = 0;
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
	print_player_introduction(data.player_list);
	print_arena(data.arena);
//	start_game(&data);
	return (0);
}
