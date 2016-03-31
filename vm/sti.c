/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:26:30 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/31 15:03:21 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "function.h"

unsigned int	sti(t_env *data, t_process *process)
{
	unsigned char		*arena;
	int					*tab;

	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (update_pc_pos_on_failure(arena, process));
	if (get_dir_value(arena, process, tab) == 0)
		return (update_pc_pos_on_failure(arena, process));
	if (get_ind_value(arena, process, tab, 1) == 0)
		return (update_pc_pos_on_failure(arena, process));
	write_arena(data, process, (tab[1] + tab[2]) % IDX_MOD, tab[0]);
	update_pc_pos(data->arena, process);
	return (1);
}
