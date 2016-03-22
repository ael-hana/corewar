/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 19:48:29 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/22 17:56:51 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		ld(t_env *data, t_process *process)
{
	unsigned char	*arena;
	int				*tab;

	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (0);
	ft_printf("Arg 1 %#x, Arg 2 %#x\n", tab[0], tab[1]);
	if (tab[1] >= 1 && tab[1] <= 16)
	{
		process->reg[tab[1] - 1] = tab[0];
		if (tab[0] == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		return (0);
	update_pc_pos(data->arena, process);
	return (1);
}

/**
unsigned int		ld(unsigned char *arena, t_process *process)
{
	const int		i = ++process->position % MEM_SIZE;
	int				tab[2];

	if (((arena[i] >> 6) & 0b00000011) == 3)
		tab[0] = recup_val(3, arena, &process->position);
	else if (((arena[i] >> 6) & 0b00000011) == 2)
		tab[0] = recup_val(2, arena, &process->position);
	else
		return (process->carry = 0);
	if (!(arena[i] & 0b00001111) && ((arena[i] >> 4) & 0b00000011) == 1 &&
			(tab[1] = recup_val(1, arena, &process->position)) < 17)
		tab[1] = tab[1];
	else
		return (process->carry = 0);
	process->reg[tab[1]] = tab[0];
	write_hex(((i + (tab[0] % IDX_MOD)) % MEM_SIZE), arena,
			process->reg[tab[1]]);
	process->position = ++process->position % MEM_SIZE;
	return (tab[0] == 0 ? (process->carry = 1) : (process->carry = 0));
}**/
