/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instru.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 20:11:57 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/10 20:44:28 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compilo.h"

extern t_op	g_op_tab[17];

static int		is_real_instru(char **s)
{
	int	i;
	int	len;

	i = -1;
	while (g_op_tab[++i].instr_name)
	{
		len = ft_strlen(g_op_tab[i].instr_name);
		if (!ft_strncmp(*s, g_op_tab[i].instr_name, len))
		{
			if ((*s)[len] != ' ' && (*s)[len] != '\t')
				continue ;
			(*s) = jump_whitespaces((*s) + len);
			return (i);
		}
	}
	return (-1);
}

static t_list	*check_args(t_instr *i, char *s, int *byte, int id_arg)
{
	if (!*s || is_in_buf(*s, COMMENT_CHARS))
		return (i->args);
	if (id_arg >= g_op_tab[i->id_instr].params_nb)
	{
		ft_lstdel(&i->args, &my_arg_del);
		return (NULL);
	}
	(void)byte;
	return (i->args);
}

int				is_good_instru(t_env *e, char *s, int *byte)
{
	int		id;
	t_instr	add;
	t_list	*tmp;

	if ((id = is_real_instru(&s)) == -1)
		return (0);
	add.byte = *byte;
	add.id_instr = id;
	if (!(add.args = check_args(&add, s, byte, 0)))
		return (0);
	if (!(tmp = ft_lstnew(&add, sizeof(t_instr))))
	{
		ft_lstdel(&add.args, &my_arg_del);
		return (0);
	}
	ft_lstpush(&e->instrs, tmp);
	return (1);
}
