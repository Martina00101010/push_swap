/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linksort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 05:00:16 by pberge            #+#    #+#             */
/*   Updated: 2019/10/18 06:28:07 by pberge           ###   ########.fr       */
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
//	ft_printf("min %i max %i\n", min, max);
	while (ft_sklen(*a) > 3)
	{
		if ((*a)->el != min && (*a)->el != max)
			ft_push(b, a, out, "pb\n");
		else
			ft_rotate(a, out, "ra\n");
	}
	ft_three_a(a, out, min);
}

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
	tmp->afl = (i <= j) ? 0 : 1;
	ft_tune_b(a, tmp, out);
}

void	ft_two(t_stack **a, t_out *out)
{
	if ((*a)->el > (*a)->prev->el)
		ft_swap(a, out, "sa\n");
}

void	ft_three(t_stack **a, t_out *out)
{
	t_stack *sk;

	sk = *a;
	if (sk->next > sk && sk->next > sk->prev)
		;
	else if (sk > sk->next && sk > sk->prev)
		ft_rotate(a, out, "ra\n");
	else if (sk->prev > sk && sk->prev > sk->next)
		ft_reverse_rotate(a, out, "rra\n");
	ft_two(a, out);
}

void	ft_linksort(t_stack **a, t_stack **b, t_ps *ps)
{
	t_stack *link;

//	if (ps->asize == 2)
//		ft_two(a, &ps->out);
//	else if (ps->asize == 3)
//		ft_three(a, &ps->out);
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
//	ft_print_stack(*a);
}
