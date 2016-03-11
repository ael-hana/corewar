/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compilo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:29:56 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/10 20:45:19 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPILO_H
# define COMPILO_H

# include "op.h"
# include "libft.h"

typedef struct	s_arg
{
	int		arg_type;
	char	*arg_value;
}				t_arg;

typedef struct	s_label
{
	int		byte;
	char	*name;
}				t_label;

typedef struct	s_instr
{
	int		byte;
	int		id_instr;
	t_list	*args;
}				t_instr;

typedef struct	s_env
{
	t_header	header;
	t_list		*labels;
	t_list		*instrs;
}				t_env;

/*
**	utilities.c
*/
char			*jump_whitespaces(char *s);
int				is_in_buf(char c, char *buf);

/*
**	lst_funcs.c
*/
void			my_arg_del(void *content, size_t size);
void			my_label_del(void *content, size_t size);
void			my_instr_del(void *content, size_t size);
int				my_lstcmp(const t_list *cmp, const void *content, size_t size);

int				my_compute(char *file_name, int opt);
void			use_env_to_compile(t_env *e, int opt);
int				analyse_file_and_fill_env(t_env *e, int fd);
int				is_good_instru(t_env *e, char *s, int *byte);

#endif
