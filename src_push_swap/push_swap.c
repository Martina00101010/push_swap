/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:40:09 by pberge            #+#    #+#             */
/*   Updated: 2019/10/13 01:51:02 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"
#include <stdlib.h>

void	ft_divide(t_stack *b, t_stack *a)
{
	
}

/*
**	
*/

void	push_swap(t_stack *a, t_stack *b)
{
	int		median;
	int		i;

	i = a->i + 1;
	ft_printf("*********************\n");
	while (--i > -1)
	{
		if (a->el[a->i] < median)
			ft_rotate(a);
		else
			ft_push(b, a);
	}
	ft_print_stacks(a, b);
}
