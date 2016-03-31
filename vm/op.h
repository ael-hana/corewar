/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2016/03/30 18:28:49 by ecousine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define CLEAR_SCREEN       "\e[1;1H\e[2J"
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

# define T_REG				1
# define T_DIR				2
# define T_IND				4
# define T_LAB				8

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3
# define READ_SIZE			42

typedef char		t_arg_type;

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
	int				visual;
	int				cycle_per_sec;
	int				debug;
}					t_env;

typedef struct		s_op
{
	char			*instr_name;
	int				params_nb;
	int				params_type[3];
	int				opcode;
	int				cycles_nb;
	char			*comment;
	int				encod;
	int				index;
}					t_op;

#endif
