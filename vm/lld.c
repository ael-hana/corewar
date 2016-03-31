/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 03:07:46 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/31 14:58:09 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "function.h"

unsigned int		lld(t_env *data, t_process *process)
{
	unsigned char	*arena;
	int				*tab;

	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (update_pc_pos_on_failure(arena, process));
	if (get_ind_value(arena, process, tab, 0) == 0)
		return (update_pc_pos_on_failure(arena, process));
	if (get_ind_value(data->arena, process, tab, 1) == 0)
		return (update_pc_pos_on_failure(arena, process));
	if (tab[1] >= 1 && tab[1] <= 16)
	{
		process->reg[tab[1] - 1] = tab[0];
		if (tab[0] == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	update_pc_pos(data->arena, process);
	return (1);
}
