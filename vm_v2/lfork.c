/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 03:34:12 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/23 17:59:44 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		lfork(t_env *data, t_process *process)
{
	t_list			*tmp;
	t_process		*ptr;
	int				ok;
	unsigned char	*arena;

	arena = data->arena;
	if (!(ptr = malloc(sizeof(t_process))))
		error_msg("CAN'T MALLOC\n");
	*ptr = *process;
	ok = ptr->position;
	ptr->position = (ok + recup_val(2, arena, &process->position)) % MEM_SIZE;
	if (!(tmp = ft_lstnew(ptr, sizeof(t_process))))
		error_msg("CAN'T MALLOC\n");
	ft_lstadd(&data->process_list, tmp);
	process->position = ++process->position % MEM_SIZE;
	return (0);
}
