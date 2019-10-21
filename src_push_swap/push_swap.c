/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:40:09 by pberge            #+#    #+#             */
/*   Updated: 2019/10/21 11:35:37 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_min_max(t_stack *sk, int *min, int *max)
{
	t_stack	*head;

	head = sk;
	*min = sk->el;
	*max = sk->el;
	sk = sk->prev;
	while (sk != head)
	{
		if (sk->el < *min)
			*min = sk->el;
		if (sk->el > *max)
			*max = sk->el;
		sk = sk->prev;
	}
}

/*
**	sorts two elements
*/

void	ft_two(t_stack **a, t_out *out)
{
	if ((*a)->el > (*a)->prev->el)
		ft_swap(a, out, "sa\n");
}

/*
**	sorts stack of length three
*/

void	ft_three(t_stack **a, t_out *out)
{
	t_stack *sk;

	sk = *a;
	if (sk->next->el > sk->el && sk->next->el > sk->prev->el)
		;
	else if (sk->el > sk->next->el && sk->el > sk->prev->el)
		ft_rotate(a, out, "ra\n");
	else if (sk->prev->el > sk->el && sk->prev->el > sk->next->el)
		ft_reverse_rotate(a, out, "rra\n");
	ft_two(a, out);
}

/*
**	sort
*/

void	push_swap(t_stack **a, t_stack **b, t_ps *ps)
{
	int	min;
	int	max;

	ft_min_max(*a, &min, &max);
	if (ps->bsize == 1)
		return ;
	else if (ps->bsize == 2)
		ft_two(a, &ps->out);
	else if (ps->bsize == 3)
		ft_three(a, &ps->out);
	else
		ft_linksort(a, b, ps);
	write(1, ps->out.buff, ps->out.i);
}
