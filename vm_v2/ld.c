/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 19:48:29 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/24 03:51:18 by ecousine         ###   ########.fr       */
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
		return (0);
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
		return (0);
	ft_printf("Reg %d : %#x\n", tab[1], process->reg[tab[1] - 1]);
	update_pc_pos(data->arena, process);
	ft_printf("End of LD\n");
	return (1);
}

/*
unsigned int		ld(t_env *data, t_process *process)
{
	unsigned char	*arena;
	const int		i = ++process->position % MEM_SIZE;
	unsigned int	tab[2];

	arena = data->arena;
	if (((arena[i] >> 6) & 0b00000011) == 2)
		tab[0] = recup_val(3, arena, &process->position);
	else if (((arena[i] >> 6) & 0b00000011) == 3)
		tab[0] = recup_val(2, arena, &process->position);
	else
		return (process->carry = 0);
	if (!(arena[i] & 0b00001111) && ((arena[i] >> 4) & 0b00000011) == 1 &&
			(tab[1] = recup_val(1, arena, &process->position)) < 17)
		tab[1] = tab[1];
	else
		return (process->carry = 0);
	process->reg[tab[1]] = tab[0];
	write_hex(((i + (tab[0] % IDX_MOD)) % MEM_SIZE), arena,
			process->reg[tab[1]]);
	process->position = ++process->position % MEM_SIZE;
	return (tab[0] == 0 ? (process->carry = 1) : (process->carry = 0));
}*/
