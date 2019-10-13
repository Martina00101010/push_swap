/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:45:40 by pberge            #+#    #+#             */
/*   Updated: 2019/10/13 00:14:41 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_swap(int *el, int i)
{
	int		tmp;

	tmp = el[i];
	el[i] = el[i - 1];
	el[i - 1] = tmp;
}

void	ft_push(t_stack *to, t_stack *from)
{
	int		tmp;

	to->i++;
	to->el[to->i] = from->el[from->i];
	from->el[from->i] = 0;
	from->i--;
}

/*
**	shift up all el im stack.
**	the first el becomes last
*/

void	ft_rotate(t_stack *sk)
{
	int		tmp;
	int		*el;
	int		i;

	i = sk->i;
	el = sk->el;
	tmp = el[i];
	while (i > 0)
	{
		el[i] = el[i - 1];
		i--;
	}
	el[i] = tmp;
}

/*
**	shift down all elements in stack.
**	the last el becomes first
*/

void	ft_reverse_rotate(t_stack *sk)
{
	int		tmp;
	int		*el;
	int		i;

	i = -1;
	el = sk->el;
	el[sk->i + 1] = el[0];
	while (++i < sk->i + 1)
		el[i] = el[i + 1];
	el[sk->i + 1] = 0;
}
