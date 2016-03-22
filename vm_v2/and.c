/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:13:50 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/21 14:54:00 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		and_bitwise(t_process *process, unsigned int *tab)
{
	process->position = ++process->position % MEM_SIZE;
	ft_putnbr(tab[2]);
	process->reg[tab[2]] = tab[1] & tab[0];
	return (process->carry = process->reg[tab[2]] == 0 ? 1 : 0);
}

unsigned int		andd(unsigned char *arena, t_process *process)
{
	const int		i = ++process->position % MEM_SIZE;
	int				it;
	unsigned int	tab[3];
	int				cmp;

	cmp = 6;
	it = -1;
	while (++it < 3 && arena[i] >> cmp)
	{
		if (!(arena[i] & 0b00000011) && it != 2 &&
				((arena[i] >> cmp) & 0b00000011) == 0b11)
			 tab[it] = recup_val(3, arena, &process->position);
		else if (!(arena[i] & 0b00000011) &&
				it != 2 && ((arena[i] >> cmp) & 0b00000011) == 0b10)
			tab[it] = recup_val(2, arena, &process->position);
		else if (!(arena[i] & 0b00000011) && ((arena[i] >> cmp) & 0b00000011)
		== 0b01 && (tab[it] = recup_val(1, arena, &process->position) < 17))
				tab[it] = process->reg[tab[it]];
		else
			return (process->carry = 0);
		cmp -= 2;
	}
	return (and_bitwise(process, tab));
}
