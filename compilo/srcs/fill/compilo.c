/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compilo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:09:23 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/11 18:10:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "compilo.h"

static int	check_good_labels(t_env *e)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	(void)tmp3;
	tmp1 = e->instrs;
	while (tmp1)
	{
		tmp2 = ((t_instr *)tmp1->content)->args;
		while (tmp2)
		{
			if (((t_arg *)tmp2->content)->arg_type & T_LAB)
			{
				if (!(tmp3 = ft_lstfind(e->labels,
					((t_arg *)tmp2->content)->arg_value, sizeof(t_label),
					&my_lstcmp)))
					return (0);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

static int	find_code_byte(t_list *tmp)
{
	int	i;
	int	nb;

	i = 6;
	nb = 0;
	while (tmp)
	{
		if (((t_arg *)tmp->content)->arg_type & T_LAB)
			nb += ((((t_arg *)tmp->content)->arg_type - T_LAB) << i);
		else
			nb += (((t_arg *)tmp->content)->arg_type << i);
		tmp = tmp->next;
		i -= 2;
	}
	return (nb);
}

static void	prepare_code(t_env *e)
{
	t_arg	*a;
	t_instr	*i;
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp1 = e->instrs;
	while (tmp1 && (i = ((t_instr *)tmp1->content)))
	{
		i->code_byte = find_code_byte(i->args);
		tmp2 = ((t_instr *)tmp1->content)->args;
		while (tmp2 && (a = (t_arg *)tmp2->content)
			&& ((tmp2 = tmp2->next) || 1))
			if (a->arg_type == REG_CODE || a->arg_type == IND_CODE
				|| !(a->arg_type & T_LAB))
				a->arg_val = ft_atoi(a->arg_value);
			else
			{
				tmp3 = ft_lstfind(e->labels, a->arg_value,
				sizeof(t_label), &my_lstcmp);
				a->arg_val = ((t_label *)tmp3->content)->byte - i->byte;
			}
		tmp1 = tmp1->next;
	}
}

int			use_env_to_compile(t_env *e, char *file_name, int opt)
{
	int	fd;

	if (!file_name || !check_good_labels(e))
	{
		ft_memdel((void **)&file_name);
		return (0);
	}
	prepare_code(e);
	if (!opt)
	{
		if ((fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR + S_IWUSR
						+ S_IRGRP + S_IWGRP + S_IROTH)) == -1)
		{
			ft_memdel((void **)&file_name);
			return (0);
		}
		write_file(e, fd);
		if ((fd = close(fd)) == -1)
			ft_printf("Can't close source file %s\nBe carreful !!!\n", file_name);
	}
	else
		write_compilo_steps(e);
	ft_memdel((void **)&file_name);
	return (1);
}
