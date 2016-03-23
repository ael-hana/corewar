/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:26:30 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/23 18:40:39 by ael-hana         ###   ########.fr       */
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
	ft_printf("Arg 1 : %d, Arg 2 : %d, Arg 3 : %d\n", tab[0], tab[1], tab[2]);
	if (get_dir_value(arena, process, tab) == 0)
		return (0);
	ft_printf("Arg 1 : %d, Arg 2 : %d, Arg 3 : %d\n", tab[0], tab[1], tab[2]);
	write_arena(data, process, (tab[1] + tab[2]) % IDX_MOD, tab[0]);
	update_pc_pos(data->arena, process);
	ft_printf("End of STI\n");
	return (1);
}
