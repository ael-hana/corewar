/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:26:30 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/22 14:30:42 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int	sti(t_env *data, t_process *process)
{
	unsigned char		*arena;
	int					*tab;

	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (0);
	if (get_dir_value(arena, process, tab) == 0)
		return (0);
	write_arena(data, process, tab[1] + tab[2], tab[0]);
	update_pc_pos(data->arena, process);
	return (1);
}
/**
unsigned int	sti(unsigned char *arena, t_process *process)
{
	const int		i = ++process->position % MEM_SIZE;
	int				tab[3];

	if ((arena[i] & 0b11000000) != 0b01000000 || ((arena[i] & 0b00001100) !=
	0b00001000 && (arena[i] & 0b00001100) != 0b00000100) ||
	!(arena[i] & 0b00110000))
		return (42);
	if ((tab[0] = recup_val((arena[i] >> 6) & 3, arena, &process->position))
		> 16 && ((arena[i] >> 6) & 3) == 1)
		return (42);
	(((arena[i] >> 6) & 3) == 1) ? tab[0] = process->reg[tab[0]] : 0;
	if ((tab[1] = recup_val((arena[i] >> 4) & 3, arena, &process->position))
		> 16 && ((arena[i] >> 4) & 3) == 1)
		return (42);
	(((arena[i] >> 4) & 3) == 1) ? tab[1] = process->reg[tab[1]] : 0;
	if ((tab[2] = recup_val((arena[i] >> 2) & 3, arena, &process->position))
		> 16 && ((arena[i] >> 2) & 3) == 1)
		return (42);
	(((arena[i] >> 2) & 3) == 1) ? tab[2] = process->reg[tab[2]] : 0;
	write_hex(((i - 1) + ((tab[0] + tab[1])) % MEM_SIZE) % IDX_MOD, arena,
	tab[2]);
	process->position = ++process->position % MEM_SIZE;
	//return (process->carry = tab[0] == 0 ? 1 : 0);
	return (0);
}**/
