/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:26:30 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/23 21:40:48 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int	sti(t_env *data, t_process *process)
{
	unsigned char		*arena;
	int					*tab;

	ft_printf("Start of STI\n");
	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (0);
	ft_printf("Board : Arg 1 : %#x, Arg 2 : %#x, Arg 3 : %#x\n", tab[0], tab[1], tab[2]);
	if (get_dir_value(arena, process, tab) == 0)
		return (0);
	ft_printf("Dir   : Arg 1 : %#x, Arg 2 : %#x, Arg 3 : %#x\n", tab[0], tab[1], tab[2]);
	if (get_ind_value(arena, process, tab, 1) == 0)
		return (0);
	ft_printf("Ind   : Arg 1 : %#x, Arg 2 : %#x, Arg 3 : %#x\n", tab[0], tab[1], tab[2]);
	write_arena(data, process, (tab[1] + tab[2]) % IDX_MOD, tab[0]);
	update_pc_pos(data->arena, process);
	ft_printf("End of STI\n");
	return (1);
}
/*
unsigned int	sti(t_env *data, t_process *process)
{
	const int		i = ++process->position % MEM_SIZE;
	unsigned char		*arena = data->arena;
	int				tab[3];

	if ((arena[i] & 0b11000000) != 0b01000000 || ((arena[i] & 0b00001100) !=
	0b00001000 && (arena[i] & 0b00001100) != 0b00000100) ||
	!(arena[i] & 0b00110000))
		return (42);
	if ((tab[0] = recup_val(((arena[i] >> 6) & 3) == 3 ? 2 : ((arena[i] >> 6) & 3), arena, &process->position)) > 16 && ((arena[i] >> 6) & 3) == 1)
		return (42);
	(((arena[i] >> 6) & 3) == 1) ? tab[0] = process->reg[tab[0]] : 0;
	if ((tab[1] = recup_val(((arena[i] >> 4) & 3) == 3 ? 2 : ((arena[i] >> 4) & 3), arena, &process->position)) > 16 && ((arena[i] >> 4) & 3) == 1)
		return (42);
	(((arena[i] >> 4) & 3) == 1) ? tab[1] = process->reg[tab[1]] : 0;
	if ((tab[2] = recup_val(((arena[i] >> 2) & 3) == 3 ? 2 : ((arena[i] >> 2) & 3), arena, &process->position)) > 16 && ((arena[i] >> 2) & 3) == 1)
		return (42);
	((arena[i] >> 2) & 3) == 1 ? tab[2] = process->reg[tab[2]] : 0;
	write_hex(((i - 1) + (((tab[2] + tab[1])) % MEM_SIZE) % IDX_MOD), arena, tab[0]);
	process->position = ++process->position % MEM_SIZE;
	ft_printf("\n\n\n\n%x %x %x %d", tab[0], tab[1], tab[2], arena[((((tab[2] + tab[1])) % MEM_SIZE) % IDX_MOD)]);
	ft_printf(" %d", arena[1 + ((((tab[2] + tab[1])) % MEM_SIZE) % IDX_MOD)]);
	ft_printf(" %d", arena[2 + ((((tab[2] + tab[1])) % MEM_SIZE) % IDX_MOD)]);
	ft_printf(" %d\n\n\n\n", arena[3 + ((((tab[2] + tab[1])) % MEM_SIZE) % IDX_MOD)]);
	//return (process->carry = tab[0] == 0 ? 1 : 0);
	return (0);
}
*/
