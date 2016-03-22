/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:32:34 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/22 16:16:21 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

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
}
