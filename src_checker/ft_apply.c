/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:49:20 by pberge            #+#    #+#             */
/*   Updated: 2019/10/21 13:39:23 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static void	ft_cmp1(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "ra") == 0)
		ft_rotate(a, NULL, NULL);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rotate(b, NULL, NULL);
	else if (ft_strcmp(line, "rr") == 0)
	{
		ft_rotate(a, NULL, NULL);
		ft_rotate(b, NULL, NULL);
	}
	else if (ft_strcmp(line, "rra") == 0)
		ft_reverse_rotate(a, NULL, NULL);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_reverse_rotate(b, NULL, NULL);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		ft_reverse_rotate(a, NULL, NULL);
		ft_reverse_rotate(b, NULL, NULL);
	}
	else
		return ;
}

static void	ft_cmp0(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_swap(a, NULL, NULL);
	else if (ft_strcmp(line, "sb") == 0)
		ft_swap(b, NULL, NULL);
	else if (ft_strcmp(line, "ss") == 0)
	{
		ft_swap(a, NULL, NULL);
		ft_swap(b, NULL, NULL);
	}
	else if (ft_strcmp(line, "pa") == 0)
		ft_push(a, b, NULL, NULL);
	else if (ft_strcmp(line, "pb") == 0)
		ft_push(b, a, NULL, NULL);
	else
		return ;
}

void		ft_apply(t_out *out, t_stack **a, t_stack **b)
{
	char	*line;
	int		fd;

	if ((fd = open("tmp", O_RDONLY)) < 0)
		ft_apply_error(a, b);
	while (get_next_line(fd, &line))
	{
		ft_cmp0(line, a, b);
		ft_cmp1(line, a, b);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	remove("tmp");
}
