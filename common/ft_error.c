/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 02:49:55 by pberge            #+#    #+#             */
/*   Updated: 2019/10/19 05:53:06 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libps.h"

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
