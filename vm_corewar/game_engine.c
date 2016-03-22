/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 14:18:57 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/18 03:29:49 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		player_process_alive(t_header *player)
{
	t_list		*process_list;
	t_process	*process;

	process_list = player->process_list;
	while (process_list)
	{
		process = process_list->content;
		if (process->alive == 1)
			return (1);
		process_list = process_list->next;
	}
	return (0);
}

int		a_process_still_alive(t_list *player_list)
{
	t_list		*players_lst_curs;
	t_header	*player;

	players_lst_curs = player_list;
	while (players_lst_curs)
	{
		player = players_lst_curs->content;
		if (player_process_alive(player))
			return (1);
		players_lst_curs = players_lst_curs->next;
	}
	return (0);
}

void	player_turn(t_env *data, t_header *player)
{
	t_list		*process_list;
	t_process	*process;

	process_list = player->process_list;
	while (process_list)
	{
		process = process_list->content;

		ft_printf("Cycle : %d lastalive : %d, opcode : %d, position : %d, wait : %d, carry : %d\n",
				data->cycle, process->last_alive, process->op, process->position, process->cycle, process->carry);
		if (process->alive == 0)
			break ;
		else if (data->cycle - data->cycle_to_die == data->cycle_of_last_verif)
		{
			if (data->cycle - data->cycle_to_die >= process->last_alive)
				process->alive = 0;
		}
		else if (process->cycle == -1)
			get_inst(process, data->arena);
		else if (process->cycle == 0)
			exec_instruction(data, process, player);
		else
			process->cycle--;
		process_list = process_list->next;
	}
}

void	start_game(t_env *data)
{
	t_list		*player_list;
	t_header	*player;

	while (a_process_still_alive(data->player_list) && data->cycle < data->dump)
	{
		player_list = data->player_list;

		while (player_list)
		{
//			print_arena(data->arena);
			getchar();
			player = player_list->content;
			player_turn(data, player);
			player_list = player_list->next;
			if (data->cycle - data->cycle_of_last_verif == data->cycle_to_die)
			{
				if (data->total_live - data->live_last_verif > NBR_LIVE)
					data->cycle_to_die -= CYCLE_DELTA;
				data->cycle_of_last_verif = data->cycle;
				data->live_last_verif = data->total_live;
			}
		}
		data->cycle++;
	}
}
/**
void	start_game(t_env *data)
{
	t_list		*players;
	t_header	*player;

	while (a_process_still_alive(data->player_list) && data->cycle < data->dump)
	{
		usleep (5000);
		ft_printf("\e[1;1H\e[2J");
		print_arena(data->arena);
		print_info(data);
		if (data->cycle - data->cycle_of_last_verif == data->cycle_to_die)
			data->cycle_of_last_verif = data->cycle;
		if (data->cycle_of_last_verif == data->cycle)
			if (data->total_live - data->live_last_verif < NBR_LIVE)
				data->cycle_to_die -= CYCLE_DELTA;
		players = data->player_list;
		while (players)
		{
			player = players->content;
			if (player->alive)
				player_turn(data, player);
			players = players->next;
		}
		data->cycle++;
	}
} **/
