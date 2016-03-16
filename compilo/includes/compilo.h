/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compilo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:29:56 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/16 15:41:29 by tle-meur         ###   ########.fr       */
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
	int		arg_val;
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
	int		code_byte;
	t_list	*args;
}				t_instr;

typedef struct	s_env
{
	t_header	header;
	t_list		*labels;
	t_list		*instrs;
}				t_env;

int				my_compute(char *file_name, int opt);

/*
**	utilities.c
*/
char			*jump_whitespaces(char *s);
int				is_in_buf(char c, char *buf);
char			*jump_word(char *s, char *ref);
int				frees_and_quit(char **a, char **b, int ret);
void			write_big_endian(long nb, int size, int fd, int nbr);

/*
**	lst_funcs.c
*/
void			my_arg_del(void *content, size_t size);
void			my_instrlabel_del(void *content, size_t size);
int				my_lstmerge(const t_list *label, const t_list *instr);
int				my_lstcmp(const t_list *cmp, const void *content, size_t size);

/*
**	checks/
*/
int				analyse_file_and_fill_env(t_env *e, int fd);
int				is_good_instru(t_env *e, char *s, int *byte);
int				check_indirect(t_instr *i, char **s, int id_arg);
int				check_register(t_instr *i, char **s, int id_arg);
int				check_direct(t_instr *i, char **s, int id_arg, t_arg *add);

/*
**	fill/
*/
void			write_file(t_env *e, int fd);
void			write_compilo_steps(t_env *e);
int				use_env_to_compile(t_env *e, char *file_name, int opt);

#endif
