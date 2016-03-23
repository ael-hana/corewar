/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:32:34 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/23 15:08:58 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		st(t_env *data, t_process *process)
{
	unsigned char	*arena;
	int				*tab;

	ft_printf("Start of ST\n");
	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (0);
	ft_printf("Arg 1 : %#x, Arg 2 : %#x\n", tab[0], tab[1]);
	if (get_dir_value(arena, process, tab) == 0)
		return (0);
	ft_printf("Arg 1 : %#x, Arg 2 : %#x\n", tab[0], tab[1]);
	write_arena(data, process, tab[1] % IDX_MOD, tab[0]);
	update_pc_pos(data->arena, process);
	return (1);
}

void				write_hex(int position, unsigned char *arena, int val)
{
	int				st;

	st = 24;
	while (st >= 0)
	{
		arena[position % MEM_SIZE] = ((val >> st) & 0x000000FF);
		++position;
		st -= 8;
	}
}
/*
unsigned int		st(unsigned char *arena, t_process *process)
{
	const int		i = ++process->position % MEM_SIZE;
	int				reg_n;
	int				tab[2];

	if ((arena[i] & 0b00001111))
		return (process->carry = 0);
	if (((arena[i] >> 6) & 0b00000011) == 1 &&
			(reg_n = recup_val(1, arena, &process->position) < 17))
		tab[0] = process->reg[reg_n];
	else
		return (process->carry = 0);
	if (((arena[i] >> 4) & 0b00000011) == 1 &&
			(reg_n = recup_val(1, arena, &process->position) < 17))
		tab[1] = process->reg[reg_n];
	else if (((arena[i] >> 4) & 0b00000011) == 3)
		tab[1] = (short)recup_val(3, arena, &process->position);
	else
		return (process->carry = 0);
	write_hex(((i - 1) + (tab[1] % IDX_MOD)) % MEM_SIZE, arena, tab[0]);
	process->position = ++process->position % MEM_SIZE;
	return (0);
}*/
