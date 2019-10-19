/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skadd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 02:42:04 by pberge            #+#    #+#             */
/*   Updated: 2019/10/20 02:12:47 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"
#include <stdlib.h>

void	ft_skadd(t_stack **top, t_stack *el)
{
	t_stack	*tmp;

	if (el == NULL)
		return ;
	if (*top == NULL)
	{
		*top = el;
		return ;
	}
	tmp = (*top)->next;
	(*top)->next = el;
	el->next = tmp;
	el->prev = *top;
	tmp->prev = el;
	(*top) = el;
}
