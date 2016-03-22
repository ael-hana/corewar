/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:52:14 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/18 04:21:35 by ael-hana         ###   ########.fr       */
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
	if ((tab[0] = recup_val((arena[i] >> 6) & 3, arena, &process->position))
		> 16 && ((arena[i] >> 6) & 3) == 1)
		return (0);
	(((arena[i] >> 6) & 3) == 1) ? tab[0] = process->reg[tab[0]] : 0;
	if ((tab[1] = recup_val((arena[i] >> 4) & 3, arena, &process->position))
		> 16 && ((arena[i] >> 4) & 3) == 1)
		return (0);
	(((arena[i] >> 4) & 3) == 1) ? tab[1] = process->reg[tab[1]] : 0;
	if ((tab[2] = recup_val((arena[i] >> 2) & 3, arena, &process->position))
		> 16 && ((arena[i] >> 2) & 3) == 1)
		return (0);
	process->reg[tab[2]] = arena[((i - 1) + ((tab[0] + tab[1]) % IDX_MOD))
							% MEM_SIZE];
	//return (process->carry = process->reg[tab[2]] == 0 ? 1 : 0);
	return (0);
}
