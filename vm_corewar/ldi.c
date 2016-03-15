/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:52:14 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/15 18:44:44 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		ldi(unsigned char *arena, t_process *process)
{
	const int		i = ++process->position % MEM_SIZE;

	if (arena[i] & 0b00001100 || (arena[i] & 0b00110000) == 0b00110000 ||
		!(arena[i] & 0b00110000) || !(arena[i] & 0b11000000))
		return (process->carry = 0);
}
