/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 03:48:17 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/22 17:10:32 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		aff(unsigned char *arena, t_process *process)
{
	unsigned char	v;

	if (arena[++process->position % MEM_SIZE] != 0b01000000)
		return (0);
	if ((v = recup_val(1, arena, &process->position)) > 16)
		return (0);
	process->position = ++process->position % MEM_SIZE;
	v = process->reg[v] % 256;
	write(1, &v, 1);
	getchar();
	return (0);
}
