/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 03:59:45 by pberge            #+#    #+#             */
/*   Updated: 2019/10/13 08:53:09 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_print_stack(t_stack *sk)
{
	t_stack	*head;

	head = sk;
	while (1)
	{
		ft_printf("%i\n", sk->el);
		sk = sk->prev;
		if (sk == head)
			break ;
	}
	ft_printf("**********");
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
			ft_printf("%i\t", at->el);
			at = at->prev;
		}
		else
			ft_printf(" \t");
		if (bt != NULL)
		{
			ft_printf("%i\n", bt->el);
			bt = bt->prev;
		}
		else
			ft_printf(" \n");
		if (at == a)
			at = a = NULL;
		if (bt == b)
			bt = b = NULL;
		bt = (bt == b) ? NULL : bt;
		if (at == a && bt == b)
			break ;
	}
	ft_printf("---------\na\tb\n");
}
