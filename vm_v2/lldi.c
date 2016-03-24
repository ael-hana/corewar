/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 03:31:51 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/23 22:36:10 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		lldi(t_env *data, t_process *process)
{
	unsigned char	*arena;
	int				*tab;
	int				value;
	int				index;
	int				reg_dest;

	ft_printf("Start of LLDI\n");
	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (0);
	reg_dest = tab[2];
	ft_printf("Arg 1 : %#x, Arg 2 : %#x\n Arg 3 : %#x\n", tab[0], tab[1]);
	if (get_dir_value(arena, process, tab) == 0)
		return (0);
	ft_printf("Arg 1 : %#x, Arg 2 : %#x\n Arg 3 : %#x\n", tab[0], tab[1]);
	index = (tab[0] + tab[1]);
	value = arena[(process->position + index++) % MEM_SIZE];
	value = value << 8;
	value += arena[(process->position + index++) % MEM_SIZE];
	value = value << 8;
	value += arena[(process->position + index++) % MEM_SIZE];
	value = value << 8;
	value += arena[(process->position + index) % MEM_SIZE];
	if (reg_dest >= 1 && reg_dest <= 16)
	{
		process->reg[reg_dest - 1] = value;
		if (value == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		return (0);
	update_pc_pos(data->arena, process);
	ft_printf("End of LLDI\n");
	return (1);
}
