/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pberge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 02:01:05 by pberge            #+#    #+#             */
/*   Updated: 2019/10/20 02:12:28 by pberge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTACK_H
# define LIBSTACK_H

typedef struct	s_stack
{
	int				el;
	char			afl;
	char			bfl;
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

/*
**	stack basics
*/

t_stack			*ft_sknew(void);
void			ft_skadd(t_stack **sk, t_stack *el);
void			ft_skfree(t_stack **sk);
int				ft_sklen(t_stack *sk);
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

#endif
