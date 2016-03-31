/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:52:14 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/31 18:44:32 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "function.h"

unsigned int		ldi(t_env *data, t_process *process)
{
	unsigned char	*arena;
	int				*tab;
	int				value;
	int				reg_dest;

	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (update_pc_pos_on_failure(arena, process, &tab));
	reg_dest = tab[2];
	if (get_dir_value(arena, process, tab) == 0)
		return (update_pc_pos_on_failure(arena, process, &tab));
	if (get_ind_value(data->arena, process, tab, 1) == 0)
		return (update_pc_pos_on_failure(arena, process, &tab));
	value = get_value(data->arena, process, (tab[0] + tab[1]) % IDX_MOD);
	if (reg_dest >= 1 && reg_dest <= 16)
		process->reg[reg_dest - 1] = value;
	update_pc_pos(data->arena, process);
	ft_memdel((void **)&tab);
	return (1);
}
