/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:50:18 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/22 20:03:48 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	last_alive(t_env *data, int id)
{
	t_list		*players;
	t_header	*player;

	players = data->player_list;
	while (players)
	{
		player = players->content;
		if (0xFFFFFFFF - player->n == id)
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
		last_alive(data, live(data->arena, process));
	}
	else if (process->op == 2)
		ld(data, process);
	else if (process->op == 3)
		st(data->arena, process);
	else if (process->op == 4)
		add(data->arena, process);
	else if (process->op == 5)
		sub(data->arena, process);
	else if (process->op == 6)
		andd(data->arena, process);
	else if (process->op == 7)
		orr(data->arena, process);
	else if (process->op == 8)
		xorr(data->arena, process);
	else if (process->op == 9)
		zjmp(data->arena, process);
	else if (process->op == 10)
		ldi(data->arena, process);
	else if (process->op == 11)
		sti(data, process);
	else if (process->op == 16)
		aff(data->arena, process);
//	else if (process->op == 12)
//		;
//		forkk(data->arena, process, player);
	else
		ft_putendl("ERRREUR");
	process->position = (process->position + 1) % MEM_SIZE;
	process->op = 0;
	process->cycle = -1;
}
