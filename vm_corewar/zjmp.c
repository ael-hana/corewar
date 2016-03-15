/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:44:54 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/15 17:25:02 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		zjmp(unsigned char *arena, t_process *process)
{
	if (!process->carry)
		return (process->carry = 0);
	process->position = (process->position - 4) +
		recup_val(2, arena, &process->position);
	return (process->carry = 1);
}
