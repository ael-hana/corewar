/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 14:18:57 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/17 18:54:07 by ecousine         ###   ########.fr       */
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
		{
			if (data->cycle - data->cycle_to_die > process->last_alive)
				process->alive = 0;
			else if (process->cycle == -1)
				get_inst(process, data->arena);
			else if (process->cycle == 0)
				exec_instruction(data, process);
			else
				process->cycle--;
		}
		process_lst_curs = process_lst_curs->next;
	}
}

void	start_game(t_env *data)
{
	t_list		*players;
	t_header	*player;

	while (a_player_still_alive(data->player_list) && data->cycle < data->dump)
	{
		if (data->cycle - data->cycle_of_last_verif == data->cycle_to_die)
			data->cycle_of_last_verif = data->cycle;
		if (data->cycle_of_last_verif == data->cycle)
			if (data->total_live - data->live_last_verif < NBR_LIVE)
				data->cycle_to_die -= CYCLE_DELTA;
		players = data->player_list;
		while (players)
		{
			player = players->content;
			if (data->cycle_of_last_verif == data->cycle)
				if (data->cycle - data->cycle_to_die > player->last_alive)
					player->alive = 0;
			if (player->alive)
				player_turn(data, player);
			players = players->next;
		}
		data->cycle++;
	}
}
