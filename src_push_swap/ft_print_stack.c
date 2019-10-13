/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 03:59:45 by pberge            #+#    #+#             */
/*   Updated: 2019/10/13 03:53:43 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

void	ft_print_stack(t_stack *sk)
{
	t_stack	*head;

	head = sk;
	if (sk->prev == head)
	{
		ft_printf("%i\n", sk->el);
		return ;
	}
	while (1)
	{
		ft_printf("%i\n", sk->el);
		sk = sk->prev;
		if (sk == head)
			break ;
	}
}

//void	ft_print_stacks(t_stack *a, t_stack *b)
//{
//	int		i;
//
//	i = (a->i > b->i) ? a->i : b->i;
//	while (i > -1)
//	{
//		if (i <= a->i)
//			ft_printf("%i\t", a->el[i]);
//		else
//			ft_printf(" \t");
//		if (i <= b->i)
//			ft_printf("%i\n", b->el[i]);
//		else
//			ft_printf(" \n");
//		i--;
//	}
//	ft_printf("---------\na\tb\n\n");
//}
