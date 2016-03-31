/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 03:31:51 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/31 15:01:57 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "function.h"

int				get_value(unsigned char *arena, t_process *process, int index)
{
	int		value;

	value = arena[(process->position + index++) % MEM_SIZE];
	value = value << 8;
	value += arena[(process->position + index++) % MEM_SIZE];
	value = value << 8;
	value += arena[(process->position + index++) % MEM_SIZE];
	value = value << 8;
	value += arena[(process->position + index) % MEM_SIZE];
	return (value);
}

unsigned int	lldi(t_env *data, t_process *process)
{
	unsigned char	*arena;
	int				*tab;
	int				value;
	int				reg_dest;

	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (update_pc_pos_on_failure(arena, process));
	reg_dest = tab[2];
	if (get_dir_value(arena, process, tab) == 0)
		return (update_pc_pos_on_failure(arena, process));
	if (get_ind_value(data->arena, process, tab, 1) == 0)
		return (update_pc_pos_on_failure(arena, process));
	value = get_value(data->arena, process, tab[0] + tab[1]);
	if (reg_dest >= 1 && reg_dest <= 16)
	{
		process->reg[reg_dest - 1] = value;
		if (value == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	update_pc_pos(data->arena, process);
	return (1);
}
