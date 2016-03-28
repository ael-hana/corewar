/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:52:14 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/28 16:10:50 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"


unsigned int		ldi(t_env *data, t_process *process)
{
	unsigned char	*arena;
	int				*tab;
	int				value;
	int				index;
	int				reg_dest;

	if (data->debug)
		ft_printf("Start of LDI\n");
	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (update_pc_pos_on_failure(arena, process));
	reg_dest = tab[2];
	if (data->debug)
		ft_printf("Arg 1 : %#x, Arg 2 : %#x\n Arg 3 : %#x\n", tab[0], tab[1]);
	if (get_dir_value(arena, process, tab) == 0)
		return (update_pc_pos_on_failure(arena, process));
	if (get_ind_value(data->arena, process, tab, 1) == 0)
		return (update_pc_pos_on_failure(arena, process));
	if (data->debug)
		ft_printf("Arg 1 : %#x, Arg 2 : %#x\n Arg 3 : %#x\n", tab[0], tab[1]);
	index = (tab[0] + tab[1]) % IDX_MOD;
	value = arena[(process->position + index++) % MEM_SIZE];
	value = value << 8;
	value += arena[(process->position + index++) % MEM_SIZE];
	value = value << 8;
	value += arena[(process->position + index++) % MEM_SIZE];
	value = value << 8;
	value += arena[(process->position + index) % MEM_SIZE];
	if (reg_dest >= 1 && reg_dest <= 16)
		process->reg[reg_dest - 1] = value;
	else
		return (update_pc_pos_on_failure(arena, process));
	update_pc_pos(data->arena, process);
	if (data->debug)
		ft_printf("End of LDI\n");
	return (1);
}
