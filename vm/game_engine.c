/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 18:44:51 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/31 14:57:24 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "function.h"

int		a_process_still_alive(t_env *data)
{
	t_list		*process_list;
	t_process	*process;

	process_list = data->process_list;
	while (process_list)
	{
		process = process_list->content;
		if (process->alive)
			return (1);
		process_list = process_list->next;
	}
	return (0);
}

void	process_cycle(t_env *data, t_process *process)
{
	if (process->alive == 0)
		return ;
	if (data->cycle - data->cycle_to_die == data->cycle_of_last_verif)
		if (data->cycle - data->cycle_to_die >= process->last_alive)
			process->alive = 0;
	if (process->cycle == -1)
		get_inst(process, data->arena);
	else if (process->cycle == 0)
		exec_instruction(data, process);
	else
		process->cycle--;
}

void	print(t_env *data)
{
	ft_putstr(CLEAR_SCREEN);
	print_arena(data);
	print_info(data);
	usleep(25000);
}

void	start_game(t_env *data)
{
	t_list		*process_list;
	t_process	*process;

	while (a_process_still_alive(data) && data->cycle < data->dump &&
			data->cycle_to_die > 0)
	{
		process_list = data->process_list;
		while (process_list)
		{
			process = process_list->content;
			process_cycle(data, process);
			process_list = process_list->next;
		}
		if (data->cycle - data->cycle_of_last_verif == data->cycle_to_die)
		{
			if (data->total_live - data->live_last_verif > NBR_LIVE)
				data->cycle_to_die -= CYCLE_DELTA;
			data->cycle_of_last_verif = data->cycle;
			data->live_last_verif = data->total_live;
		}
		if (data->visual && data->cycle % data->cycle_per_sec == 0)
			print(data);
		data->cycle++;
	}
}
