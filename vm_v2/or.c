/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:05:35 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/24 07:31:22 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		orr(t_env *data, t_process *process)
{
	unsigned char		*arena;
	int					*tab;
	int					reg_dest;

	ft_printf("Start of OR\n");
	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (0);
	reg_dest = tab[2];
	ft_printf("Arg 1 : %#x, Arg 2 : %#x, Arg 3 : %#x\n", tab[0], tab[1], tab[2]);
	if (get_dir_value(arena, process, tab) == 0)
		return (0);
	ft_printf("Arg 1 : %#x, Arg 2 : %#x, Arg 3 : %#x\n", tab[0], tab[1], tab[2]);
	if (reg_dest >= 1 && reg_dest <= 16)
	{
		process->reg[reg_dest - 1] = tab[0] | tab[1];
		if ((tab[0] | tab[1]) == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	update_pc_pos(data->arena, process);
	ft_printf("End of OR\n");
	return (1);
}
