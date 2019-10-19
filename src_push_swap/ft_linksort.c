/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linksort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 05:00:16 by pberge            #+#    #+#             */
/*   Updated: 2019/10/19 23:58:25 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

/*
**	rotates stack B to put needed element on top
*/

void	ft_tune_b(t_stack **b, t_stack *link, t_out *out)
{
	if (link->bfl)
	{
		while ((*b)->el != link->el)
			ft_reverse_rotate(b, out, "rrb\n");
	}
	else
	{
		while ((*b)->el != link->el)
			ft_rotate(b, out, "rb\n");
	}
}

/*
**	rotates stack A shortest way
**	to push next element from B
*/

void	ft_tune_a(t_stack **a, t_stack *link, t_out *out)
{
	if (link->afl)
	{
		while ((*a)->next->el > link->el)
			ft_reverse_rotate(a, out, "rra\n");
	}
	else
	{
		while ((*a)->el < link->el)
			ft_rotate(a, out, "ra\n");
	}
}

/*
**	rotates sorted stack
**	to put the smallest value on top
*/

void	ft_tune_end(t_stack **a, t_out *out)
{
	t_stack *tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = *a;
	while (tmp->el > tmp->next->el)
	{
		i++;
		tmp = tmp->prev;
	}
	tmp = *a;
	while (tmp->el > tmp->next->el)
	{
		j++;
		tmp = tmp->next;
	}
	tmp->bfl = (i <= j) ? 0 : 1;
	ft_tune_b(a, tmp, out);
}

/*
**	main logic
*/

void	ft_linksort(t_stack **a, t_stack **b, t_ps *ps)
{
	t_stack *link;

	ft_toss(a, b, &ps->out);
	ps->bsize = ps->bsize > 3 ? ps->bsize - 3 : 0;
	while (*b != NULL)
	{
		link = ft_eval(a, b, ps->bsize);
		ft_tune_b(b, link, &ps->out);
		ft_tune_a(a, link, &ps->out);
		ft_push(a, b, &ps->out, "pa\n");
		ps->bsize--;
	}
	ft_tune_end(a, &ps->out);
}
