/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 02:53:09 by pberge            #+#    #+#             */
/*   Updated: 2019/10/13 04:36:14 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

#include "libftprintf.h"

# define STACK_NUM 4

typedef struct	s_stack
{
	int				el;
	char			fl;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

/*
**	stack basics
*/

t_stack	*ft_sknew(void);
void	ft_skadd(t_stack **sk, t_stack *el);
void	ft_skfree(t_stack **sk);

/*
**	errors
*/

void	ft_error(void);
void	ft_alloc(int *alloc, int n, int ***sk);

void	ft_prepare(t_stack *a, t_stack *b, char *arg, int ***sk);
//void	push_swap(t_stack *a, t_stack *b);

/*
**	stack operations
*/

//void	ft_swap(int *el, int i);
//void	ft_push(t_stack *to, t_stack *from);
//void	ft_rotate(t_stack *sk);
//void	ft_reverse_rotate(t_stack *sk);
//
void	ft_print_stack(t_stack *sk);
//void	ft_print_stacks(t_stack *a, t_stack *b);

#endif
