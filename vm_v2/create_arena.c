/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:10:11 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/28 00:51:46 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int mod(int a, int b)
{
	int r = a % b;

	return (r < 0 ? r + b : r);
}

void	write_arena(t_env *data, t_process *pc, int pos, int value)
{
	int			i;
	t_header	*player;
	int			index;

	player = pc->player;
	i = 0;
	index = mod(pc->position + pos, MEM_SIZE);
	if (data->debug)
		ft_printf("Write : %#x at %d\n", value, index % MEM_SIZE);
	while (i < 4)
	{
		data->arena[(index + i) % MEM_SIZE] = value >> 24;
		data->arena_owner[(index + i) % MEM_SIZE] = player->numb;
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
