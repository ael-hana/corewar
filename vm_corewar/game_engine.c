/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 14:18:57 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/14 21:11:18 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		a_player_still_alive(t_list *player_list)
{
	t_list		*players_lst_curs;
	t_header	*player;

	players_lst_curs = player_list;
	while (players_lst_curs)
	{
		player = players_lst_curs->content;
		if (player->alive)
			return (1);
		players_lst_curs = players_lst_curs->next;
	}
	return (0);
}

void	player_turn(t_env *data, t_header *player)
{
	t_list		*process_lst_curs;
	t_process	*process;

	process_lst_curs = player->process_list;
	while (process_lst_curs)
	{
		process = process_lst_curs->content;
		if (process->alive)
			;
//			exec_process(data, process);
		process_lst_curs = process_lst_curs->next;
	}
}

void	start_game(t_env *data)
{
	t_list		*players;

	while (a_player_still_alive(data->player_list) && data->cycle < data->dump)
	{
		players = data->player_list;
		while (players)
		{
			player_turn(data, players->content);
			players = players->next;
		}
		data->cycle++;
	}
}
