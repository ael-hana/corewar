/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecousine <ecousine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:44:02 by ecousine          #+#    #+#             */
/*   Updated: 2016/03/31 15:48:44 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include "op.h"

extern t_op		g_op_tab[17];

int				update_pc_pos_on_failure(unsigned char *arena, t_process *pc);
void			update_pc_pos(unsigned char *are, t_process *process);
void			write_arena(t_env *data, t_process *pc, int pos, int value);
int				get_dir_value(unsigned char *are, t_process *process, int *tab);
int				get_arg_value(unsigned char *a, t_process *p, int *j, char b);
int				*get_op_args(unsigned char *arena, t_process *process);
int				get_arg_nb(char bytecode);
void			print_info(t_env *data);
void			exec_instruction(t_env *data, t_process *process);
unsigned int	live(t_env *data, t_process *process);
unsigned int	ld(t_env *data, t_process *process);
unsigned int	st(t_env *data, t_process *process);
unsigned int	add(t_env *data, t_process *process);
unsigned int	sub(t_env *data, t_process *process);
unsigned int	andd(t_env *data, t_process *process);
unsigned int	orr(t_env *data, t_process *process);
unsigned int	xorr(t_env *data, t_process *process);
unsigned int	zjmp(t_env *data, t_process *process);
unsigned int	ldi(t_env *data, t_process *process);
unsigned int	sti(t_env *data, t_process *process);
unsigned int	aff(t_env *data, t_process *process);
unsigned int	forkk(t_env *data, t_process *process);
unsigned int	lld(t_env *data, t_process *process);
unsigned int	lldi(t_env *data, t_process *process);
unsigned int	lforkk(t_env *data, t_process *process);

int				get_value(unsigned char *arena, t_process *process, int index);
int				get_ind_value(unsigned char *a, t_process *p, int *t, int i);
void			write_hex(int position, unsigned char *arena, int val);
void			get_inst(t_process *process, unsigned char *arena);
t_process		*create_process(t_process *father_process, t_header *player,
				int position);
void			start_game(t_env *data);
void			print_error(char *str);
int				str_is_digit(char *str);
int				parse_flags(int ac, char **av, t_env *data);
int				parse_players(int ac, char **av, t_env *data);
void			create_arena(t_env *data);
void			print_arena(t_env *data);
void			place_players(t_env *data);
t_header		*create_player(char *path);
void			error_msg(char *str);
t_header		*check_buf(unsigned char *str, int len);
int				str_is_digit(char *str);
int				parse_flags(int ac, char **av, t_env *data);
int				parse_players(int ac, char **av, t_env *data);
unsigned int	recup_val(int code, unsigned char *arena, int *i);
unsigned int	recup_reg_n(unsigned char *arena, int *i);
void			print_player_introduction(t_list *player_list);
int				bytecode_nb(int bytecode);

#endif
