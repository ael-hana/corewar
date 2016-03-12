/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:58:50 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/11 19:50:02 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "compilo.h"

extern t_op	g_op_tab[17];

int	check_register(t_instr *i, char **s, int id_arg)
{
	int	len;
	int	ind;

	if (!(g_op_tab[i->id_instr].params_type[id_arg] & T_REG))
		return (0);
	if (**s != 'r')
		return (0);
	len = 0;
	ind = ft_atoi((*s) + ++len);
	if (ind <= 0 || ind > REG_NUMBER)
		return (0);
	while (ft_isdigit((*s)[len]))
		len++;
	if ((*s)[len] && (*s)[len] != SEPARATOR_CHAR && (*s)[len] != ' '
			&& (*s)[len] != '\t' && !is_in_buf((*s)[len], COMMENT_CHARS))
		return (0);
	(*s)++;
	return (1);
}

int	check_direct(t_instr *i, char **s, int id_arg)
{
	int	nb;
	int	len;

	if ((len = 0) || !(g_op_tab[i->id_instr].params_type[id_arg] & T_DIR)
			|| **s != DIRECT_CHAR)
		return (0);
	if ((*s)[++len] == LABEL_CHAR && len++)
		while ((*s)[len] && is_in_buf((*s)[len], LABEL_CHARS))
			len++;
	else
	{
		nb = ft_atoi((*s) + len);
		if (g_op_tab[i->id_instr].is_index && (nb < SHRT_MIN || nb > SHRT_MAX))
			return (0);
		len += ((*s)[len] == '-' || (*s)[len] == '+') ? 1 : 0;
		while ((*s)[len] && ft_isdigit((*s)[len]))
			len++;
	}
	if (!len || ((*s)[len] && (*s)[len] != SEPARATOR_CHAR && (*s)[len] != ' '
				&& (*s)[len] != '\t' && !is_in_buf((*s)[len], COMMENT_CHARS)))
		return (0);
	(*s) += ((*s)[1] == LABEL_CHAR) ? 2 : 1;
	return (1);
}


int	check_indirect(t_instr *i, char **s, int id_arg)
{
	int	nb;
	int	len;

	if ((len = 0) || !(g_op_tab[i->id_instr].params_type[id_arg] & T_IND)
			|| **s != DIRECT_CHAR)
		return (0);
	if ((*s)[++len] == LABEL_CHAR && len++)
		while ((*s)[len] && is_in_buf((*s)[len], LABEL_CHARS))
			len++;
	else
	{
		nb = ft_atoi((*s) + len);
		if (nb < SHRT_MIN || nb > SHRT_MAX)
			return (0);
		len += ((*s)[len] == '-' || (*s)[len] == '+') ? 1 : 0;
		while ((*s)[len] && ft_isdigit((*s)[len]))
			len++;
	}
	if (!len || ((*s)[len] && (*s)[len] != SEPARATOR_CHAR && (*s)[len] != ' '
				&& (*s)[len] != '\t' && !is_in_buf((*s)[len], COMMENT_CHARS)))
		return (0);
	(*s) += ((*s)[1] == LABEL_CHAR) ? 2 : 1;
	return (1);
}
