/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 20:33:22 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/10 20:36:09 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compilo.h"

void	my_arg_del(void *content, size_t size)
{
	(void)size;
	if (!content)
		return ;
	if (((t_arg *)content)->arg_value)
		free(((t_arg *)content)->arg_value);
	free(content);
}

void	my_label_del(void *content, size_t size)
{
	(void)size;
	if (!content)
		return ;
	if (((t_label *)content)->name)
		free(((t_label *)content)->name);
	free(content);
}

void	my_instr_del(void *content, size_t size)
{
	(void)size;
	if (!content)
		return ;
	ft_lstdel(&((t_instr *)content)->args, &my_arg_del);
	free(content);
}

int		my_lstcmp(const t_list *cmp, const void *content, size_t size)
{
	(void)size;
	return (!ft_strcmp(content, ((t_label *)cmp->content)->name));
}
