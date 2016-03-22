/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 03:07:46 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/18 04:29:36 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		lld(unsigned char *arena, t_process *process)
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
			(tab[1] = recup_val(1, arena, &process->position) < 17))
		tab[1] = tab[1];
	else
		return (process->carry = 0);
	process->reg[tab[1]] = tab[0];
	write_hex((((i - 1) + (tab[0])) % MEM_SIZE), arena,
			process->reg[tab[1]]);
	process->position = ++process->position % MEM_SIZE;
	return (tab[0] == 0 ? (process->carry = 1) : (process->carry = 0));
}
