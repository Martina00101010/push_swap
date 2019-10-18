/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:40:09 by pberge            #+#    #+#             */
/*   Updated: 2019/10/18 07:12:37 by pberge           ###   ########.fr       */
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
**	sort
*/

void	push_swap(t_stack **a, t_stack **b, t_ps *ps)
{
	int	min;
	int	max;

	ft_min_max(*a, &min, &max);
	
	ft_linksort(a, b, ps);
//	ft_print_stacks(*a, *b);
	//ft_printf("|%s|\n", ps->out.buff);
	write(1, ps->out.buff, ps->out.i);
}
