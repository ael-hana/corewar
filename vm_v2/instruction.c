/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:50:18 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/23 19:29:39 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	last_alive(t_env *data, unsigned int id)
{
	t_list		*players;
	t_header	*player;

	players = data->player_list;
	while (players)
	{
		player = players->content;
		if (0xFFFFFFFF - (player->n - 1) == id)
		{
			data->total_live++;
			player->last_alive = data->cycle;
		}
		players = players->next;
	}
}

void	exec_instruction(t_env *data, t_process *process)
{
	if (process->op == 1)
	{
		process->last_alive = data->cycle;
		last_alive(data, live(data, process));
	}
	else if (process->op == 2)
		ld(data, process);
	else if (process->op == 3)
		st(data, process);
	else if (process->op == 4)
		add(data, process);
	else if (process->op == 5)
		sub(data, process);
	else if (process->op == 6)
		andd(data, process);
	else if (process->op == 7)
		orr(data, process);
	else if (process->op == 8)
		xorr(data, process);
	else if (process->op == 9)
		zjmp(data, process);
	else if (process->op == 10)
		ldi(data, process);
	else if (process->op == 11)
		sti(data, process);
	else if (process->op == 12)
		forkk(data, process);
	else if (process->op == 13)
		lld(data, process);
	else if (process->op == 14)
		lldi(data, process);
	else if (process->op == 15)
		lforkk(data, process);
	else if (process->op == 16)
		aff(data, process);
	process->position = (process->position + 1) % MEM_SIZE;
	process->op = 0;
	process->cycle = -1;
}
