/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2016/03/23 18:37:46 by ael-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"
# define ERR_PARAM "./corewar [-dump nbr_cycles] [[-n number] champion.cor]..\n"

# define IND_SIZE			2
# define REG_SIZE			4
# define DIR_SIZE			REG_SIZE

# define REG_CODE			1
# define DIR_CODE			2
# define IND_CODE			3

# define MAX_ARGS_NUMBER	4
# define MAX_PLAYERS		4
# define MEM_SIZE			(4*1024)
# define IDX_MOD			(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)

# define COMMENT_CHARS		"#;"
# define LABEL_CHAR			':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define LABEL_CHARS		"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING	".name"
# define COMMENT_CMD_STRING	".comment"

# define REG_NUMBER			16

# define CYCLE_TO_DIE		1536
# define CYCLE_DELTA		50
# define NBR_LIVE			21
# define MAX_CHECKS			10

typedef char		t_arg_type;

# define T_REG				1
# define T_DIR				2
# define T_IND				4
# define T_LAB				8

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3
# define READ_SIZE			42


typedef struct		s_header
{
	unsigned int	magic;
	char			numb;
	unsigned short	n;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	unsigned char	*inst;
	char			comment[COMMENT_LENGTH + 1];
	int				alive;
	int				last_alive;
}					t_header;

typedef struct		s_process
{
	t_header		*player;
	int				cycle;
	int				op;
	int				carry;
	int				reg[16];
	int				position;
	int				alive;
	int				last_alive;
}					t_process;

typedef struct		s_env
{
	int				i;
	int				dump;
	int				nb_players;
	t_list			*player_list;
	t_list			*process_list;
	int				total_live;
	int				live_last_verif;
	unsigned char	*arena;
	unsigned char	*arena_owner;
	int				cycle;
	int				cycle_to_die;
	int				cycle_of_last_verif;
}					t_env;

typedef struct		s_op
{
	char			*instr_name;
	int				params_nb;
	int				params_type[3];
	int				opcode;
	int				cycles_nb;
	char			*comment;
	int				encod; //byte encodage
	int				index; //index = 2 sans = 4
}					t_op;

extern t_op			op_tab[17];

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
unsigned int	ldi(unsigned char *arena, t_process *process);
unsigned int	sti(t_env *data, t_process *process);
unsigned int	aff(t_env *data, t_process *process);
unsigned int	forkk(t_env *data, t_process *process);
unsigned int	lfork(t_env *data, t_process *process);
unsigned int	lld(unsigned char *arena, t_process *process);

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

#endif
