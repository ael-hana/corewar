/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 19:48:29 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/23 18:44:22 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		ld(t_env *data, t_process *process)
{
	unsigned char	*arena;
	int				*tab;

	ft_printf("Start of LD\n");
	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (0);
	ft_printf("Arg 1 : %#x, Arg 2 : %#x\n", tab[0], tab[1]);
	if (tab[1] >= 1 && tab[1] <= 16)
	{
		process->reg[tab[1] - 1] = tab[0];
		if (tab[0] == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		return (0);
	ft_printf("Reg 2 : %#x\n", process->reg[1]);
	update_pc_pos(data->arena, process);
	ft_printf("End of LD\n");
	return (1);
}
