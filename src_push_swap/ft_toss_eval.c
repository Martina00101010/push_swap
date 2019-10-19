/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toss_eval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 03:24:56 by pberge            #+#    #+#             */
/*   Updated: 2019/10/19 03:29:42 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

/*
**	pushes min to bottom of stack
**	sorts other two values in ascending order
*/

void	ft_three_a(t_stack **a, t_out *out, int min)
{
	if ((*a)->el == min)
		ft_rotate(a, out, "ra\n");
	else if ((*a)->prev->el == min)
		ft_reverse_rotate(a, out, "rra\n");
	else if ((*a)->next->el == min)
		;
	ft_two(a, out);
}

/*
**	pushes all to temporary stack (B)
**	remains min, max and one random value in stackA
*/

void	ft_toss(t_stack **a, t_stack **b, t_out *out)
{
	int		min;
	int		max;

	ft_min_max(*a, &min, &max);
	while (ft_sklen(*a) > 3)
	{
		if ((*a)->el != min && (*a)->el != max)
			ft_push(b, a, out, "pb\n");
		else
			ft_rotate(a, out, "ra\n");
	}
	ft_three_a(a, out, min);
}

/*
**	counts steps and finds shortest way to rotate stack A
*/

int	ft_steps_a(t_stack *a, t_stack *link)
{
	t_stack	*tmp;
	int	i;
	int	j;

	j = 0;
	i = 0;
	tmp = a;
	while (tmp->el < link->el)
	{
		i++;
		tmp = tmp->prev;
	}
	tmp = a;
	while (tmp->next->el > link->el)
	{
		j++;
		tmp = tmp->next;
	}
	link->afl = (i >= j) ? 0 : 1;
	return (i < j ? j : i);
}

/*
**	evaluates the number of operations for each element
*/

t_stack	*ft_eval(t_stack **a, t_stack **b, int j)
{
	t_stack	*link;
	int		head;
	int		steps;
	int		min;
	int		i;

	i = 0;
	min = 2147483647;
	head = (*b)->el;
	while (1)
	{
		steps = ft_steps_a(*a, *b) + (i < j ? i : j);
		if (steps < min)
		{
			link = *b;
			min = steps;
		}
		(*b)->bfl = (i++ < j--) ? 0 : 1;
		*b = (*b)->prev;
		if ((*b)->el == head)
			break ;
	}
	return (link);
}
