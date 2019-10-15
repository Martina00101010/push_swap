/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 03:59:45 by pberge            #+#    #+#             */
/*   Updated: 2019/10/13 15:01:47 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_print_stack(t_stack *sk)
{
	t_stack	*head;

	head = sk;
	while (1)
	{
		ft_printf("%i\t%i\n", sk->el, sk->fl);
		sk = sk->prev;
		if (sk == head)
			break ;
	}
	ft_printf("**********\n");
}

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	t_stack	*at;
	t_stack *bt;

	at = a;
	bt = b;
	while (1)
	{
		if (at != NULL)
		{
			ft_printf("%3i %i\t", at->el, at->fl);
			at = at->prev;
		}
		else
			ft_printf(" \t");
		if (bt != NULL)
		{
			ft_printf("%3i %i\n", bt->el, bt->fl);
			bt = bt->prev;
		}
		else
			ft_printf(" \t\n");
		if (at == a)
			at = a = NULL;
		if (bt == b)
			bt = b = NULL;
		bt = (bt == b) ? NULL : bt;
		if (at == a && bt == b)
			break ;
	}
	ft_printf("---------------\n");
}
