/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:10:11 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/22 14:11:02 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	write_arena(t_env *data, t_process *pc, int pos, int value)
{
	int			i;
	t_header	*player;

	player = pc->player;
	i = 0;
	while (i < 4)
	{
		data->arena[(pc->position + pos + i) % MEM_SIZE] = value >> 24;
		data->arena_owner[(pc->position + pos + i) % MEM_SIZE] = player->numb;
		value = value << 8;
		i++;
	}
}

void	create_arena(t_env *data)
{
	data->arena = malloc(sizeof(unsigned char) * MEM_SIZE);
	ft_bzero(data->arena, MEM_SIZE);
	data->arena_owner = malloc(sizeof(unsigned char) * MEM_SIZE);
	ft_bzero(data->arena_owner, MEM_SIZE);
}
