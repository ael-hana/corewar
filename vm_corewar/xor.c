/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:17:50 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/15 16:18:57 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		xor_bitwise(t_process *process, unsigned int *tab)
{
	process->position = ++process->position % MEM_SIZE;
	process->reg[tab[2]] = tab[1] ^ tab[0];
	return (process->carry = 1);
}

unsigned int		xor(unsigned char *arena, t_process *process)
{
	const int		i = ++process->position % MEM_SIZE;
	int				it;
	unsigned int	tab[3];
	int				cmp;

	cmp = 6;
	it = -1;
	if (arena[i] & 0b00000011)
		return (process->carry = 0);
	while (++it < 3 && arena[i] >> cmp)
	{
		if (it != 2 && ((arena[i] >> cmp) & 0b00000011) == 0b11)
			 tab[it] = recup_val(3, arena, &process->position);
		else if (it != 2 && ((arena[i] >> cmp) & 0b00000011) == 0b10)
			tab[it] = recup_val(2, arena, &process->position);
		else if (((arena[i] >> cmp) & 0b00000011) == 0b01 &&
			recup_val(1, arena, &process->position) < 17)
				tab[it] = process->reg[recup_reg_n(arena, &process->position)];
		else
			return (process->carry = 0);
		cmp -= 2;
	}
	return (xor_bitwise(process, tab));
}
