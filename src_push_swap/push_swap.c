/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:40:09 by pberge            #+#    #+#             */
/*   Updated: 2019/10/17 04:48:37 by pberge           ###   ########.fr       */
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

void	ft_atob(t_stack **a, t_stack **b, t_out *out)
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
			ft_rotate(a, out, "ra\n");
		else
			ft_push(b, a, out, "pb\n");
	}
}

/*
**	that's a crazy func and it won't be changed
**				because I like it!
**	the first time it splits stack A
**	the next time it pushes patches from A to B
*/

void	ft_divide(t_stack **a, t_stack **b, t_out *out, char *op)
{
	char	flag;

	flag = (*a)->fl;
	if (flag == 0)
		ft_atob(a, b, out);
	else
	{
		while ((*a)->fl == flag)
			ft_push(b, a, out, "pb\n");
	}
}

/*
**	splitting B by median and pushing bigger elements to A
**	until B has 3 or mere elements.
**	A looks like staircase
*/

void	ft_staircase(t_stack **a, t_stack **b, t_out *out, char *op)
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
		out->flag++;
		while ((*b)->fl != fl)
		{
			(*b)->fl++;
//			ft_printf("%i\n", median);
//			ft_print_stacks(*a, *b);
			if ((*b)->el <= median)
				ft_rotate(b, out, "rb\n");
			else
			{
				(*b)->fl = out->flag;
				ft_push(a, b, out, "pa\n");
			}
//			ft_print_stacks(*a, *b);
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
	while ((*a)->el != min || *b != NULL || ft_issorted(*a) == 0)
		ft_sort(a, b, ps);
	ft_print_stacks(*a, *b);
//	ft_printf("%s\n", ps->out.buff);
}
