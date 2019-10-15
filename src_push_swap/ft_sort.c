/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 11:21:12 by pberge            #+#    #+#             */
/*   Updated: 2019/10/15 12:58:20 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int		ft_issorted(t_stack *sk)
{
	t_stack	*head;

	if (sk == NULL)
		return (0);
	head = sk;
	sk = sk->prev;
	while (1)
	{
		if (sk->el < sk->next->el)
			return (0);
		if (sk->prev == head)
			break ;
		sk = sk->prev;
	}
//	ft_printf("is sorted\n");
	return (1);
}

void	ft_three(t_stack **a, t_stack **b)
{
	int	first;
	int	second;
	int	third;

//	ft_printf("three\n");
	first = (*b)->el;
	second = (*b)->prev->el;
	third = (*b)->prev->prev->el;
	if (first < second && first < third)
		;
	else if (second < first && second < third)
		ft_rotate(b);
	else if (third < first && third < second)
		ft_reverse_rotate(b);
	ft_btoa(a, b);
}

void	ft_two(t_stack **a, t_stack **b)
{
//	ft_printf("two\n");
	(void)a;
	if ((*b)->prev->el < (*b)->el)
		ft_swap(b);
	ft_btoa(a, b);
}

void	ft_sort(t_stack **a, t_stack **b, t_ps *ps)
{
	int	len;

	len = ft_sklen(*b);
//	ft_printf("len %i\n", len);
//	ft_print_stacks(*a, *b);
	if (ft_issorted(*b))
		ft_btoa(a, b);
	else
		ps->sort[len](a, b);
}

/*
**	returning sorted integers to stack A
*/

void	ft_btoa(t_stack **a, t_stack **b)
{
	while (*b != NULL)
	{
		(*b)->fl++;
		ft_push(a, b);
		ft_rotate(a);
	}
}
