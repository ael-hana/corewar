/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:52:14 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/17 19:20:13 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		ldi(unsigned char *arena, t_process *process)
{
	const int		i = ++process->position % MEM_SIZE;
	int				tab[3];
	
	if ((arena[i] & 0b00001100) != 0b00000100 || ((arena[i] & 0b00110000) !=
	0b00100000 && (arena[i] & 0b00110000) != 0b00010000) ||
	!(arena[i] & 0b11000000))
		return (0);
	tab[0] = recup_val((arena[i] >> 6) & 3, arena, &process->position);
	if ((arena[i] >> 6) & 1)
		tab[0] = process->reg[tab[0]];
	tab[1] = recup_val((arena[i] >> 4) & 3, arena, &process->position);
	if ((arena[i] >> 4) & 1)
		tab[1] = process->reg[tab[1]];
	if ((tab[2] = recup_val(1, arena, &process->position)) >= 17)
			return (0);
	process->reg[tab[2]] = arena[(((i - 1) + (tab[0] + tab[1])) % MEM_SIZE)
		% IDX_MOD];
	return (process->carry = process->reg[tab[2]] == 0 ? 1 : 0);
}
