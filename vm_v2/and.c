/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:13:50 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/28 00:48:26 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		andd(t_env *data, t_process *process)
{
	unsigned char		*arena;
	int					*tab;
	int					reg_dest;

	if (data->debug)
		ft_printf("Start of AND\n");
	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (update_pc_pos_on_failure(arena, process));
	reg_dest = tab[2];
	if (data->debug)
		ft_printf("Arg 1 : %d, Arg 2 : %d, Arg 3 : %d\n", tab[0], tab[1], tab[2]);
	if (get_dir_value(arena, process, tab) == 0)
		return (update_pc_pos_on_failure(arena, process));
	if (data->debug)
		ft_printf("Arg 1 : %d, Arg 2 : %d, Arg 3 : %d\n", tab[0], tab[1], tab[2]);

	if (get_ind_value(data->arena, process, tab, 1) == 0)
		return (update_pc_pos_on_failure(arena, process));

	if (reg_dest >= 1 && reg_dest <= 16)
	{
		process->reg[reg_dest - 1] = tab[0] & tab[1];
		if ((tab[0] & tab[1]) == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		return (update_pc_pos_on_failure(arena, process));
	update_pc_pos(data->arena, process);
	if (data->debug)
		ft_printf("End of AND\n");
	return (1);
}
