/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:09:23 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/11 18:10:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compilo.h"

extern t_op	g_op_tab[17];

static void	write_first_line(t_env *e, t_instr *i, t_instr *next)
{
	t_arg	*a;
	t_list	*tmp;

	ft_printf("%-4d (%-3d) :\t    %-9s ", i->byte,
	((next) ? (unsigned int)next->byte : e->header.prog_size) - i->byte,
	g_op_tab[i->id_instr].instr_name);
	tmp = i->args;
	while (tmp && (a = (t_arg *)tmp->content))
	{
		if (a->arg_type == REG_CODE)
			ft_printf("r%-15s  ", a->arg_value);
		else if (a->arg_type == IND_CODE)
			ft_printf("%-16s  ", a->arg_value);
		else if (a->arg_type & T_LAB)
			ft_printf("%c%c%-14s  ", DIRECT_CHAR, LABEL_CHAR, a->arg_value);
		else
			ft_printf("%c%-15s  ", DIRECT_CHAR, a->arg_value);
		tmp = tmp->next;
	}
}

static void	write_second_line(t_instr *i)
{
	t_list	*tmp;

	ft_printf("\t\t    %-4d", g_op_tab[i->id_instr].opcode);
	if (g_op_tab[i->id_instr].code_byte)
		ft_printf("%-4d", i->code_byte);
	else
		ft_putstr("    ");
	ft_putstr("  ");
	tmp = i->args;
	while (tmp)
	{
		if (((t_arg *)tmp->content)->arg_type == REG_CODE)
			ft_printf("%-16d", ((t_arg *)tmp->content)->arg_val);
		else if (((t_arg *)tmp->content)->arg_type == IND_CODE)
			write_big_endian(((t_arg *)tmp->content)->arg_val, 2, 0, 1);
		else if (!(((t_arg *)tmp->content)->arg_type & T_LAB)
			&& !g_op_tab[i->id_instr].is_index)
			write_big_endian(((t_arg *)tmp->content)->arg_val, 4, 0, 1);
		else
			write_big_endian(((t_arg *)tmp->content)->arg_val, 2, 0, 1);
		ft_putstr("  ");
		tmp = tmp->next;
	}
}

static void	write_third_line(t_instr *i)
{
	t_list	*tmp;

	ft_printf("\t\t    %-4d", g_op_tab[i->id_instr].opcode);
	if (g_op_tab[i->id_instr].code_byte)
		ft_printf("%-4d", i->code_byte);
	else
		ft_putstr("    ");
	ft_putstr("  ");
	tmp = i->args;
	while (tmp)
	{
		ft_printf("%-16d  ", ((t_arg *)tmp->content)->arg_val);
		tmp = tmp->next;
	}
}

static void	write_instr(t_env *e, t_instr *i, t_list *next)
{
	write_first_line(e, i, (next) ? next->content : next);
	ft_putchar('\n');
	write_second_line(i);
	ft_putchar('\n');
	write_third_line(i);
	ft_putchar('\n');
	ft_putchar('\n');
}

void		write_compilo_steps(t_env *e)
{
	t_list	*tmp;
	t_list	*prev;

	ft_lstmerge(&e->labels, e->instrs, &my_lstmerge);
	prev = e->labels;
	if ((e->instrs = NULL) || prev->content_size == sizeof(t_label))
		ft_printf("%-4d       :\t%s%c\n", ((t_label *)prev->content)->byte,
		((t_label *)prev->content)->name, LABEL_CHAR);
	else
		write_instr(e, prev->content, prev->next);
	while ((tmp = prev->next))
	{
		if (tmp->content_size == sizeof(t_label))
			ft_printf("%-4d       :\t%s%c\n", ((t_label *)tmp->content)->byte,
			((t_label *)tmp->content)->name, LABEL_CHAR);
		else
			write_instr(e, tmp->content, tmp->next);
		prev = tmp;
	}
}
