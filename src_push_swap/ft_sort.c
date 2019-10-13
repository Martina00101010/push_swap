/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 11:21:12 by pberge            #+#    #+#             */
/*   Updated: 2019/10/13 12:09:17 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

int		ft_issorted(t_stack *sk)
{
	t_stack	*head;
	int		iss;

	iss = 0;
	head = sk;
	sk = sk->prev;
	while (1)
	{
		if (sk->el > sk->next->el)
			return (1);
		if (sk->prev == head)
			break ;
		sk = sk->prev;
	}
	return (0);
}

void	ft_three(t_stack **a, t_stack **b)
{
	int	first;
	int	second;
	int	third;

	first = (*b)->el;
	second = (*b)->prev->el;
	third = (*b)->prev->prev->el;
//	ft_issorted
//	if (first > second && second > third && third < first)
//		return ;
	if (first > second && second < third && third < first)
	{
		ft_push(a, b);
		ft_swap(b);
	}
	else if (first > second && second < third && third > first)
		ft_reverse_rotate(b);
	else if (first < second && second > third && third < first)
		ft_swap(b);
	else if (first < second && second < third && third > first)
	{
		ft_swap(b);
		ft_reverse_rotate(b);
	}
	else
		ft_rotate(b);
}
