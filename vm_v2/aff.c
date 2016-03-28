/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 03:48:17 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/28 00:50:33 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		aff(t_env *data, t_process *process)
{
	unsigned char	*arena;
	int				*tab;
	unsigned char	v;

	arena = data->arena;
	if ((tab = get_op_args(arena, process)) == NULL)
		return (update_pc_pos_on_failure(arena, process));
	v = process->reg[tab[0]] % 256;
	write(1, &v, 1);
	update_pc_pos(arena, process);
	return (0);
}
