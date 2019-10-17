/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 23:45:40 by pberge            #+#    #+#             */
/*   Updated: 2019/10/17 02:30:41 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libps.h"

/*
**	swap first two elements in stack
*/

void	ft_swap(t_stack **sk, t_out *out, char *op)
{
	t_stack	*top;
	t_stack	*tmp;

	top = *sk;
	tmp = top->prev;
	top->prev = tmp->prev;
	tmp->prev->next = top;
	tmp->next = top->next;
	tmp->prev = top;
	top->next = tmp;
	tmp->next->prev = tmp;
	*sk = tmp;
	ft_output(out, op);
}

/*
**	push element to another stack
*/

void	ft_push(t_stack **to, t_stack **from, t_out *out, char *op)
{
	t_stack	*mv;

	mv = *from;
	*from = (mv != mv->prev) ? mv->prev : NULL;
	if (*from != NULL)
	{
		(*from)->next = mv->next;
		(*from)->next->prev = *from;
	}
	mv->prev = (*to != NULL) ? *to : mv;
	mv->next = (*to != NULL) ? (*to)->next : mv;
	if (*to != NULL)
		(*to)->next = mv;
	else
		*to = mv;
	mv->next->prev = mv;
	*to = mv;
	ft_output(out, op);
}

/*
**	shift up all el in stack.
**	the first el becomes last
*/

void	ft_rotate(t_stack **sk, t_out *out, char *op)
{
	if (*sk == NULL)
		return ;
	*sk = (*sk)->prev;
	ft_output(out, op);
}

/*
**	shift down all elements in stack.
**	the last el becomes first
*/

void	ft_reverse_rotate(t_stack **sk, t_out *out, char *op)
{
	if (*sk == NULL)
		return ;
	*sk = (*sk)->next;
	ft_output(out, op);
}
