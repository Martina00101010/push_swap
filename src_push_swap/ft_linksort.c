/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linksort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 05:00:16 by pberge            #+#    #+#             */
/*   Updated: 2019/10/17 07:01:43 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_two_a(t_stack **a, t_out *out)
{
	if ((*a)->el > (*a)->prev->el)
		ft_swap(a, out, "sa\n");
}

void	ft_three_a(t_stack **a, t_out *out, int min)
{
	if ((*a)->el == min)
		ft_rotate(a, out, "ra\n");
	else if ((*a)->prev->el == min)
		ft_reverse_rotate(a, out, "rra\n");
	else if ((*a)->next->el == min)
		;
	ft_two_a(a, out);
}

void	ft_toss(t_stack **a, t_stack **b, t_out *out)
{
	int		min;
	int		max;

	ft_min_max(*a, &min, &max);
	ft_printf("min %i max %i\n", min, max);
	while (ft_sklen(*a) > 3)
	{
		if ((*a)->el != min && (*a)->el != max)
			ft_push(b, a, out, "pb\n");
		else
			ft_rotate(a, out, "ra\n");
	}
	ft_three_a(a, out, min);
}

int	ft_steps_a(t_stack *a, int el)
{
	int	ret;

	ret = 0;
	while (el > a->el)
	{
		ret++;
		a = a->prev;
	}
	return (ret);
}

void	ft_eval(t_stack **a, t_stack **b, int j)
{
	int		head;
	int		i;

	i = 0;
	head = (*b)->el;
	while (1)
	{
		(*b)->fl = ft_steps_a(*a, (*b)->el) + (i < j ? i : j);
		(*b)->rfl = (i++ < j--) ? 0 : 1;
		*b = (*b)->prev;
		if ((*b)->el == head)
			break ;
	}
}

void	ft_linksort(t_stack **a, t_stack **b, t_ps *ps)
{
	ft_toss(a, b, &ps->out);
	ft_eval(a, b, ps->size - 3);
	ft_print_stacks(*a, *b);
}
