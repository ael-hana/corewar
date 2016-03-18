/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 21:51:24 by ael-hana          #+#    #+#             */
/*   Updated: 2016/03/18 03:34:40 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

unsigned int		forkk(unsigned char *arena, t_process *process, t_header *r)
{
	t_list			*tmp;
	int				ok;

	ok = process->position;
	if (!(tmp = ft_lstnew(create_process(process, ok, recup_val(3, arena,
	&process->position)), sizeof(t_process))))
		error_msg("CAN'T MALLOC\n");
	ft_lstadd(&r->process_list, tmp);
	process->position = ++process->position % MEM_SIZE;
	return (0);
}
