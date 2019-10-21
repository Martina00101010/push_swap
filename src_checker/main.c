/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:32:49 by pberge            #+#    #+#             */
/*   Updated: 2019/10/21 14:22:34 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

static int	ft_get_op(char **op, char *line)
{
	while (*op)
	{
		if (ft_strcmp(*op, line) == 0)
			return (1);
		op++;
	}
	return (0);
}

static int	ft_endnl(int fd)
{
	char	buff[BUFF_SIZE1 + 1];
	int		rd;

	lseek(fd, -1, SEEK_END);
	ft_bzero(buff, BUFF_SIZE1 + 1);
	rd = read(fd, buff, 1);
	if (buff[0] != '\n')
		return (0);
	return (1);
}

static int	ft_valid(char *buff)
{
	char	**op;
	char	*line;
	int		i;
	int		fd;

	if ((fd = open("tmp", O_RDONLY)) < 0)
		ft_error();
	op = (char *[]){ "sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr", 0 };
	line = NULL;
	i = 0;
	while ((i = get_next_line(fd, &line)))
	{
		if (i == -1)
			ft_valid_error(fd, &line);
		if (!ft_get_op(op, line))
			ft_valid_error(fd, &line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (!ft_endnl(fd))
		ft_valid_error(fd, NULL);
	close(fd);
	return (1);
}

static void	ft_read(t_out *out, t_stack **a)
{
	char	buff[BUFF_SIZE1 + 1];
	int		rd;
	int		fd;

	chmod("tmp", 0644);
	if ((fd = open("tmp", O_RDWR | O_CREAT)) < 0)
		ft_exception(a, NULL);
	chmod("tmp", 0644);
	rd = 0;
	ft_bzero(&buff, BUFF_SIZE1 + 1);
	while ((rd = read(0, &buff, BUFF_SIZE1)) > 0)
	{
		buff[rd] = '\0';
		out->i += rd;
		write(fd, buff, BUFF_SIZE1);
	}
	close(fd);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_out	out;
	int		n;

	a = NULL;
	b = NULL;
	if (argc == 1)
	{
		ft_printf("usage: ./checker numbers\n");
		return (0);
	}
	ft_bzero(&out, sizeof(t_out));
	ft_fill_sk(&a, argv + 1, argc - 1);
	ft_read(&out, &a);
	if (out.i > 0 && !ft_valid(out.buff))
		ft_exception(&a, NULL);
	if (out.i > 0)
		ft_apply(&out, &a, &b);
	ft_answer(&a, &b);
	ft_end(&a, &b, NULL);
	return (0);
}
