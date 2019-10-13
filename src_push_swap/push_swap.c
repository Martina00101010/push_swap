/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:40:09 by pberge            #+#    #+#             */
/*   Updated: 2019/10/13 12:11:52 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>

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
**	move elements less than median to stack B
**	median moves to B, too
*/

void	ft_divide(t_stack **a, t_stack **b)
{
	int		median;
	int		min;
	int		max;

	min = 0;
	max = 0;
	ft_min_max(*a, &min, &max);
	median = max / 2 + min;
	ft_printf("*********************\n");
	ft_printf("median %i\n", median);
	while (1)
	{
		(*a)->fl = 1;
		if ((*a)->el > median)
			ft_rotate(a);
		else
			ft_push(b, a);
		if ((*a)->fl == 1)
			break ;
	}
	ft_print_stacks(*a, *b);
}

/*
**	counting size of stack B
*/

int		ft_len(t_stack **b)
{
	t_stack	*tmp;
	int		len;

	len = 0;
	tmp = (*b)->prev;
	while (tmp != *b)
	{
		tmp = tmp->prev;
		len++;
	}
	return (len > 2 ? 1 : 0);
}

/*
**	splitting B by median and pushing bigger elements to A
**	untill B has 3 or mere elements
*/

void	ft_staircase(t_stack **a, t_stack **b)
{
	int		median;
	int		min;
	int		max;
	char	fl;
	int		k;

	k = 4;
	fl = 2;
	while (ft_len(b))
	{
		ft_min_max(*b, &min, &max);
		median = (max - min) / 2 + min;
		ft_printf("median %i\n", median);
		while ((*b)->fl != fl)
		{
			(*b)->fl = fl;
			if ((*b)->el <= median)
				ft_rotate(b);
			else
				ft_push(a, b);
		}
		ft_print_stacks(*a, *b);
		fl++;
	}
}

/*
**	sort
*/

void	push_swap(t_stack **a, t_stack **b)
{
	ft_divide(a, b);
	ft_printf("\n");
	ft_staircase(a, b);
	ft_printf("sorted %i\n", ft_issorted(*b));
	if (ft_issorted(*b))
		ft_three(a, b);
	ft_print_stacks(*a, *b);
}
