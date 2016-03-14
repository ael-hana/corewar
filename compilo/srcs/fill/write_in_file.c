/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:09:23 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/11 18:10:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "compilo.h"

extern t_op	g_op_tab[17];

static void	write_header(t_env *e, int fd)
{
	int	i;
	int	empty;

	empty = 0;
	write_big_endian(e->header.magic, 4, fd, 0);
	i = -1;
	while (++i < PROG_NAME_LENGTH)
		write(fd, &e->header.prog_name[i], 1);
	write(fd, &empty, 4);
	write_big_endian(e->header.prog_size, 4, fd, 0);
	i = -1;
	while (++i < COMMENT_LENGTH)
		write(fd, &e->header.comment[i], 1);
	write(fd, &empty, 4);
}

void		write_file(t_env *e, int fd)
{
	t_arg	*a;
	t_instr	*i;
	t_list	*tmp1;
	t_list	*tmp2;

	write_header(e, fd);
	tmp1 = e->instrs;
	while (tmp1 && (i = (t_instr *)tmp1->content)
		&& ((tmp1 = tmp1->next) || 1))
	{
		write(fd, &g_op_tab[i->id_instr].opcode, 1);
		if ((tmp2 = i->args) && g_op_tab[i->id_instr].code_byte)
			write(fd, &i->code_byte, 1);
		while (tmp2 && (a = (t_arg *)tmp2->content)
			&& ((tmp2 = tmp2->next) || 1))
		{
			if (a->arg_type == REG_CODE || a->arg_type == IND_CODE)
				write_big_endian(a->arg_val,
				(a->arg_type == REG_CODE) ? 1 : 2, fd, 0);
			else
				write_big_endian(a->arg_val,
				(g_op_tab[i->id_instr].is_index) ? 2 : 4, fd, 0);
		}
	}
}
