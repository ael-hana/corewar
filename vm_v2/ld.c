/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 19:48:29 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/24 08:35:23 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		ld(t_env *data, t_process *process)
{
	unsigned char	*arena;
	int				*tab;

	ft_printf("Begin of LD\n");
	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (update_pc_pos_on_failure(arena, process));
	ft_printf("Board : Arg 1 : %#x, Arg 2 : %#x\n", tab[0], tab[1]);
	if (get_ind_value(arena, process, tab, 1) == 0)
		return (update_pc_pos_on_failure(arena, process));
	ft_printf("Ind   : Arg 1 : %#x, Arg 2 : %#x\n", tab[0], tab[1]);
	if (tab[1] >= 1 && tab[1] <= 16)
	{
		process->reg[tab[1] - 1] = tab[0];
		if (tab[0] == 0)
			process->carry = 1;
		else
			process->carry = 0;
	}
	else
		return (update_pc_pos_on_failure(arena, process));
	ft_printf("Reg %d : %#x\n", tab[1], process->reg[tab[1] - 1]);
	update_pc_pos(data->arena, process);
	ft_printf("End of LD\n");
	return (1);
}
