/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 21:51:24 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/23 18:12:25 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		forkk(t_env *data, t_process *process)
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
