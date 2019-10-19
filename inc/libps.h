/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 02:53:09 by pberge            #+#    #+#             */
/*   Updated: 2019/10/20 02:23:39 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include "libftprintf.h"
# include "libstack.h"

# define SORTF 5

typedef void	(*t_sort[SORTF])(t_stack **, t_stack **, t_out *o, char *op);

typedef struct	s_push_swap
{
	t_sort	sort;
	t_out	out;
	int		bsize;
}				t_ps;

/*
**	errors
*/

void			ft_error(void);
void			ft_exception(t_stack **a, t_ps **ps);

/*
**	algo additional functions
*/

void			ft_validate(char *arg);
t_ps			*ft_prepare(int n);
int				ft_fill_sk(t_stack **a, char **arg, int num);
void			ft_min_max(t_stack *sk, int *min, int *max);
void			ft_toss(t_stack **a, t_stack **b, t_out *out);
t_stack			*ft_eval(t_stack **a, t_stack **b, int j);
void			ft_end(t_stack **a, t_stack **b, t_ps **ps);
int				ft_issorted(t_stack **sk);

/*
**	sorting funcs
**	according to number of elements in stack
*/

void			ft_two(t_stack **a, t_out *out);
void			ft_linksort(t_stack **a, t_stack **b, t_ps *ps);
void			push_swap(t_stack **a, t_stack **b, t_ps *ps);

#endif
