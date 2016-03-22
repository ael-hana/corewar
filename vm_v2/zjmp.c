/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:44:54 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/17 18:58:18 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		zjmp(unsigned char *arena, t_process *process)
{
	if (!process->carry)
		return (0);
	process->position = ((process->position - 4) +
		((short)recup_val(2, arena, &process->position) % IDX_MOD)) % MEM_SIZE;
	return (1);
}
