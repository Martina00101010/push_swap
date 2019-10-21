/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 02:53:09 by pberge            #+#    #+#             */
/*   Updated: 2019/10/21 08:26:05 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPS_H
# define LIBPS_H

# include "libftprintf.h"
# include "libstack.h"

# define BUFF_SIZE1 1
# define SORTF 5

# define INTMAX 2147483647

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
void			ft_valid_error(int fd, char **line);
void			ft_apply_error(t_stack **a, t_stack **b);

/*
**	algo additional functions
*/

t_ps			*ft_prepare(int n);
int				ft_get_ints(t_stack **a, char **arr);
int				ft_fill_sk(t_stack **a, char **arg, int num);
void			ft_min_max(t_stack *sk, int *min, int *max);
void			ft_toss(t_stack **a, t_stack **b, t_out *out);
t_stack			*ft_eval(t_stack **a, t_stack **b, int j);
void			ft_end(t_stack **a, t_stack **b, t_ps **ps);
int				ft_issorted(t_stack **sk);
void			ft_apply(t_out *out, t_stack **a, t_stack **b);
void			ft_answer(t_stack **a, t_stack **b);

/*
**	sorting funcs
**	according to number of elements in stack
*/

void			ft_two(t_stack **a, t_out *out);
void			ft_linksort(t_stack **a, t_stack **b, t_ps *ps);
void			push_swap(t_stack **a, t_stack **b, t_ps *ps);

#endif
