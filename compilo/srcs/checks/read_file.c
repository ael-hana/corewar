/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:07:58 by tle-meur          #+#    #+#             */
/*   Updated: 2016/03/16 15:41:58 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compilo.h"

static int	my_trash(char *bufs[3], int *type, int *size)
{
	char	*buf_tmp;

	if (!(*type % 2))
	{
		if (*size + 1 > ((*type < 3) ? PROG_NAME_LENGTH : COMMENT_LENGTH)
		|| !(buf_tmp = (char *)ft_memrealloc(bufs[1], *size, *size + 1)))
			return (0);
		bufs[1] = buf_tmp;
		bufs[1][(*size)++] = '\n';
	}
	return (1);
}

static int	fill_comment(char *bufs[3], int *type, int *size, int *nb)
{
	int		len;
	char	*buf_tmp;

	if (!my_trash(bufs, type, size))
		return (0);
	if (!**bufs || (!(len = 0) && *type % 2 && *(bufs[0]++) != '"'))
		return ((!**bufs) ? 1 : 0);
	(*type) += (*type % 2) ? 1 : 0;
	while (bufs[0][len] && bufs[0][len] != '"')
		len++;
	if (!(buf_tmp = NULL) && !len && bufs[0][len] != '"')
		return (1);
	if (len + *size > ((*type < 3) ? PROG_NAME_LENGTH : COMMENT_LENGTH)
		|| !(buf_tmp = (char *)ft_memrealloc(bufs[1], *size, len + *size)))
		return (0);
	ft_memcpy((bufs[1] = buf_tmp) + *size, bufs[0], len);
	if (((*size += len) || 1) && bufs[0][len] == '"'
		&& ((bufs[0] = jump_whitespaces(bufs[0] + len + 1)) || 1))
	{
		if ((**bufs && !is_in_buf(**bufs, COMMENT_CHARS)))
			return (0);
		ft_memcpy(bufs[2], bufs[1], *size);
		frees_and_quit(&bufs[1], NULL, (++(*nb)) ? (*type = (*size *= 0)) : 0);
	}
	return (1);
}

/*
**	bufs :
**		bufs[0] = tmp
**		bufs[1] = buf_tmp
**		bufs[2] = e->header.?
**	vars :
**		vars[0] = nb
**		vars[1] = len
**		vars[2] = type
**		vars[3] = ret
*/

static int	get_header(t_env *e, int fd, char *line, int i)
{
	int		vars[4];
	char	*bufs[3];

	ft_memset(vars, 0, 4 * sizeof(int));
	ft_memset(bufs, 0, 3 * sizeof(char *));
	while ((vars[3] = ft_gnl(fd, &line)) > 0 && ++i)
	{
		*bufs = jump_whitespaces(line);
		if (!vars[2] && (is_in_buf(**bufs, COMMENT_CHARS) || !**bufs))
			continue ;
		if (!ft_strncmp(*bufs, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING))
			&& vars[2] < 2 && !*(bufs[2] = e->header.prog_name))
			*bufs = jump_word(*bufs, NAME_CMD_STRING)
			+ (vars[2] -= vars[2] - 1) * 0;
		else if (!ft_strncmp(*bufs, COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)) && (!vars[2] || vars[2] > 2)
			&& !*(bufs[2] = e->header.comment))
			*bufs = jump_word(*bufs, COMMENT_CMD_STRING)
			+ (vars[2] -= vars[2] - 3) * 0;
		else if (!vars[2])
			return (frees_and_quit(&bufs[1], &line, 0));
		if (!(fill_comment(bufs, &vars[2], &vars[1], vars)) || *vars == 2)
			return (frees_and_quit(&bufs[1], &line, (*vars == 2) ? 1 : 0));
	}
	return (frees_and_quit(&bufs[1], &line, (vars[3] == -1) ? -1 : *vars == 2));
}

static int	is_label(t_env *e, char **s, int byte)
{
	t_label	add;
	int		len;
	t_list	*tmp;

	len = 0;
	while ((*s)[len] && (*s)[len] != LABEL_CHAR)
		if (!is_in_buf((*s)[len++], LABEL_CHARS))
			return (1);
	if (!(*s)[len])
		return (1);
	if (!(add.name = (char *)ft_strnew(len * sizeof(char))))
		return (0);
	ft_memcpy(add.name, (*s), len);
	if ((tmp = ft_lstfind(e->labels, add.name, sizeof(t_label), &my_lstcmp)))
		return (frees_and_quit(&add.name, NULL, 0));
	add.byte = byte;
	if (!(tmp = ft_lstnew(&add, sizeof(t_label))))
		return (frees_and_quit(&add.name, NULL, 0));
	ft_lstpush(&e->labels, tmp);
	*s = jump_whitespaces((*s) + len + 1);
	return (1);
}

int			analyse_file_and_fill_env(t_env *e, int fd)
{
	int		ret;
	char	*tmp;
	int		byte;
	char	*line;

	if (!get_header(e, fd, NULL, 0))
		return (0);
	byte = 0;
	line = NULL;
	while ((ret = ft_gnl(fd, &line)) > 0)
	{
		tmp = jump_whitespaces(line);
		if (!*tmp || is_in_buf(*tmp, COMMENT_CHARS))
			continue ;
		if (!is_label(e, &tmp, byte))
			return (frees_and_quit(&line, NULL, 0));
		if (!*tmp || is_in_buf(*tmp, COMMENT_CHARS))
			continue ;
		if (!is_good_instru(e, tmp, &byte))
			return (frees_and_quit(&line, NULL, 0));
	}
	e->header.prog_size = byte;
	e->header.magic = COREWAR_EXEC_MAGIC;
	ft_memdel((void **)&line);
	return (frees_and_quit(&line, NULL, ret + 1));
}
