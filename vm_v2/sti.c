/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:26:30 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/24 08:41:36 by ecousine         ###   ########.fr       */
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
		return (update_pc_pos_on_failure(arena, process));
	ft_printf("Board : Arg 1 : %#x, Arg 2 : %#x, Arg 3 : %#x\n", tab[0], tab[1], tab[2]);
	if (get_dir_value(arena, process, tab) == 0)
		return (update_pc_pos_on_failure(arena, process));
	ft_printf("Dir   : Arg 1 : %#x, Arg 2 : %#x, Arg 3 : %#x\n", tab[0], tab[1], tab[2]);
	if (get_ind_value(arena, process, tab, 1) == 0)
		return (update_pc_pos_on_failure(arena, process));
	ft_printf("Ind   : Arg 1 : %#x, Arg 2 : %#x, Arg 3 : %#x\n", tab[0], tab[1], tab[2]);
	write_arena(data, process, (tab[1] + tab[2]) % IDX_MOD, tab[0]);
	update_pc_pos(data->arena, process);
	ft_printf("End of STI\n");
	return (1);
}
