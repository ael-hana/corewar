/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 03:34:12 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/18 03:44:35 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		lfork(unsigned char *arena, t_process *process, t_header *r)
{
	t_list			*tmp;
	t_process		*ptr;
	int				ok;

	if (!(ptr = malloc(sizeof(t_process))))
		error_msg("CAN'T MALLOC\n");
	*ptr = *process;
	ok = process->position;
	ptr->position = (ok + recup_val(3, arena, &process->position)) % MEM_SIZE;
	if (!(tmp = ft_lstnew(ptr, sizeof(t_process))))
		error_msg("CAN'T MALLOC\n");
	ft_lstadd(&r->process_list, tmp);
	process->position = ++process->position % MEM_SIZE;
	return (0);
}
