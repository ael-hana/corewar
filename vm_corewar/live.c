/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:54:45 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/14 21:11:16 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		live(unsigned char *arena, t_process *process)
{
	unsigned int	len;

	process->position = ++process->position % MEM_SIZE;
	len = arena[++process->position % MEM_SIZE];
	len = len << 8;
	len += arena[++process->position % MEM_SIZE];
	len = len << 8;
	len += arena[++process->position % MEM_SIZE];
	len = len << 8;
	len += arena[++process->position % MEM_SIZE];
	process->position = process->position % MEM_SIZE;
	process->carry = 1;
	return (len);
}
