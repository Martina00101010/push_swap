/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:40:09 by pberge            #+#    #+#             */
/*   Updated: 2019/10/15 12:58:39 by pberge           ###   ########.fr       */
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
**	pushing next patch from A according to flag
*/

void	ft_atob(t_stack **a, t_stack **b)
{
	int		median;
	int		min;
	int		max;
	char	flag;

//	ft_printf("divide\n");
	min = 0;
	max = 0;
	flag = (*a)->fl;	
	ft_min_max(*a, &min, &max);
	median = max / 2 + min;
	while (!(*a)->fl)
	{
		(*a)->fl++;
		if ((*a)->el > median)
			ft_rotate(a);
		else
			ft_push(b, a);
	}
}

/*
**	move elements less than median to stack B
**	median moves to B, too
*/

void	ft_divide(t_stack **a, t_stack **b)
{
	char	flag;

	flag = (*a)->fl;
	if (!flag)
		ft_atob(a, b);
	else
	{
		while ((*a)->fl == flag)
			ft_push(b, a);
	}
}

/*
**	splitting B by median and pushing bigger elements to A
**	until B has 3 or mere elements.
**	A looks like staircase
*/

void	ft_staircase(t_stack **a, t_stack **b)
{
	int		median;
	int		min;
	int		max;
	char	fl;
	int		k;

//	ft_printf("staircase\n");
	while ((k = ft_sklen(*b)) > 3)
	{
		fl = (*b)->fl + 1;
		ft_min_max(*b, &min, &max);
		median = (max - min) / 2 + min;
		while ((*b)->fl != fl)
		{
			(*b)->fl++;
			if ((*b)->el <= median)
				ft_rotate(b);
			else
				ft_push(a, b);
		}
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
	while ((*a)->el != min || *b != NULL)
		ft_sort(a, b, ps);
//	ft_print_stacks(*a, *b);
}
