/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:34:26 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/17 17:34:26 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		add(unsigned char *arena, t_process *process)
{
	const int		i = ++process->position % MEM_SIZE;
	unsigned int	tab[2];
	char			st;

	if (arena[i] != 0b01010100)
		return (process->carry = 0);
	if ((st = recup_val(1, arena, &process->position)) < 17)
		tab[0] = st;
	else
		return (process->carry = 0);
	if ((st = recup_val(1, arena, &process->position)) < 17)
		tab[1] = st;
	else
		return (process->carry = 0);
	if ((st = recup_val(1, arena, &process->position)) < 17)
		process->reg[st] = process->reg[tab[0]] + process->reg[tab[1]];
	else
		return (process->carry = 0);
	process->position = ++process->position % MEM_SIZE;
	return (process->carry = process->reg[st] == 0 ? 1 : 0);
}
