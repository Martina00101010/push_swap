/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 02:53:09 by pberge            #+#    #+#             */
/*   Updated: 2019/10/17 03:21:24 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include "libftprintf.h"

typedef struct	s_stack
{
	int				el;
	char			fl;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

# define BUFF_SIZE 1023

typedef struct	s_out
{
	char	buff[BUFF_SIZE + 1];
	int		flag;
	int		i;
}				t_out;

# define SORTF 5

typedef void	(*t_sort[SORTF])(t_stack **, t_stack **, t_out *o, char *op);

typedef struct	s_push_swap
{
	t_sort	sort;
	t_out	out;
}				t_ps;

/*
**	stack basics
*/

t_stack			*ft_sknew(void);
void			ft_skadd(t_stack **sk, t_stack *el);
void			ft_skfree(t_stack **sk);
int				ft_sklen(t_stack *sk);

/*
**	errors
*/

void			ft_error(void);
void			ft_exception(t_stack **a, t_ps **ps);

t_ps			*ft_prepare(t_stack **a, t_stack **b, char *arg);
void			push_swap(t_stack **a, t_stack **b, t_ps *ps);
void			ft_end(t_stack **a, t_stack **b, t_ps **ps);
void			ft_output(t_out *out, char *op);

/*
**	stack operations
*/

void			ft_swap(t_stack **sk, t_out *out, char *op);
void			ft_push(t_stack **to, t_stack **from, t_out *out, char *op);
void			ft_rotate(t_stack **sk, t_out *out, char *op);
void			ft_reverse_rotate(t_stack **sk, t_out *out, char *op);

/*
**	printing stacks
*/

void			ft_print_stack(t_stack *sk);
void			ft_print_stacks(t_stack *a, t_stack *b);

/*
**	sorting funcs
**	according to number of elements in stack
*/

int				ft_issorted(t_stack *sk);
void			ft_divide(t_stack **a, t_stack **b, t_out *out, char *op);
void			ft_two(t_stack **a, t_stack **b, t_out *out, char *op);
void			ft_three(t_stack **a, t_stack **b, t_out *out, char *op);
void			ft_sort(t_stack **a, t_stack **b, t_ps *ps);
void			ft_atob(t_stack **a, t_stack **b, t_out *out);
void			ft_staircase(t_stack **a, t_stack **b, t_out *out, char *op);
void			ft_btoa(t_stack **a, t_stack **b, t_out *out, char *op);

#endif
