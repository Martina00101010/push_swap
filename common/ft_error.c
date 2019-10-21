/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 02:49:55 by pberge            #+#    #+#             */
/*   Updated: 2019/10/21 15:09:20 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libps.h"
#include <stdio.h>

/*
**	in case of:
**		invalid number of arguments
*/

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

/*
**	free all when exception occures
*/

void	ft_exception(t_stack **a, t_ps **ps)
{
	if (*a != NULL)
		ft_skfree(a);
	if (ps != NULL)
		free(*ps);
	ft_error();
}

/*
**	free all at the end
*/

void	ft_end(t_stack **a, t_stack **b, t_ps **ps)
{
	ft_skfree(a);
	ft_skfree(b);
	if (ps != NULL)
		free(*ps);
}

/*
**	handle error in arguments validation
*/

void	ft_valid_error(int fd, char **line)
{
	if (line)
		free(*line);
	close(fd);
	remove("tmp");
	ft_error();
}

/*
**	handle error in applying arguments
*/

void	ft_apply_error(t_stack **a, t_stack **b)
{
	ft_skfree(a);
	ft_skfree(b);
	remove("tmp");
	ft_error();
}
