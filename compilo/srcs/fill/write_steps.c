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

static void	write_first_line(t_instr *i)
{
	t_arg	*a;
	int		ret;
	t_list	*tmp;

	ft_printf("%s\t", g_op_tab[i->id_instr].instr_name);
	tmp = i->args;
	while (tmp && (a = (t_arg *)tmp->content))
	{
		if (a->arg_type == REG_CODE)
			ret = ft_printf("r%s", a->arg_value);
		else if (a->arg_type == IND_CODE)
			ret = ft_printf("%s", a->arg_value);
		else if (a->arg_type & T_LAB)
			ret = ft_printf("%c%c%s", DIRECT_CHAR, LABEL_CHAR, a->arg_value);
		else
			ret = ft_printf("%c%s", DIRECT_CHAR, a->arg_value);
		if (tmp->next)
		{
			ft_putchar('\t');
			if (ret < 4 && a->arg_type == DIR_CODE && !(a->arg_type & T_LAB)
				&& !g_op_tab[i->id_instr].is_index)
				ft_putchar('\t');
		}
		tmp = tmp->next;
	}
}

static void	write_second_line(t_instr *i)
{
	t_list	*tmp;

	ft_printf("%02hhx", g_op_tab[i->id_instr].opcode);
	if (g_op_tab[i->id_instr].code_byte)
		ft_printf(" %02hhx", i->code_byte);
	ft_putchar('\t');
	tmp = i->args;
	while (tmp)
	{
		if (((t_arg *)tmp->content)->arg_type == REG_CODE)
			ft_printf("%02hhx", ((t_arg *)tmp->content)->arg_val);
		else if (((t_arg *)tmp->content)->arg_type == IND_CODE)
			write_big_endian(((t_arg *)tmp->content)->arg_val, 2, 0, 1);
		else if (!(((t_arg *)tmp->content)->arg_type & T_LAB)
			&& !g_op_tab[i->id_instr].is_index)
			write_big_endian(((t_arg *)tmp->content)->arg_val, 4, 0, 1);
		else
			write_big_endian(((t_arg *)tmp->content)->arg_val, 2, 0, 1);
		if (tmp->next)
			ft_putchar('\t');
		tmp = tmp->next;
	}
}

static void	write_third_line(t_instr *i)
{
	int		ret;
	t_list	*tmp;

	ft_printf("%02hhx", g_op_tab[i->id_instr].opcode);
	if (g_op_tab[i->id_instr].code_byte)
		ft_printf(" %02x", i->code_byte);
	ft_putchar('\t');
	tmp = i->args;
	while (tmp)
	{
		if (((t_arg *)tmp->content)->arg_type == REG_CODE)
			ret = ft_printf("%02hhx", ((t_arg *)tmp->content)->arg_val);
		else
			ret = ft_printf("%d", ((t_arg *)tmp->content)->arg_val);
		if (tmp->next)
		{
			ft_putchar('\t');
			if (ret < 4 && ((t_arg *)tmp->content)->arg_type == DIR_CODE
				&& !(((t_arg *)tmp->content)->arg_type & T_LAB)
				&& !g_op_tab[i->id_instr].is_index)
				ft_putchar('\t');
		}
		tmp = tmp->next;
	}
}

static void	write_instr(t_instr *i)
{
	write_first_line(i);
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
		ft_printf("%s (%d) %c\n", ((t_label *)prev->content)->name,
		((t_label *)prev->content)->byte, LABEL_CHAR);
	else
		write_instr(prev->content);
	while ((tmp = prev->next))
	{
		if (tmp->content_size == sizeof(t_label))
		{
			if (prev->content_size != sizeof(t_label))
				ft_putchar('\n');
			ft_printf("%s (%d) %c\n", ((t_label *)tmp->content)->name,
			((t_label *)tmp->content)->byte, LABEL_CHAR);
		}
		else
			write_instr(tmp->content);
		prev = tmp;
	}
}
